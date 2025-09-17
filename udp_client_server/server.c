#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    //Socket File Descriptor: When you create a socket using a system call like socket(), the operating system returns a socket file descriptor. This integer acts as a handle that your program uses to refer to that specific socket for subsequent operations, such as connect(), bind(), listen(), accept(), send(), and recv().
    //creating socket file descriptor

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket connection failed");
        exit(EXIT_FAILURE);
    }
    
    //fill a block of memory (of size servaddr in this case) with a specified value (0) in this case
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    return 0;
}