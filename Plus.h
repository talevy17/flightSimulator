//
// Created by tal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_PLUS_H
#define FLIGHTSIMULATOR_PLUS_H

#include "BinaryExpression.h"

/**
 * binary expression, adds two expressions, as part of the design pattern.
 */
class Plus : public BinaryExpression {
public:
    /**
    * CTOR, sets super's left and right Expressions.
    * @param leftEx Expression*
    * @param rightEx Expression*
    */
    Plus(Expression *leftEx, Expression *rightEx);

    /**
    * adds the two expressions.
    * @return double value.
    */
    virtual double calculate();

    /**
     * DTOR.
     */
    virtual ~Plus() {}
};


#endif //FLIGHTSIMULATOR_PLUS_H
