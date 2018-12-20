//
// Created by tal on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_SMALLEREQUAL_H
#define FLIGHTSIMULATOR_SMALLEREQUAL_H

#include "BinaryExpression.h"

/**
 * implements the smaller "<=" operator, as part of the expression design pattern.
 */
class SmallerEqual: public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    SmallerEqual(Expression *leftEx, Expression *rightEx);

    /**
     * divide the expressions.
     * @return double value.
     */
    virtual double calculate();

    /**
     * virtual DTOR.
     */
    virtual ~SmallerEqual() {}
};

#endif //FLIGHTSIMULATOR_SMALLEREQUAL_H
