//
// Created by tal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_NOTEQUAL_H
#define FLIGHTSIMULATOR_NOTEQUAL_H

#include "BinaryExpression.h"

/**
 * implements the not equal "!=" operator, as part of the expression design pattern.
 */
class NotEqual: public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    NotEqual(Expression *leftEx, Expression *rightEx);

    /**
     * check if the arguments are not equal.
     * @return double value.
     */
    virtual double calculate() const;

    /**
     * virtual DTOR.
     */
    virtual ~NotEqual() {}
};


#endif //FLIGHTSIMULATOR_NOTEQUAL_H
