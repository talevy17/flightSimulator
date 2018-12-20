#ifndef FLIGHTSTIMULATOR_OPENDATASERVER_H
#define FLIGHTSTIMULATOR_OPENDATASERVER_H


#include "Command.h"

class openDataServer : public Command{
    virtual void execute(queue<string> &commandLine);
};


#endif //FLIGHTSTIMULATOR_OPENDATASERVER_H
