
#ifndef FLIGHTSIMULATOR_COMMANDEXPRESSION_H
#define FLIGHTSIMULATOR_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Commands/Command.h"

/**
 * Adapter class ! adapts commands to expressions.
 */
class CommandExpression : public Expression {
    Command *cmd;
    vector<string>::iterator &args;

public:
    /**
    * CTOR, initializes a reference arguments vector's iterator and a Command.
    * @param command Command*
    * @param iter vector<string>::iterator
    */
    CommandExpression(Command *command, vector<string>::iterator &iter);

    /**
    * executes the command, returns 0 if successful and 1 if a problem occurred ( C style (: )
    * @return double 0 or 1
    */
    virtual double calculate() const;
};


#endif //FLIGHTSIMULATOR_COMMANDEXPRESSION_H
