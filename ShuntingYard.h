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

class ShuntingYard {
public:
    double evaluate(string expression);
};


#endif //FLIGHTSIMULATOR_SHUNTINGYARD_H
