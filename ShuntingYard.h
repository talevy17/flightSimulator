//
// Created by tal on 12/15/18.
//

#ifndef FLIGHTSIMULATOR_SHUNTINGYARD_H
#define FLIGHTSIMULATOR_SHUNTINGYARD_H

#include "Div.h"
#include "Minus.h"
#include "Mult.h"
#include "Plus.h"
#include "Number.h"
#include "string.h"
#include <list>

using namespace std;

/**
 * an implementation of Dijkstra's Shunting-Yard algorithm.
 */
class ShuntingYard {
public:
    /**
    * evaluate the input string expression, throws exception if the expression is invalid.
    * @param expression the string expression.
    * @return double result.
    */
    double evaluate(string expression);
};


#endif //FLIGHTSIMULATOR_SHUNTINGYARD_H
