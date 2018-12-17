
#ifndef FLIGHTSIMULATOR_BINARYEXPRESSION_H
#define FLIGHTSIMULATOR_BINARYEXPRESSION_H

#include "Expression.h"

/**
 * Binary expression.
 */
class BinaryExpression : public Expression {
    //left and right expressions.
    Expression *left;
    Expression *right;
protected:
    //getters and setters - member access to inheriting classes.
    /**
     * set the left expression.
     * @param ex Expression*
     */
    void setLeft(Expression *ex);

    /**
     * set the right expression.
     * @param ex Expression*
     */
    void setRight(Expression *ex);

    /**
     * get the left expression.
     * @return const Expression* left
     */
    Expression *getLeft() const;

    /**
     * get the right expression.
     * @return const Expression* right
     */
    Expression *getRight() const;

public:
    /**
     * virtual destructor.
     */
    virtual ~BinaryExpression();
};


#endif //FLIGHTSIMULATOR_BINARYEXPRESSION_H
