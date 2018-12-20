
#ifndef FLIGHTSIMULATOR_DIV_H
#define FLIGHTSIMULATOR_DIV_H

#include "BinaryExpression.h"

/**
 * Dividing two expressions, as part of the design pattern.
 */
class Div : public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    Div(Expression *leftEx, Expression *rightEx);

    /**
     * divide the expressions.
     * @return double value.
     */
    virtual double calculate() const;

    /**
     * virtual DTOR.
     */
    virtual ~Div() {}
};


#endif //FLIGHTSIMULATOR_DIV_H
