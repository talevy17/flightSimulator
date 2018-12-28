#include <cstring>
#include "Server.h"

#define BUF 2000

/**
 * CTOR, initialized the data table and mutex.
 * @param m
 * @param varsData
 */
Server::Server(mutex &m, FlightDataVariables &varsData) : _mutex(m), data(varsData) {this->isRunning = false;}

/**
* opens the socket for reading from the simulator's data stream.
* @param port
* @param hz
*/
void Server::openServer(int port, int hz) {
    this->port = port;
    this->hz = hz;
    int opt = 1;
    struct sockaddr_in server, client;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
    if (bind(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    socklen_t addrlen = sizeof(sockaddr_in);
    newsockfd = accept(sockfd, (struct sockaddr *) &client, &addrlen);
    if (newsockfd < 0) {
        cout << "Connection accepted, starting listener thread" << endl;
    }
}

/**
 * splits the data from the stream into a vector of values.
 * @param buff
 * @return
 */
vector<double> xmlDataSplitter(string buff) {
    //init a data vector<double> for the data.
    vector<double> info;
    size_t pos = 0;
    string delimiter = ",";
    //while there are still delimiters.
    while ((pos = buff.find(delimiter)) != string::npos) {
        info.push_back(stod(buff.substr(0, pos)));
        buff.erase(0, pos + delimiter.length());
    }
    info.push_back(stod(buff.substr(0, pos)));
    return info;
}

/**
* reads a stream from the socket and updates the flight data map.
* @return
*/
string Server::socketReader() {
    ssize_t valread;
    this->isRunning = true;
    char buffer[BUF] = {0};
    while (this->isRunning) {
        listen(this->sockfd, 5);
        valread = read(this->newsockfd, buffer, sizeof(buffer));
        if (valread < 0) {
            perror("Error reading from socket");
        }
        vector<double> values = xmlDataSplitter(buffer);
        this->data.setFlightData(values);
    }
    return "exit";
}

/**
* stops inner thread's loop.
*/
void Server::closeServer() {
    if (this->isRunning) {
        close(this->sockfd);
        close(this->newsockfd);
    }
    this->isRunning = false;
}

/**
* DTOR, closes connections.
*/
Server::~Server() {
}