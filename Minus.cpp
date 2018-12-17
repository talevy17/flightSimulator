
#include "Minus.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
Minus::Minus(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* subtract the expressions.
* @return double value
*/
double Minus::calculate() {
    return this->getLeft()->calculate() - this->getRight()->calculate();
}