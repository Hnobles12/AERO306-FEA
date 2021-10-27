# AERO306-FEA

## Overview

This repo houses code to complete a Finite Element Analysis of a simiple beam to satisfy the requirements for AERO 306. The program is written in modern C++ and makes use of many features of C++11.

## Installation:

The program can be installed/compiled using MAKE commands or by writing the compilation commands yourself.

### Using the MAKEFILE:

The commands in the makefile are written for a UNIX-like system (Linux, MacOs, etc.) and may not work for a Windows machine. However, using a bash shell (Git for Windows, etc.) or with Windows Subsystem for Linux (WSL) will allow for the use of the commmands as they are written below.

```bash
$ cd AERO306-FEA
$ make
```

After the above commands, the executable can be found in the `bin/` directory.

### Manual Compilation:

The compilation process is relatively straightforward if you are familiar with C/C++ compilation. To compile the executable run the following commands:

```bash
$ cd AERO306-FEA
$ g++ -I./include -o ./bin/FEA.out ./src/*.cpp
```

## Using the Program

The program is intended to be run from the command line, as it requires command line arguments to run properly. The input and output filenames are able to be passed to the program when running it. The format of these arguments is as follows:

```bash
$ ./FEA.out <input_file_path> <output_file_path> <display_to_stdout?>
```

For example, to read from a file `input.txt` and output the processed data to `output.txt` as well as display to stdout:

```bash
$ ./bin/FEA.out ./data/input.txt  ./data/output.txt  1
```

To quickly run the program using the default (given) input file, I have incuded a special make command which cleans the working tree, builds, and executes the binary with the arguments above. The command is as follows:

```bash
$ make run
```
