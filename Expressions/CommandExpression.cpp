
#include "CommandExpression.h"

/**
 * CTOR, initializes a reference arguments vector's iterator and a Command.
 * @param command Command*
 * @param iter vector<string>::iterator
 */
CommandExpression::CommandExpression(Command *command, vector<string>::iterator &iter) : args(iter) {
    this->cmd = command;
}

/**
 * executes the command, returns 0 if successful and 1 if a problem occurred ( C style (: )
 * @return double 0 or 1
 */
double CommandExpression::calculate() const {
    try {
        this->cmd->execute(this->args);
        return 0;
    } catch (const char* e) {
        cout << e << endl;
        return 1;
    }
}