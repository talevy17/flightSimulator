#include "openDataServer.h"
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include "Lexer.h"
#define BUFFER 5000

//////////////////
//thread here!!!!!!
//////////////////

void openDataServer :: execute(vector<string>::iterator &commandLine){
/*
    while (true) {
        int server_fd, new_socket, valread;
        char buffer[BUFFER];
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(5400);
        bind(server_fd, (struct sockaddr *) &address, sizeof(address));
        listen(server_fd, 5);

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        while(true) {
            ssize_t e = read(new_socket, buffer, 5000);
            printf("%s\n", buffer);
        }

    }
    */

/*
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>

    struct ServerArgs
    {
        int port;
        int hz;
    };

    void* open_server(void* args) {
        ServerArgs* sArgs = (ServerArgs *) args;

        int sockfd, newsockfd, portno, clilen;
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;
        int  n;

        /* First call to socket() function
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        /* Initialize socket structure
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = sArgs->port;

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        /* Now bind the host address using bind() call.
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }

        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection


        if (listen(sockfd, 5) < 0)  {
            perror("Error on listen");
            exit(1);
        }

        clilen = sizeof(cli_addr);

        /* Accept actual connection from the client
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        /* If connection is established then start communicating
        bzero(buffer,256);
        n = read( newsockfd,buffer,255 );

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        cout << "Here is the message: " << buffer << endl;

        return nullptr;
    }


    int main() {
        pthread_t trid;
        ServerArgs* args = new ServerArgs{.port = 5400, .hz = 10};
        pthread_create(&trid, nullptr, open_server, args);
        return 0;
    }
    */
}