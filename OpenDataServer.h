#ifndef FLIGHTSTIMULATOR_OPENDATASERVER_H
#define FLIGHTSTIMULATOR_OPENDATASERVER_H

#include "Command.h"
#include "Server.h"
#include <thread>
#include <iostream>
#include <string>
#include "pthread.h"
#include <pthread.h>

class OpenDataServer : public Command{
    FlightDataVariables& data;

public:
    typedef struct {
        int port;
        int hz;
        Server* ser;
        int sockfd;
    } socketParameters;

    OpenDataServer(FlightDataVariables& dataMaps);

    virtual void execute(vector<string>::iterator &it);
};


#endif //FLIGHTSTIMULATOR_OPENDATASERVER_H
