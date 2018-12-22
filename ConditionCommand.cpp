
#include "ConditionCommand.h"
#include "ShuntingYard.h"

/**
* parse the condition of the block.
* @param it iterator
* @param condition the Expression.
*/
void ConditionCommand::parseCondition(vector<string>::iterator &it, Expression *&condition) {
    ShuntingYard s(this->symbolTable->getSymbolTable());
    try {
        condition = s(it);
    } catch (const char *e) {
        throw e;
    }
    if (*it != ";") {
        throw "Invalid condition";
    }
    ++it;
}

/**
* variable map setter.
* @param variables FlightDataVariables*
*/
void ConditionCommand::setSymbolTable(FlightDataVariables *variables) { this->symbolTable = variables; }

/**
* command map setter.
* @param commands map<string, Command*> *
*/
void ConditionCommand::setCommandMap(map<string, Command *> *commands) { this->commandMap = commands; }

/**
* parse the commands in the block for later execution.
* @param it iterator
* @param cmds a vector to push the commands into.
* @param args a vector to push the arguments of the commands respectively.
*/
void ConditionCommand::parseCommands(vector<string>::iterator &it,
                                     vector<Command *> &cmds, vector<vector<string>::iterator> &args) {
    if (*it != "{") {
        throw "Invalid condition command block!";
    }
    while (*(++it) != "}") {
        try {
            cmds.push_back(this->commandMap->at(*it));
        } catch (exception &e) {
            cmds.push_back(this->commandMap->at("Var"));
        }
        auto cpyIter = it;
        args.push_back(cpyIter);
        if (*it == "if" || *it == "while") {
            while (*it != "}") {
                it++;
            }
        } else {
            while (*it != ";") {
                it++;
            }
        }
    }
}