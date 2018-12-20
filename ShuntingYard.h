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
#include "Smaller.h"
#include "Bigger.h"
#include "SmallerEqual.h"
#include "BiggerEqual.h"
#include "Var.h"
#include "string.h"
#include <map>
#include <queue>

using namespace std;

/**
 * an implementation of Dijkstra's Shunting-Yard algorithm.
 */
class ShuntingYard {
    map<string, Var*> vars;
public:
    /**
     * CTOR, use a reference from the variables map.
     * @param variables
     */
    ShuntingYard(const map<string, Var*>& variables);
    /**
    * evaluate the input string expression, throws exception if the expression is invalid.
    * @param expression the string expression.
    * @return double result.
    */
    Expression* parseExpression(vector<string>::iterator& it);
};


#endif //FLIGHTSIMULATOR_SHUNTINGYARD_H
