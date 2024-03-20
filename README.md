# MiniWeb Server in C

This is a minimalist implementation of a web server in C that serves files requested by clients over HTTP.

## Usage

1. Compile the code:
    ```bash
    gcc socket.c -o socket
    ```

2. Run the compiled executable:
    ```bash
    ./WebServer
    ```

3. Open a web browser and navigate to `http://localhost:8080/yourfile.html` to retrieve the contents of `yourfile.html`.

## Description

This simple web server listens on port 8080 for incoming HTTP requests. Upon receiving a request, it extracts the requested file name from the HTTP request header, opens the file, and sends its contents back to the client.

## Implementation Details

- **Socket Creation**: The server creates a socket using `socket()` function provided by `sys/socket.h`.

- **Binding and Listening**: The server binds the socket to a specific address and port using `bind()` and starts listening for incoming connections using `listen()`.

- **Accepting Connections**: When a client connects, the server accepts the connection using `accept()`.

- **Receiving Request**: The server receives the HTTP request from the client using `recv()`.

- **Extracting File Name**: It parses the requested file name from the HTTP request.

- **Opening File**: The server opens the requested file using `open()` with read-only mode.

- **Sending File**: It sends the contents of the requested file back to the client using `sendfile()`.

- **Closing Connections**: After sending the file, the server closes the file descriptor and the client connection.

## Limitations

- This server does not support concurrent connections. It serves one client at a time.

- Error handling and security measures are minimal. This code is not suitable for production use without further enhancements.

- The server sends a fixed-size buffer of 256 bytes from the file. This limits the size of files that can be served.
