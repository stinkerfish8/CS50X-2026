# Command-Line Arguments

## Introduction to Command-Line Arguments
Passing Inputs via Terminal: C programs can accept inputs directly from the terminal at the moment of execution. This eliminates the need to prompt the user for input later using functions like get_string. This is achieved by modifying the traditional main function signature to accept parameters: `int main(int argc, char *argv[])` (or `string argv[]` in the CS50 library).

---

## Core Components

### Argument Count (argc)
* **Definition:** A standard integer variable that stores the total number of words typed into the terminal command line to run the program. Words are separated by spaces.

### Argument Vector (argv)
* **Definition:** An array of strings containing the actual words typed by the user.
* **The System Rule:** `argv[0]` is always reserved for the name of the executable file itself (e.g., `./hello`). The actual custom inputs provided by the user start from `argv[1]` onward.

---

## Critical Rules and Behaviors

### Positional Dependency (Strict Ordering)
* **The Rule:** The order in which you type arguments in the terminal strictly dictates their index inside the `argv` array. If your program expects a number in `argv[1]` and a name in `argv[2]`, typing them in reverse order will assign them to the wrong variables, leading to bugs or crashes. You cannot skip or reorder arguments unless you explicitly write complex logic to parse them.

### Data Type Constraint
* **Everything is Text:** Even if you type a number in the terminal (like `1024`), it is initially stored inside the `argv` array as a text string (`"1024"`), not an integer. To use it in mathematical operations, you must manually convert it using functions like `atoi` (Argument to Integer) from the `<stdlib.h>` library.

---

## The Safety Boundary (Segmentation Fault)
* **The Danger:** If a program tries to access an index of `argv` that does not exist (e.g., checking `argv[1]` when the user didn't type any argument), the program will attempt to read an unallocated sector of RAM, causing a critical crash called a "Segmentation Fault".
* **Defensive Programming:** Code must be secured with a conditional block (e.g., `if (argc != 2)`) at the very beginning of the `main` function to verify the correct number of arguments exists before attempting to read them, acting as a crucial software safety belt.
