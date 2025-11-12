# Hash Table in C++

This project presents the implementation of a **Hash Table** in C++.

The Hash Table is an essential data structure for efficient data storage, allowing insertion, search, and removal operations in average time **O(1)**.

## Demonstrated Concepts

*   **Data Structures:** Implementation of a Hash Table.
*   **Collision Resolution:** Use of **separate chaining** to handle collisions, where each table _bucket_ stores a linked list of elements.
*   **Object-Oriented Programming (OOP):** Use of classes and inheritance for the table structure.
*   **Hash Function:** Implementation of a hashing function to map keys to table indices.

## Project Structure

| File | Description |
| :-- | :-- |
| `TabelaEspalhamentoAbstrata.h` | Interface (abstract class) that defines the Hash Table methods. |
| `MinhaTabelaEspalhamento.h` | Concrete implementation of the Hash Table. |
| `Posicao.h` | Auxiliary class to represent the position in the table. |
| _Linked List Files_ | The implementation depends on a Linked List for separate chaining. |

## How to Compile and Run

This project is a set of header files and must be integrated with a test file (`main.cpp`) and the Linked List files to function.

1.  Ensure you have a C++ compiler (such as g++) and the Linked List files (from `lista-encadeada-cpp`) in the same environment.
2.  Compile the project:
    
    ```shell
    g++ -std=c++17 main.cpp -o hash_table_test
    ```
    
3.  Run the test:
    
    ```shell
    ./hash_table_test
    ```
    

**Language:** C++ **Topics:** Hash Table, Data Structures, Collision Resolution, OOP.
