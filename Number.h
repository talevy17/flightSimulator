//
// Created by tal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_NUMBER_H
#define FLIGHTSIMULATOR_NUMBER_H

#include "Expression.h"
#include <string.h>

/**
 * represents the "leaf" of the recursion tree, implementing the expresion design pattern.
 */
class Number : public Expression {
    //class member, a number.
    double value;
public:
    /**
    * CTOR, converts string input to double.
    * @param num string
    */
    Number(string num);

    /**
     * calculates the expression.
     * @return double value.
     */
    virtual double calculate();

    /**
     * DTOR.
     */
    ~Number(){}
};


#endif //FLIGHTSIMULATOR_NUMBER_H
