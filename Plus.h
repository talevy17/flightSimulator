//
// Created by tal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_PLUS_H
#define FLIGHTSIMULATOR_PLUS_H

#include "BinaryExpression.h"

class Plus: public BinaryExpression {
public:
    Plus(Expression* leftEx, Expression* rightEx);
    virtual double calculate();
    virtual ~Plus(){}
};


#endif //FLIGHTSIMULATOR_PLUS_H
