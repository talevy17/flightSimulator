//
// Created by tal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_EQUAL_H
#define FLIGHTSIMULATOR_EQUAL_H

#include "BinaryExpression.h"

/**
 * implements the not equal "!=" operator, as part of the expression design pattern.
 */
class Equal: public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    Equal(Expression *leftEx, Expression *rightEx);

    /**
     * check if the expressions are equal.
     * @return double value.
     */
    virtual double calculate() const;

    /**
     * virtual DTOR.
     */
    virtual ~Equal() {}
};

#endif //FLIGHTSIMULATOR_EQUAL_H
