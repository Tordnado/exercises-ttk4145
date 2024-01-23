#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 30000

int main() {
    // Create a UDP socket
    int recvSock = socket(AF_INET, SOCK_DGRAM, 0);
    if (recvSock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;  // Listen on all available interfaces
    addr.sin_port = 0;  // Let the system choose a random port

    // Bind the socket
    if (bind(recvSock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Bind failed");
        close(recvSock);
        exit(EXIT_FAILURE);
    }

    // Buffer for receiving data
    char buffer[BUFFER_SIZE];

    // Empty address structure for the sender's information
    struct sockaddr_in fromWho;
    socklen_t fromWhoLen = sizeof(fromWho);

    while (1) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Receive data on the socket
        size_t numBytesReceived = recvfrom(recvSock, buffer, sizeof(buffer), 0, (struct sockaddr*)&fromWho, &fromWhoLen);

        if (numBytesReceived < 0) {
            perror("Receive failed");
            close(recvSock);
            exit(EXIT_FAILURE);
        }

        // Convert the buffer to a string
        buffer[numBytesReceived] = '\0';

        // Optional: Filter out messages from ourselves (assuming localIP is a string)
        char localIP[] = "127.0.0.1";
        if (strcmp(inet_ntoa(fromWho.sin_addr), localIP) != 0) {
            // Do stuff with the received data (stored in buffer)
            printf("Received %zd bytes from %s:%d\n", numBytesReceived, inet_ntoa(fromWho.sin_addr), ntohs(fromWho.sin_port));
            printf("Message: %s\n", buffer);
        }
    }

    // Close the socket (unreachable in this example)
    close(recvSock);
}