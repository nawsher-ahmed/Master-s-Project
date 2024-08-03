#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/adapter.h"

int main() {
    int client_sock;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connect to the server
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    ExtU_Model2_T dataToSend = {10};
    write_to_buffer_ExtU_Model2_T(&dataToSend, buffer);
    send(client_sock, buffer, sizeof(dataToSend), 0);

    std::cout << "Data sent to server: I = " << dataToSend.I << std::endl;

    // Read response from the server
    read(client_sock, buffer, 1024);

    ExtY_Model2_T receivedData;
    read_from_buffer_ExtY_Model2_T(&receivedData, buffer);

    std::cout << "Data received from server: U = " << receivedData.U << std::endl;

    close(client_sock);

    return 0;
}



