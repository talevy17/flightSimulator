//
// Created by tal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_WHILECOMMAND_H
#define FLIGHTSIMULATOR_WHILECOMMAND_H

#include "ConditionCommand.h"

/**
 * implements the condition block while loop, as part of the design pattern.
 */
class WhileCommand : public ConditionCommand {
public:
    /**
     * CTOR, initializes the data a command maps in super.
     * @param variables
     * @param commandMap
     */
    WhileCommand(FlightDataVariables *variables, map<string, Command *> *commandMap);

    /**
     * while the condition is true, execute the commands inside the block.
     * @param it iterator.
     */
    void execute(vector<string>::iterator &it);
};


#endif //FLIGHTSIMULATOR_WHILECOMMAND_H
