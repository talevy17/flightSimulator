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


void Client::openClient(string ip, double port) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Now connect to the server */
    while (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        if (errno == ECONNREFUSED) {
            usleep(1);
        } else {
            perror("ERROR connecting");
            exit(EXIT_FAILURE);
        }
    }
    this->server_sock_fd = sockfd;
}

void Client::send(string path, double newVal) {
    string first = "set " + path+ " " + to_string(newVal) + " \r\n";
    ssize_t valWrite = write(this->server_sock_fd, path.c_str(), path.size());
    if (valWrite < 0) {
        perror("error writing to socket");
        exit(EXIT_FAILURE);
    }
}

Client::~Client() {
    close(this->server_sock_fd);
}
