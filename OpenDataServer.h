#ifndef FLIGHTSTIMULATOR_OPENDATASERVER_H
#define FLIGHTSTIMULATOR_OPENDATASERVER_H

#include "Command.h"
#include "Server.h"
#include <thread>
#include <iostream>
#include <string>

class OpenDataServer : public Command{
    FlightDataVariables& data;
    Server& server;
public:
    OpenDataServer(Server& ser, FlightDataVariables& dataMaps);

    virtual void execute(vector<string>::iterator &it);
};


#endif //FLIGHTSTIMULATOR_OPENDATASERVER_H
