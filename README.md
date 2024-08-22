# LightningJX

**LightningJX** is a high-performance, real-time data processor designed for efficiently handling JSON and XML data streams. Built with speed and flexibility in mind, LightningJX operates as a server where clients can connect and send data streams in real time. It can also be integrated as a library in C/C++, C#, and Python projects. Its lightweight design ensures minimal latency, making it ideal for applications requiring rapid and reliable data processing.

## Features

* **Real-Time Stream Processing:** Optimized for low-latency, LightningJX processes incoming data streams in real time, ensuring your applications can handle dynamic data efficiently.

* **Support for JSON and XML:** Whether your data is in JSON or XML format, LightningJX can handle both with ease, providing flexibility in data interchange formats.

* **Server Mode:** Operates as a server, allowing multiple clients to connect and send data streams for processing. This makes it ideal for distributed systems or real-time data aggregation.

* **Customizable Message Handling:** LightningJX provides multiple options for handling incoming messages:

    * **Store on Disk:** Save the processed data to files on disk.
    
    * **Database Storage:** Insert the data into a database (e.g., SQLite, MySQL, PostgreSQL).
    
    * **Custom Handlers:** Implement custom handlers for specific use cases.

* **Library Integration:** LightningJX can also be embedded as a library in your existing C/C++, C#, or Python projects for seamless data processing capabilities.

* **High Performance:** Designed with performance in mind, LightningJX processes large volumes of data with minimal overhead, keeping your applications responsive.

* **Cross-Platform Compatibility:** LightningJX is built to run on multiple platforms, making it versatile for deployment across different environments.

## Installation

### Standalone Server

1) **Clone the Repository:**
```bash
git clone https://github.com/sharvillimaye/LightningJX.git
cd LightningJX
```
2) **Build the Server:**
```bash
make
```
3) **Run the Server:**
```
./bin/lightningjx-server [options]
```


### Library Integration

**C/C++**

1) **Include Header:**
```c
#include "lightningjx.h"
```
2) **Link Library:** When compiling your C/C++ project, link against the LightningJX library:
```bash
gcc -o yourproject yourproject.c -L/path/to/lightningjx -llightningjx
```

**C#**

1) **Add DLL Reference:** Add a reference to the LightningJX DLL in your C# project.
2) **Use in Code:**
```C#
using LightningJX;
```

**Python**

1) **Install the Python Package:**
```bash
pip install lightningjx
```
2) **Use in Code:**
```python
import lightningjx
```


## Usage

### Server Options

* `-p <port>`: Specify the port on which the server will listen (default: 8080).
* `-t <type>`: Specify the data type to process (`json` or `xml`).
* `-m <mode>:` Specify the message handling mode (default: `disk`). Options:

    * `disk:` Store processed data to disk.
    * `db:` Insert data into a database.
    * `custom:` Use a custom message handler.

* `-v`: Enable verbose logging.

### Example Usage

**Server:**
```bash
./lightningjx-server -p 8080 -t xml -m db
```

Clients can then connect to the server on the specified port and start sending JSON or XML data streams. The server will handle the incoming messages according to the specified mode.

### Custom Message Handlers

For advanced use cases, you can implement custom handlers in your application code. Simply set the server mode to custom and provide your own handling logic using the LightningJX API.

## Contributing

Contributions are welcome! Please submit pull requests, report issues, or suggest features via the GitHub repository.

## License

LightningJX is licensed under the MIT License. See `LICENSE` for more details.
