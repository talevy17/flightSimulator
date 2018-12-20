#include "openDataServer.h"
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include "Lexer.h"
#define BUFFER 5000

//////////////////
//thread here!!!!!!
//////////////////

void openDataServer :: execute(queue<string> &commandLine){

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
}