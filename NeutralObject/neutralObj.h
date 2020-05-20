//
// Created by kot on 10.05.2020.
//

#ifndef NEUTRALOBJ_H
#define NEUTRALOBJ_H

#include "unit.h"
class NeutralObj {
public:
    virtual ~NeutralObj() = default;
    virtual void operator += (Unit&) = 0;
    virtual std::string characteristics() const = 0;
	virtual Neutraltype getEnumType() = 0;

};

#endif //NEUTRALOBJ_H
