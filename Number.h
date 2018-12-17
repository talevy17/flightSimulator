//
// Created by tal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_NUMBER_H
#define FLIGHTSIMULATOR_NUMBER_H

#include "Expression.h"
#include <string.h>


class Number : public Expression {
    double value;
public:
    Number(string num);

    virtual double calculate();

    ~Number();
};


#endif //FLIGHTSIMULATOR_NUMBER_H
