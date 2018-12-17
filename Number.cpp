//
// Created by tal on 12/13/18.
//

#include "Number.h"

Number::Number(string num) {
    this->value = stod(num);
}

double Number::calculate() {return this->value;}

Number::~Number() {}