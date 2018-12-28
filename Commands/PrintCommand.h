
#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H

#include "Command.h"
#include "Expressions/Var.h"
#include "Data/FlightDataVariables.h"
#include <map>

/**
 * prints the argument to the console.
 */
class PrintCommand : public Command {
    FlightDataVariables* symbolTable;

public:
    /**
     * CTOR.
     * @param vars
     */
    PrintCommand(FlightDataVariables *vars);

    /**
     * executes the command, prints the argument to the console.
     * @param it
     */
    void execute(vector<string>::iterator &it);
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
