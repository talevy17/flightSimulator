//
// Created by tal on 12/19/18.
//

#include "Var.h"

/**
* CTOR.
* @param varName string name
* @param val double value
*/
Var::Var(string varName, double val) {
    this->value = val;
    this->name = varName;
}

/**
* CTOR.
* @param varName string name
*/
Var::Var(string varName) {
    this->name = varName;
}

/**
* assign a value to the Var, shall be used by the assign command at run-time.
* @param val
*/
void Var::assignValue(double val) {
    this->value = val;
}

/**
* assign a value of an Expression to the var, shall be used by the assign command.
* @param ex
*/
void Var::assignValue(Expression *ex) {
    this->value = ex->calculate();
}
/**
* calculates the value of the node.
* @return double value.
*/
double Var::calculate() { return this->value;}