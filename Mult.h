
#ifndef FLIGHTSIMULATOR_MULT_H
#define FLIGHTSIMULATOR_MULT_H

#include "BinaryExpression.h"

/**
 * Multiplying two expressions, as part of the design pattern.
 */
class Mult : public BinaryExpression {
public:
    /**
     * CTOR.
     * @param leftEx Expression*
     * @param rightEx Expression*
     */
    Mult(Expression *leftEx, Expression *rightEx);

    /**
     * Multiply the expressions.
     * @return
     */
    virtual double calculate();

    /**
     * virtual DTOR.
     */
    virtual ~Mult() {}
};


#endif //FLIGHTSIMULATOR_MULT_H
