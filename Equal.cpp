//
// Created by tal on 12/21/18.
//

#include "Equal.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
Equal::Equal(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* compare the calculated arguments.
* @return double 1 or 0 (true or false)
*/
double Equal::calculate() const {
    return this->getLeft()->calculate() == this->getRight()->calculate();
}