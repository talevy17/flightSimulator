//
// Created by tal on 12/19/18.
//

#include "Var.h"

/**
* CTOR.
* @param varName string name
* @param val double value
*/
Var::Var(string& varName, double val) {
    this->value = val;
    this->name = varName;
}

/**
* calculates the value of the node.
* @return double value.
*/
double Var::calculate() { return this->value;}