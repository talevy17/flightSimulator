
#include "BinaryExpression.h"

/**
* get the left expression.
* @return const Expression* left
*/
Expression *BinaryExpression::getLeft() const { return this->left; }

/**
* get the right expression.
* @return const Expression* right
*/
Expression *BinaryExpression::getRight() const { return this->right; }

/**
* set the left expression.
* @param ex Expression*
*/
void BinaryExpression::setLeft(Expression *ex) { this->left = ex; }

/**
* set the right expression.
* @param ex Expression*
*/
void BinaryExpression::setRight(Expression *ex) { this->right = ex; }

/**
* virtual destructor.
*/
BinaryExpression::~BinaryExpression() {
    delete (this->left);
    delete (this->right);
}