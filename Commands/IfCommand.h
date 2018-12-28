//
// Created by tal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_IFCOMMAND_H
#define FLIGHTSIMULATOR_IFCOMMAND_H

#include "ConditionCommand.h"

/**
 * implements the condition block if, as part of the design pattern.
 */
class IfCommand : public ConditionCommand {
public:
    /**
     * CTOR, initializes the data a command maps in super.
     * @param variables
     * @param commandMap
     */
    IfCommand(FlightDataVariables *variables, map<string, Command *> *commandMap);

    /**
     * executes the condition and following commands in the block (if the condition is true)
     * @param it iterator.
     */
    void execute(vector<string>::iterator &it);
};


#endif //FLIGHTSIMULATOR_IFCOMMAND_H
