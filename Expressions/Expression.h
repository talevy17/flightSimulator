
#ifndef FLIGHTSIMULATOR_EXPRESSION_H
#define FLIGHTSIMULATOR_EXPRESSION_H

#include <iostream>

using namespace std;

/**
 * Expression interface, used to implement the Expression design pattern.
 */
class Expression {
public:
    /**
     * evaluates an Expression.
     * @return double value.
     */
    virtual double calculate() const = 0;

    /**
     * virtual destructor
     */
    virtual ~Expression() {}
};

#endif //FLIGHTSIMULATOR_EXPRESSION_H
