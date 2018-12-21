

#include "IfCommand.h"

/**
* CTOR, initializes the data a command maps in super.
* @param variables
* @param commandMap
*/
IfCommand::IfCommand(FlightDataVariables *variables, map<string, Command *> *commandMap) {
    this->setSymbolTable(variables);
    this->setCommandMap(commandMap);
}

/**
* executes the condition and following commands in the block (if the condition is true)
* @param it iterator.
*/
void IfCommand::execute(vector<string>::iterator &it) {
    //keep locally the commands and arguments in the block.
    vector<Command*> cmds;
    vector<vector<string>::iterator> args;
    Expression* condition;
    //try parsing the condition.
    try {
        this->parseCondition(++it, condition);
    } catch (const char *e) {
        throw e;
    }
    //check the condition.
    if (condition->calculate()) {
        //try parsing the commands.
        try {
            this->parseCommands(it, cmds, args);
        } catch (const char *e) {
            throw e;
        }
        //try to execute all of the commands in the block.
        for (unsigned long int i = 0; i < cmds.size(); i++) {
            try {
                cmds.at(i)->execute(args.at(i));
            } catch (const char *e) {
                throw e;
            }
        }
    }
    delete(condition);
}