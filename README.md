# TreeGui Data Structure Project

## Description

This project implements a generic k-ary tree in C++. The tree supports various types of iterators (Pre-Order, Post-Order, In-Order, BFS, DFS) and can be transformed into a heap. It also includes methods for adding nodes and visualizing the tree using a GUI.

**Course:** System Programming 2  
**Assignment:** EX4  
**University:** Ariel University

## Features

- **Generic k-ary Tree**: Supports nodes with up to k children.
- **Iterators**: Implements Pre-Order, Post-Order, In-Order, BFS, and DFS iterators.
- **Heap Conversion**: Converts binary trees to min-heaps.
- **GUI Visualization**: Visualizes the tree using a GUI library.

## Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/MaorBer/CPP_EX4
    cd Downloads/CPP_EX4
    ```

2. **Install dependencies:**

    Ensure you have Qt installed for GUI support. Install Qt from [Qt official site](https://www.qt.io/download).

## Building the Project

1. **Generate Makefile:**

    ```bash
    qmake Treegui.pro
    ```

2. **Compile the project:**

    ```bash
    make
    ```

3. **Compile the tests:**

    ```bash
    make test
    ```

4. **Run the example program:**

    ```bash
    make tree
    ```

## Usage

- **Testing**: Run the tests using the `make test` command.
- **Tree Example**: Run the example program using `make tree`.

## Author

Maor Berenstein  
Email: maorw9@gmail.com

## Contact

For any questions or feedback, feel free to reach out via email.

## Notes

- This project is part of the System Programming 2 course at Ariel University.
- Make sure to follow the project's specific guidelines and instructions for proper implementation.

