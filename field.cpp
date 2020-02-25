//
// Created by kot on 25.02.2020.
//
#include "field.h"

Field::Field(unsigned width, unsigned height, unsigned itemLimit)
    :width(width), height(height), itemLimit(itemLimit), itemCounter(0) {

    items = new FieldItem **[width];
    for (unsigned i = 0; i < width; i++) {
        items[i] = new FieldItem *[height];
        for (unsigned j = 0; j < height; j++) {
            items[i][j] = nullptr;
        }
    }
}

Field::Field(const Field &field)
    :width(field.width), height(field.height), itemLimit(field.itemLimit),
itemCounter(field.itemCounter){

    items = new FieldItem **[width];
    for (unsigned i = 0; i < width; i++) {
        items[i] = new FieldItem *[height];
        for (unsigned j = 0; j < height; j++) {
            items[i][j] = nullptr;
        }
    }
    for (unsigned i = 0; i < width; i++){
        for (unsigned j = 0; j < height; j++) {
            if (field.items[i][j] != nullptr){
                items[i][j] = field.items[i][j]->itemCopy();
                // page 6
            }
        }
    }

}

Field::Field(Field &&field)
    :width(field.width), height(field.height), itemLimit(field.itemLimit),
itemCounter(field.itemCounter){
    field.items = nullptr;
    field.width = 0;
    field.height = 0;
}

Field::~Field() {
    for (unsigned i = 0; i < width; i++){
        for (unsigned j = 0; j < height; j++)
            deleteItem(i,j);
        delete[] items[i];
    }
    if (items)
        delete[] items;
}

bool Field::addItem(unsigned x, unsigned y, FieldItem *item) {
    if (itemCounter == itemLimit)
        throw std::length_error("limit of field items is reached");
    if (x >= width || y >= height)
        throw std::out_of_range("coords are out of field");
    if (items[x][y] != nullptr)
        throw std::invalid_argument("field cell is busy");
    items[x][y] = item;
    // page 6
    itemCounter++;
    return true;

}

bool Field::deleteItem(unsigned x, unsigned y) {
    if (x >= width || y >= height)
        throw std::out_of_range("coords are out of field");
    if (items[x][y] == nullptr)
        return false;
    delete items[x][y];
    items[x][y] = nullptr;
    itemCounter--;
    return true;
}

bool Field::deleteItem(FieldItem *item) {
    for (unsigned i = 0; i < width; i++){
        for (unsigned j = 0; j < height ; j++) {
            if (items[i][j] = item){
                delete items[i][j];
                items[i][j] = nullptr;
                itemCounter--;
                return true;
            }
        }
    }
    throw  std::invalid_argument("there is no items like that");
}

FieldItem *Field::getItem(unsigned x, unsigned y){
    if (x >= width || y >= height)
        throw std::out_of_range("coords are out of field");
    return items[x][y];
}

Field &Field::operator=(const Field &field) {
    return <#initializer#>;
}

Field &Field::operator=(Field &&field) {
    return <#initializer#>;
}
