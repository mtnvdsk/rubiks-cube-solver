# Rubik's Cube Solver

## Overview
This repository contains a Rubik's Cube solver implemented in C++. It includes various data structures and algorithms to manipulate and solve the Rubik's Cube efficiently. The project utilizes pattern databases and breadth-first search (BFS) algorithms to find solutions.

## Features
- **Multiple Cube Representations**: Supports different representations of the Rubik's Cube, including 1D arrays and bitboards.
- **Pattern Databases**: Implements corner and edge pattern databases for efficient move counting.
- **Solvers**: Includes various solver algorithms such as Depth-First Search (DFS), Breadth-First Search (BFS), Iterative Deepening Depth-First Search (IDDFS), and A* search (IDA*).
- **Random Shuffle**: Can randomly shuffle the cube for testing purposes.

## Requirements
- C++11 or higher
- CMake
- A C++ compiler (e.g., g++, clang++)

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/rubiks-cube-solver.git
2. Navigate to the project directory
    ```bash
    cd rubiks-cube-solver
3. Create a build directory and navigate into it:
    ```bash
    mkdir build && cd build
4. Run CMake to configure the project:
    ```bash
    cmake ..
5. Build the project:
    ```bash
    make

## Usage
After building the project, you can run the executable to start solving the Rubik's Cube. The main entry point is located in main.cpp. You can modify this file to test different functionalities or algorithms.

## Contributing
Contributions are welcome! Please create a pull request for any improvements or new features.