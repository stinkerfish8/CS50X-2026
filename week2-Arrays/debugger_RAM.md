# Memory and Debugging

## Introduction to the Debugger
A debugger is a tool that allows you to pause the execution of your program at any specific line (using a breakpoint) and watch how variables change in the RAM in real-time. This helps you find logic errors (bugs) that code compilers cannot detect.
* **CS50 IDE Command**
  To start the debugger in the CS50 environment, open the terminal and type `debug50 ./filename` (replacing `filename` with the name of your compiled program).

---

## Debugger Navigation
* **Step Into**
  Enters inside the called function. The cursor jumps to the very first line of that function, allowing you to debug its internal code line by line.
* **Step Over / Through**
  Executes the entire function in one single step. The cursor moves directly to the next line of code in the current function (e.g., main), hiding the internal details of the called function.

---

## RAM Memory Architecture (Memory Segments)
When a C program runs, the RAM allocated to it is divided into distinct zones, each with a specific purpose:

### The Stack
* **What it stores:** Local variables, function parameters, and local pointers (variables declared inside main or any other function).
* **How it works:** Dynamic and temporary. When a function is called, a new chunk of memory (Stack Frame) is allocated on top of the Stack. The data is passed by value (the function receives a fresh copy of the variables). As soon as the function hits return or reaches its closing brace, its entire Stack Frame is automatically destroyed and wiped from the RAM.

### Data Segment (Global / Static Memory)
* **What it stores:** Global variables (declared outside of all functions) and static variables.
* **How it works:** Permanent and fixed. This memory zone remains allocated and unchanged from the exact moment the program starts until it fully closes. It is never automatically destroyed mid-program like the Stack.

---

## Summary of Key Concepts
* **Passed by Value**
  Functions only receive a duplicated snapshot (a "photocopy") of the arguments you pass them. Modifying a variable inside a function will never change the original variable inside the main function, because they live in completely separate Stack Frames.
* **Scope**
  Local variables only exist within the specific function or code block where they were born. Global variables can be seen and modified from anywhere in the program.
