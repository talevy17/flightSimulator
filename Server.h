
#ifndef FLIGHTSIMULATOR_SERVER_H
#define FLIGHTSIMULATOR_SERVER_H

#include "FlightDataVariables.h"
#include "vector"
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "strings.h"
#include <mutex>

class Server {
    FlightDataVariables &data;
    mutex &_mutex;
    int port;
    int hz;
    bool isRunning;
    int sockfd;
    int newsockfd;
public:
    Server(mutex &m, FlightDataVariables &varsData);

    void openServer(int port, int hz);

    string socketReader();

    void closeServer();

};


#endif //FLIGHTSIMULATOR_SERVER_H
