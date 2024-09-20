#include <iostream>
#include <cstring>      // For memset
#include <sys/socket.h> // For socket functions
#include <arpa/inet.h>  // For sockaddr_in and inet_pton
#include <unistd.h>     // For close function

int main() {
    // Step 1: Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Failed to create socket!" << std::endl;
        return -1;
    }

    // Step 2: Define the server address and port
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080); // Connect to port 8080

    // Step 3: Convert IP address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        std::cerr << "Invalid address or address not supported!" << std::endl;
        return -1;
    }

    // Step 4: Connect to the server
    if (connect(sock, (sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection failed!" << std::endl;
        return -1;
    }

    // Step 5: Receive the "Hello, World!" message from the server
    char buffer[1024] = {0};
    int valread = read(sock, buffer, 1024);
    std::cout << "Message from server: " << buffer << std::endl;

    // Step 6: Close the socket
    close(sock);

    return 0;
}
