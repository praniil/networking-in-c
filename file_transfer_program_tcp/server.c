#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>


int main() {
    // create a socket
    int sockfd; //socket file desciptor

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully with descriptor: %d\n", sockfd);

    //bind the socket to ip address and port

    struct sockaddr_in address;
    int port = 8000;    //port that will be bound to

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;   //address that accepts all the incomming message
    address.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket is successfully bind to the ip address and port\n");

    return 0;
}