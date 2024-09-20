# Simple C++ Socket Program: Hello, World!

This project contains two programs: a **server** and a **client**. The server listens for incoming connections on a specified port and sends a "Hello, World!" message to any client that connects. The client connects to the server, receives the message, and prints it to the console.

## Files
- `server.cpp`: The server-side code that waits for a client connection and sends a message.
- `client.cpp`: The client-side code that connects to the server and receives the message.

## Requirements
To compile and run this program, you'll need a Linux-based system or any environment that supports socket programming in C++ (such as WSL on Windows or macOS).

## How to Compile and Run

1. **Compile the server:**
    ```bash
    g++ server.cpp -o server
    ```

2. **Compile the client:**
    ```bash
    g++ client.cpp -o client
    ```

3. **Run the server:**
    Open a terminal window and run:
    ```bash
    ./server
    ```
    The server will start listening on port `8080`.

4. **Run the client:**
    In another terminal window, run:
    ```bash
    ./client
    ```

    The client will connect to the server and receive the "Hello, World!" message.

## Output Example
When you run the client after starting the server, you should see this output:


## Code Breakdown

### Server (server.cpp)
- Creates a TCP socket and binds it to port `8080`.
- Listens for incoming connections.
- Sends a "Hello, World!" message to the client upon connection.
- Closes the connection after sending the message.

### Client (client.cpp)
- Creates a TCP socket.
- Connects to the server at `127.0.0.1` (localhost) on port `8080`.
- Receives the "Hello, World!" message from the server and displays it.

## Dependencies
- **C++ Compiler**: Tested with `g++`.
- **POSIX Sockets**: The code uses POSIX socket libraries (`sys/socket.h`, `netinet/in.h`, etc.), which are available on Linux, macOS, and Windows Subsystem for Linux (WSL).

## License
This project is open-source and available for educational purposes. Feel free to modify, distribute, or use it as you wish.

## Troubleshooting

- Ensure that the server is running before starting the client.
- If the port `8080` is already in use, you may change the port in both the server and client code.

## Future Improvements

- Add error handling for real-world use cases.
- Implement multithreading in the server to handle multiple clients simultaneously.
- Expand the project to support sending custom messages between the server and client.

