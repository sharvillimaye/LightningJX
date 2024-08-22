# Testing the server functionality by making a small client in python

import socket
import threading

def connect():
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect(('127.0.0.1', 8080))
        sock.sendall(b'Test\n')  # Use a byte literal for sending
        response = sock.recv(1024)
        print(response.decode())  # Decode the bytes to a string
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        sock.close()

threads = []
for i in range(0, 50):
    thread = threading.Thread(target=connect)
    thread.start()
    threads.append(thread)

for thread in threads:
    thread.join()