

#include "Bigger.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
Bigger::Bigger(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* compare the calculated arguments.
* @return double 1 or 0 (true or false)
*/
double Bigger::calculate() const {
    return this->getLeft()->calculate() > this->getRight()->calculate();
}