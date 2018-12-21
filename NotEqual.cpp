
#include "NotEqual.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
NotEqual::NotEqual(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* compare the calculated arguments.
* @return double 1 or 0 (true or false)
*/
double NotEqual::calculate() const {
    return this->getLeft()->calculate() != this->getRight()->calculate();
}