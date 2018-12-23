
#ifndef FLIGHTSIMULATOR_SERVER_H
#define FLIGHTSIMULATOR_SERVER_H

#include "FlightDataVariables.h"
#include "vector"
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "strings.h"

class Server {
    FlightDataVariables &data;
    int port;
    int hz;
public:
    Server(FlightDataVariables &varsData);

    int openServer(int port, int hz);

    string socketReader(int sockfd);

};


#endif //FLIGHTSIMULATOR_SERVER_H
