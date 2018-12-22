//
// Created by tal on 12/21/18.
//

#include "WhileCommand.h"

/**
* CTOR, initializes the data a command maps in super.
* @param variables
* @param commandMap
*/
WhileCommand::WhileCommand(FlightDataVariables *variables, map<string, Command *> *commandMap) {
    this->setSymbolTable(variables);
    this->setCommandMap(commandMap);
}

/**
* while the condition is true, execute the commands inside the block.
* @param it iterator.
*/
void WhileCommand::execute(vector<string>::iterator &it) {
    //keep locally the commands and arguments in the block.
    vector<Command *> cmds;
    vector<vector<string>::iterator> args;
    Expression *condition;
    auto conditionIter = ++it;
    //try parsing the condition.
    try {
        this->parseCondition(it, condition);
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
    } else {
        return;
    }
    while (condition->calculate()) {
        //try to execute all of the commands in the block.
        for (unsigned long int i = 0; i < cmds.size(); i++) {
            auto temp = args.at(i);
            try {
                cmds.at(i)->execute(temp);
            } catch (const char *e) {
                throw e;
            }
        }
        //re-parse the condition to accumulate the changes.
        delete (condition);
        auto tempCondition = conditionIter;
        this->parseCondition(tempCondition, condition);
    }
    delete (condition);
}