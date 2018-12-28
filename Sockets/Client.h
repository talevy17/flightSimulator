#ifndef FLIGHTSIMULATOR_CLIENT_H
#define FLIGHTSIMULATOR_CLIENT_H

#include <mutex>

using namespace std;

class Client {
    int server_sock_fd;
    bool isRunning;
public:
    /**
     * CTOR, initializes the run boolean.
     */
    Client();

    /**
    * open client connect to server
    * @param ip
    * @param port
    */
    void openClient(string ip, double port);

    /**
    * the function gets address and value and update the exist val
    * in this address by connecting the socket
    * @param path  - address
    * @param newVal - to update
    */
    void send(string path, double newVal);

    /**
    * close the connection if it was open
    */
    void closeClient();

    ~Client();
};


#endif //FLIGHTSIMULATOR_CLIENT_H
