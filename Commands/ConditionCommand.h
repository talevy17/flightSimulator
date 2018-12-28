//
// Created by tal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_CONDITIONCOMMAND_H
#define FLIGHTSIMULATOR_CONDITIONCOMMAND_H

#include "Command.h"
#include "Expressions/Expression.h"
#include <map>
#include "Data/FlightDataVariables.h"

/**
 * super class for the conditional type commands (e.g while and if)
 */
class ConditionCommand : public Command {
    //necessary maps of data.
    FlightDataVariables *symbolTable;
    map<string, Command *> *commandMap;
protected:
    /**
     * variable map setter.
     * @param variables FlightDataVariables*
     */
    void setSymbolTable(FlightDataVariables *variables);

    /**
     * command map setter.
     * @param commands map<string, Command*> *
     */
    void setCommandMap(map<string, Command *> *commands);

    /**
     * parse the condition of the block.
     * @param it iterator
     * @param condition the Expression.
     */
    void parseCondition(vector<string>::iterator &it, Expression *&condition);

    /**
     * parse the commands in the block for later execution.
     * @param it iterator
     * @param cmds a vector to push the commands into.
     * @param args a vector to push the arguments of the commands respectively.
     */
    void parseCommands(vector<string>::iterator &it, vector<Command *> &cmds, vector<vector<string>::iterator> &args);

    virtual ~ConditionCommand() {}
};


#endif //FLIGHTSIMULATOR_CONDITIONCOMMAND_H
