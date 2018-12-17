//
// Created by tal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_MINUS_H
#define FLIGHTSIMULATOR_MINUS_H

#include "BinaryExpression.h"

/**
 * subtracting two expressions.
 */
class Minus : public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    Minus(Expression *leftEx, Expression *rightEx);

    /**
     * subtract the expressions.
     * @return double value
     */
    virtual double calculate();

    /**
     * virtual DTOR.
     */
    virtual ~Minus() {}
};


#endif //FLIGHTSIMULATOR_MINUS_H
