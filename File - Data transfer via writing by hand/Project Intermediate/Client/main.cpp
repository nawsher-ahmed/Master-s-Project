#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_file(const char *filename, int sock) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Unable to open file for reading");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), fp)) {
        send(sock, buffer, strlen(buffer), 0);
    }

    fclose(fp);
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }

    send_file("extracted_data.txt", sock);
    printf("Data buffer sent\n");

    close(sock);
    return 0;
}

