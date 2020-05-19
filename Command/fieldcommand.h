//
// Created by kot on 19.05.2020.
//

#ifndef FIELDCOMMAND_H
#define FIELDCOMMAND_H
#include "command.h"
#include "Field/field.h"


class FieldCommand: public Command {
private:
	map<string, int> landInfo();
	map<string, int> unitInfo();
};


#endif //FIELDCOMMAND_H
