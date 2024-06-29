# Directory Encryption/Decryption Project

## Overview

This project provides a solution to recursively iterate over all files within a specified directory and either encrypt or decrypt them based on a given flag. It efficiently handles file processing by creating tasks for each file, placing them into a queue, and processing these tasks until the queue is empty.

## Features

- **Recursive File Processing**: Iterates over all files in the given directory and its subdirectories.
- **Encryption/Decryption**: Supports both encryption and decryption of files.
- **Task Queue**: Uses a queue to manage tasks efficiently, ensuring that all files are processed without overwhelming system resources.

## Requirements

- C++17 or later
- install `make`

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/voilentKiller0/Directory-Cryption.git
   cd Directory-Cryption
   ```

2. Build the project using `make`:
   ```sh
   make
   ```

## Usage

### Command-Line Interface

You can run the executable from the command line as follows:

```sh
./encrypt_decrypt.exe
```

### Parameters

- `/path/to/directory`: The directory to be processed.
- `encrypt` or `decrypt`: The operation to be performed, either `encrypt` or `decrypt`.

### Example

To encrypt/decrypt all files in a directory:
```sh
./encrypt_decrypt.exe
```

##### Output
```
Enter the directory: example

Enter the action: encrypt
Processing file : example\file.txt
Executing task: example\file.txt,ENCRYPT
```

## Project Structure

```
directory-encryption-decryption/
│
├── example/
│   └── file.txt
├── src/
│   └── app/
│       ├── encryptDecrypt/
│       │   ├── Cryption.cpp
│       │   ├── Cryption.hpp
│       │   └── CryptionMain.cpp
│       ├── fileHandling/
│       │   ├── io.cpp
│       │   ├── io.hpp
│       │   └── ReadEnv.cpp
│       ├── Processes/
│       │   ├── ProcessManagement.cpp
│       │   ├── ProcessManagement.hpp
│       │   └── Task.hpp
│       ├── .env
│       ├── main.cpp
│       └── main.exe
├── Makefile
└── README.md
```

## Implementation Details

### main.cpp

This script start the process and take directory and action as input initializes the task queue. It also starts the recursive iteration over the files in the specified directory.

### Cryption.cpp & Cryption.hpp

Contains the functions for encryption and decryption of files using the Crypto++ library.

### io.cpp & io.hpp

Handles input/output operations related to file processing.

### ReadEnv.cpp

Handles reading key variables

### ProcessManagement.cpp & ProcessManagement.hpp

Manages the task queue, ensuring that tasks (file processing) are handled efficiently. It includes the logic to add tasks to the queue and process them until the queue is empty.

### Task.hpp

Defines the structure and operations for tasks that are queued for processing.

---
