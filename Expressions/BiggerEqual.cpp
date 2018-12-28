//
// Created by tal on 12/19/18.
//

#include "BiggerEqual.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
BiggerEqual::BiggerEqual(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* compare the calculated arguments.
* @return double 1 or 0 (true or false)
*/
double BiggerEqual::calculate() const {
    return this->getLeft()->calculate() >= this->getRight()->calculate();
}