#ifndef FLIGHTSIMULATOR_CLIENT_H
#define FLIGHTSIMULATOR_CLIENT_H

#include <mutex>

using namespace std;

class Client {
    int server_sock_fd;
public:
    void openClient (string ip, double port);
    void send(string path, double newVal);
    ~Client();
};


#endif //FLIGHTSIMULATOR_CLIENT_H
