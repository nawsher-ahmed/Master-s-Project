#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return 1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return 1;
    }

    if (listen(server_sock, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return 1;
    }

    int client_sock = accept(server_sock, nullptr, nullptr);
    if (client_sock < 0) {
        std::cerr << "Accept failed" << std::endl;
        return 1;
    }

    int data[2];
    recv(client_sock, data, sizeof(data), 0);
    std::cout << "Data received from client: " << data[0] << " " << data[1] << std::endl;

    data[0] *= 2;
    data[1] *= 2;
    send(client_sock, data, sizeof(data), 0);
    std::cout << "Data sent to client: " << data[0] << " " << data[1] << std::endl;

    close(client_sock);
    close(server_sock);
    return 0;
}

