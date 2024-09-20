#include <iostream>
#include <cstring>     // For memset
#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in structure
#include <unistd.h>     // For close function

int main() {
    // Step 1: Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (server_fd == 0) {
        std::cerr << "Failed to create socket!" << std::endl;
        return -1;
    }

    // Step 2: Define the server address and port
    sockaddr_in address;
    address.sin_family = AF_INET;           // Use IPv4
    address.sin_addr.s_addr = INADDR_ANY;   // Accept connections from any IP
    address.sin_port = htons(8080);         // Port number (8080)

    // Step 3: Bind the socket to the address
    if (bind(server_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Binding failed!" << std::endl;
        return -1;
    }

    // Step 4: Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed!" << std::endl;
        return -1;
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    // Step 5: Accept a connection from a client
    int addrlen = sizeof(address);
    int new_socket = accept(server_fd, (sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        std::cerr << "Accept failed!" << std::endl;
        return -1;
    }

    // Step 6: Send a "Hello, World!" message to the client
    const char* hello = "Hello, World!";
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Hello, World! message sent to client." << std::endl;

    // Step 7: Close the socket
    close(new_socket);
    close(server_fd);

    return 0;
}
