
#include "Server.h"

#define BUF 1000

/**
 * CTOR.
 * @param varsData
 */
Server::Server(FlightDataVariables &varsData) : data(varsData) {}

int Server::openServer(int port, int hz) {
    this->port = port;
    this->hz = hz;
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd, 1);
    cout << "waiting for connection..." << endl;
    /* Accept actual connection from the client */
    newsockfd = ::accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    cout << "connected!" << endl;
    return newsockfd; //return the new sockfd
}

vector<double> xmlDataSplitter(string buff) {
    vector<double> info;
    size_t pos = 0;
    string delimiter = " ";
    while ((pos = buff.find(delimiter)) != string::npos) {
        info.push_back(stod(buff.substr(0, pos)));
        buff.erase(0, pos + delimiter.length());
    }
    info.push_back(stod(buff.substr(0, pos)));
    return info;
}

string Server::socketReader(int sockfd) {
    while (true) {
        char buffer[BUF];
        bzero(buffer, BUF);
        ssize_t n = read(sockfd, buffer, BUF - 1);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        } else if (n == 0) {
            // ?
            int y = 0;
        } else {
            buffer[n] = NULL; // warning
            //sleep(1 / time_per_sec); // sleep for the given time
            cout << buffer << endl; // for check
        }
        vector<double> split_buff = xmlDataSplitter(buffer);
        this->data.setFlightData(split_buff); // update the map
    }
    return "";
}