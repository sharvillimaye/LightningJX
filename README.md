# LightningJX

**LightningJX** is a high-performance, real-time data processor designed for efficiently handling JSON and XML data streams. Built with speed and flexibility in mind, LightningJX operates as a server where clients can connect and send data streams in real time. It can also be integrated as a library in C/C++, C#, and Python projects. Its lightweight design ensures minimal latency, making it ideal for applications requiring rapid and reliable data processing.

## Features

* **Real-Time Stream Processing:** Optimized for low-latency, LightningJX processes incoming data streams in real time, ensuring your applications can handle dynamic data efficiently.
* **Support for JSON and XML:** LightningJX handles both JSON and XML data formats, providing versatility in how you process data.
* **Server Mode:** LightningJX operates as a server, allowing multiple clients to connect and send data streams for processing. By default, the server logs incoming data to a file, but this behavior can be fully customized through a user-defined callback function.
* **Custom Message Handling:** LightningJX provides a default handler template that logs data to a file. Users can customize this template to specify exactly how incoming messages should be processed.
* **Library Integration:** LightningJX can also be embedded as a library in your existing C/C++, C#, or Python projects for seamless data processing capabilities.
* **High Performance:** Designed with performance in mind, LightningJX processes large volumes of data with minimal overhead, keeping your applications responsive.
* **Cross-Platform Compatibility:** LightningJX is built to run on multiple platforms, making it versatile for deployment across different environments.

## Installation

### Standalone Server

1. Clone the Repository:

    ```bash
    git clone https://github.com/yourusername/LightningJX.git
    cd LightningJX
    ```

2. Build the Server:

    ```bash
    make
    ```

3. Run the Server:

    ```bash
    ./lightningjx-server [options]
    ```

### Library Integration

#### C/C++

1. Include Header:

    ```c
    #include "lightningjx.h"
    ```

2. Link Library: <br> *When compiling your C/C++ project, link against the LightningJX library.*

    ```bash
    gcc -o yourproject yourproject.c -L/path/to/lightningjx -llightningjx
    ```

#### C#

1. Add DLL Reference: <br> *Add a reference to the LightningJX DLL in your C# project.*
2. Use in Code:

    ```csharp
    using LightningJX;
    ```

#### Python

1. Install the Python Package:

    ```bash
    pip install lightningjx
    ```

2. Use in Code:

    ```python
    import lightningjx
    ```

## Usage

### Server Mode

When running in server mode, LightningJX listens on a specified port for incoming connections and processes JSON or XML data streams sent by clients. The server's behavior is fully customizable through a callback function that you must define.

#### Default Behavior

By default, the LightningJX server logs all incoming data to a file named `data.log` in the current working directory. This provides basic functionality out of the box, allowing users to see the server in action without requiring any custom configuration.

#### Starting the Server

To start the server, you need to specify the port and data type. However, the server will not process incoming data unless you define a callback function.

```bash
./lightningjx-server -p 8080 -t json
```

The above command will start the server on port 8080 and process JSON data streams, logging them to `data.log`. 

#### Server Settings

* `-p <port>`: Specify the port on which the server will listen (default: 8080).
* `-t <type>`: Specify the data type to process (`json` or `xml`).
* `-v`: Enable verbose logging.

### Custom Message Handling

If the default logging behavior doesn't meet your needs, you can define a custom callback function to handle incoming messages according to your application's requirements. The default handler can be used as a template for this customization.

#### Default Handler Template in C

```c
#include "lightningjx.h"
#include <stdio.h>

void default_handler(const char* data) {
    // Log data to file
    FILE *f = fopen("data.log", "a");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(f, "%s\n", data);
    fclose(f);
}

int main() {
    LightningJX_SetMessageHandler(default_handler);
    LightningJX_StartServer(8080, JSON);
    return 0;
}
```

*More information about library usage in Python and C# can be found in the `examples` directory.*

## Contributing

Contributions are welcome! Please submit pull requests, report issues, or suggest features via the GitHub repository.

## License

LightningJX is licensed under the MIT License. See `LICENSE` for more details.
