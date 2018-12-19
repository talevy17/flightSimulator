//
// Created by tal on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H

#include <string>
#include "Expression.h"

class Var : public Expression {
    string name;
    double value;
public:
    Var(string varName, double val);

    double calculate();

    ~Var(){}
};


#endif //FLIGHTSIMULATOR_VAR_H
