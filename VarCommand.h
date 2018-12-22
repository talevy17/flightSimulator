//
// Created by tal on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_VARCOMMAND_H
#define FLIGHTSIMULATOR_VARCOMMAND_H

#include "Command.h"
#include "FlightDataVariables.h"

class VarCommand : public Command {
    FlightDataVariables *data;
public:
    /**
     * CTOR, receives access to the data maps.
     * @param maps
     */
    VarCommand(FlightDataVariables *maps);

    /**
     * execute the Var Command (implements the command design pattern).
     * @param it
     */
    void execute(vector<string>::iterator &it);
};


#endif //FLIGHTSIMULATOR_VARCOMMAND_H
