
#include "Plus.h"

/**
 * CTOR, sets super's left and right Expressions.
 * @param leftEx Expression*
 * @param rightEx Expression*
 */
Plus::Plus(Expression *leftEx, Expression *rightEx) {
    this->setRight(rightEx);
    this->setLeft(leftEx);
}

/**
 * adds the two expressions.
 * @return double value.
 */
double Plus::calculate() const {
    return this->getLeft()->calculate() + this->getRight()->calculate();
}