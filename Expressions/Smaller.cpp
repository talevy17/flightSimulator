//
// Created by tal on 12/19/18.
//

#include "Smaller.h"

/**
* CTOR.
* @param leftEx Expression*
* @param rightEx Expression*
*/
Smaller::Smaller(Expression *leftEx, Expression *rightEx) {
    this->setLeft(leftEx);
    this->setRight(rightEx);
}

/**
* compare the calculated arguments.
* @return double 1 or 0 (true or false)
*/
double Smaller::calculate() const {
    return this->getLeft()->calculate() < this->getRight()->calculate();
}