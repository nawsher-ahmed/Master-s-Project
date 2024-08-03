
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "../include/adapter.h"

int main() {
    int server_fd, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port 8080" << std::endl;

    // Accept an incoming connection
    if ((client_sock = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Read data from the client
    read(client_sock, buffer, 1024);

    ExtU_Model2_T receivedData;
    read_from_buffer_ExtU_Model2_T(&receivedData, buffer);

    std::cout << "Data received from client: I = " << receivedData.I << std::endl;

    // Process the data
    ExtY_Model2_T dataToSend;
    dataToSend.U = receivedData.I * 2;

    // Send data back to the client
    write_to_buffer_ExtY_Model2_T(&dataToSend, buffer);
    send(client_sock, buffer, sizeof(dataToSend), 0);

    std::cout << "Processed data sent back to client: U = " << dataToSend.U << std::endl;

    close(client_sock);
    close(server_fd);

    return 0;
}


