//
// Created by tal on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H

#include <string>
#include "Expression.h"

/**
 * A single variable, a node in the expression design pattern.
 */
class Var : public Expression {
    string name;
    double value;
public:
    /**
     * CTOR.
     * @param varName string name
     * @param val double value
     */
    Var(string& varName, double val);

    /**
     * calculates the value of the node.
     * @return double value.
     */
    double calculate();

    /**
     * DTOR.
     */
    ~Var(){}
};


#endif //FLIGHTSIMULATOR_VAR_H
