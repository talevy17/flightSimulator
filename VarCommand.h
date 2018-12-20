//
// Created by tal on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_VARCOMMAND_H
#define FLIGHTSIMULATOR_VARCOMMAND_H

#include "Command.h"
#include "FlightDataVariables.h"

class VarCommand : public Command {
    FlightDataVariables* data;
public:
    VarCommand(FlightDataVariables* maps);
    void execute(vector<string>::iterator& it);
};


#endif //FLIGHTSIMULATOR_VARCOMMAND_H
