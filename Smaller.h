//
// Created by tal on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_SMALLER_H
#define FLIGHTSIMULATOR_SMALLER_H

#include "BinaryExpression.h"

/**
 * implements the smaller "<" operator, as part of the expression design pattern.
 */
class Smaller: public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    Smaller(Expression *leftEx, Expression *rightEx);

    /**
     * divide the expressions.
     * @return double value.
     */
    virtual double calculate();

    /**
     * virtual DTOR.
     */
    virtual ~Smaller() {}
};



#endif //FLIGHTSIMULATOR_SMALLER_H
