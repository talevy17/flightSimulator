//
// Created by tal on 12/19/18.
//

#include "SmallerEqual.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
SmallerEqual::SmallerEqual(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* compare the calculated arguments.
* @return double 1 or 0 (true or false)
*/
double SmallerEqual::calculate() const {
    return this->getLeft()->calculate() <= this->getRight()->calculate();
}