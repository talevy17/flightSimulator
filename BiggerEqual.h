//
// Created by tal on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_BIGGEREQUAL_H
#define FLIGHTSIMULATOR_BIGGEREQUAL_H

#include "BinaryExpression.h"

/**
 * implements the bigger-equal ">=" operator, as part of the expression design pattern.
 */
class BiggerEqual: public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    BiggerEqual(Expression *leftEx, Expression *rightEx);

    /**
     * check if the left expression is bigger or equal than the right.
     * @return double value.
     */
    virtual double calculate() const;

    /**
     * virtual DTOR.
     */
    virtual ~BiggerEqual() {}
};

#endif //FLIGHTSIMULATOR_BIGGEREQUAL_H
