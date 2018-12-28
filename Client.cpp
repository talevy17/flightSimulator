#include "Client.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "FlightDataVariables.h"

#define BUFFER 256

/**
* CTOR, initializes the run boolean.
*/
Client::Client() {this->isRunning = false;}

/**
 * open client connect to server
 * @param ip
 * @param port
 */
void Client::openClient(string ip, double port) {
    //connect to server
    struct sockaddr_in serv_addr;
    int sock_fd;
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(0);
    }
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        exit(0);
    }else {
        cout << "connected" <<endl;
    }
    this->server_sock_fd = sock_fd;
    this->isRunning = true;
}

/**
 * the function gets address and value and update the exist val
 * in this address by connecting the socket
 * @param path  - address
 * @param newVal - to update
 */
void Client::send(string path, double newVal) {
    char *conversion = new char[BUFFER];
    bzero(conversion,BUFFER);
    sprintf(conversion, "set %s %s \r\n", path.c_str(),
            std::to_string(newVal).c_str());
    ::send(this->server_sock_fd,conversion , strlen(conversion),0);
    delete[] conversion;
}

/**
 * close the connection if it was open
 */
void Client::closeClient() {
    if (this->isRunning) {
        close(this->server_sock_fd);
    }
    this->isRunning = false;
}

/**
 * destructor
 */
Client::~Client() {}
