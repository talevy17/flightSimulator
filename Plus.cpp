//
// Created by tal on 12/13/18.
//

#include "Plus.h"

Plus::Plus(Expression *leftEx, Expression *rightEx) {
    this->setRight(rightEx);
    this->setLeft(leftEx);
}

double Plus::calculate() {
    return this->getLeft()->calculate() + this->getRight()->calculate();
}