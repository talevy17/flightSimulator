//
// Created by tal on 12/15/18.
//

#ifndef FLIGHTSIMULATOR_SHUNTINGYARD_H
#define FLIGHTSIMULATOR_SHUNTINGYARD_H

#include "Expressions/Div.h"
#include "Expressions/Minus.h"
#include "Expressions/Mult.h"
#include "Expressions/Plus.h"
#include "Expressions/Number.h"
#include "Expressions/Smaller.h"
#include "Expressions/Bigger.h"
#include "Expressions/SmallerEqual.h"
#include "Expressions/BiggerEqual.h"
#include "Expressions/Var.h"
#include "Expressions/NotEqual.h"
#include "Expressions/Equal.h"
#include "string.h"
#include <vector>
#include <map>

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

    /**
     * a nicer way to use Shunting Yard parser.
    * @param it vector<string>::iterator
    * @return Expression* result.
    */
    Expression* operator()(vector<string>::iterator& it);
};


#endif //FLIGHTSIMULATOR_SHUNTINGYARD_H
