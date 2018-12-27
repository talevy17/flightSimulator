#ifndef FLIGHTSIMULATOR_SLEEP_H
#define FLIGHTSIMULATOR_SLEEP_H

#include "Command.h"
#include "FlightDataVariables.h"
#include <unistd.h>

class SleepCommand : public Command {
    FlightDataVariables *data;
public:
    SleepCommand(FlightDataVariables *dataVariables);
    void execute(vector<string>::iterator &it);
};


#endif //FLIGHTSIMULATOR_SLEEP_H
