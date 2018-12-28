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
    /**
    * CTOR, initialized the data table and mutex.
    * @param m
    * @param varsData
    */
    Server(mutex &m, FlightDataVariables &varsData);

    /**
     * opens the socket for reading from the simulator's data stream.
     * @param port
     * @param hz
     */
    void openServer(int port, int hz);

    /**
     * reads a stream from the socket and updates the flight data map.
     * @return
     */
    string socketReader();

    /**
    * stops inner thread's loop.
    */
    void closeServer();

    /**
    * DTOR, closes connections.
    */
    ~Server();
};


#endif //FLIGHTSIMULATOR_SERVER_H
