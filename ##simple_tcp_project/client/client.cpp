#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return 1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return 1;
    }

    int data[2] = {10, 20};
    send(client_sock, data, sizeof(data), 0);
    std::cout << "Data sent to server: " << data[0] << " " << data[1] << std::endl;

    recv(client_sock, data, sizeof(data), 0);
    std::cout << "Data received from server: " << data[0] << " " << data[1] << std::endl;

    close(client_sock);
    return 0;
}

