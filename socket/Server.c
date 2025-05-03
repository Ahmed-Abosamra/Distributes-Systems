#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0; 
    }
    return 1; 
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    int option;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(server_fd, 3);

    printf("Waiting for connections...\n");

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if ( new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        read(new_socket, &option, sizeof(int));

        read(new_socket, buffer, BUFFER_SIZE);

        printf("Server Received: Option %d, String: %s\n", option, buffer);

        if (option == 1) { 
            int result = is_palindrome(buffer);
            write(new_socket, &result, sizeof(int));
        } 
        else if (option == 2) { 
            reverse_string(buffer);
            write(new_socket, buffer, strlen(buffer) + 1);
        } 
        else {
            printf("Invalid option received.\n");
            break;
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
