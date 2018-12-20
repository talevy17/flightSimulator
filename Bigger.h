//
// Created by tal on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_BIGGER_H
#define FLIGHTSIMULATOR_BIGGER_H

#include "BinaryExpression.h"

/**
 * implements the bigger ">" operator, as part of the expression design pattern.
 */
class Bigger: public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    Bigger(Expression *leftEx, Expression *rightEx);

    /**
     * divide the expressions.
     * @return double value.
     */
    virtual double calculate();

    /**
     * virtual DTOR.
     */
    virtual ~Bigger() {}
};


#endif //FLIGHTSIMULATOR_BIGGER_H
