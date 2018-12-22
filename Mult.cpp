
#include "Mult.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
Mult::Mult(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* Multiply the expressions.
* @return
*/
double Mult::calculate() const {
    return this->getLeft()->calculate() * this->getRight()->calculate();
}