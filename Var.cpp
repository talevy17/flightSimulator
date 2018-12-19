//
// Created by tal on 12/19/18.
//

#include "Var.h"

Var::Var(string varName, double val) {
    this->value = val;
    this->name = varName;
}

double Var::calculate() { return this->value;}