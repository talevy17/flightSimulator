
#include "Div.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
Div::Div(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* divide the expressions.
* @return double value.
*/
double Div::calculate() {
    double right = this->getRight()->calculate();
    if (right == 0.0) {
        throw "cannot divide by zero!";
    }
    return this->getLeft()->calculate() / right;
}