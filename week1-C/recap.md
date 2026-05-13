# CS50 Recap - Week 1: C

[Course Material](https://cs50.harvard.edu/x/weeks/1/)

## 1. Environment & Tools
* **VS Code & Codespaces:** Cloud-based Integrated Development Environment (IDE).
* **Terminal (CLI):** Command Line Interface used for navigation (`ls`, `cd`, `mkdir`, `cp`, `mv`).
* **Compiler:** Tool that translates source code (C) into machine code (binary) using `make`.

## 2. Syntax & Structure
* **Headers:** Including libraries (e.g., `#include <stdio.h>` for `printf`).
* **Main Function:** The program's entry point: `int main(void) { ... }`.
* **Prototypes:** Declaring functions at the top of the file to notify the compiler (similar to custom pink blocks in Scratch).
* **Comments:** `//` for single-line, `/* ... */` for blocks. Essential for writing pseudocode.

## 3. Variables & Data Types
* **Types:** `int`, `long`, `float`, `double`, `char`, `string`.
* **Scope:** The context in which a variable exists, typically limited to the curly braces `{}` where it was declared.
* **Type Casting:** Explicitly converting one data type to another (e.g., float to int, which leads to truncation/loss of precision).
* **Constants:** `const int N = 3;` - Fixed values that never change during execution, usually written in UPPERCASE.

## 4. Control Flow
* **Conditionals:** `if`, `else if`, `else`.
* **Logical Operators:** `&&` (AND), `||` (OR), `!` (NOT).
* **Loops:**
    * `while`: Checks the condition first, then executes.
    * `do-while`: Executes at least once, then checks the condition (ideal for input validation).
    * `for`: Loop with a built-in counter, best used when the number of iterations is known.

## 5. Syntactic Sugar & Operators
* **Increment/Decrement:** `i++`, `i--`.
* **Compound Assignment:** `i += 5`, `x *= 2`.
* **Format Specifiers (Placeholders):** `%i` (int), `%s` (string), `%f` (float). Use `%.2f` to specify decimal precision.

## 6. Code Quality (CS50 Metrics)
* **Correctness:** Automated testing via `check50`.
* **Style:** Visual consistency and formatting checked by `style50`.
* **Design:** The logical efficiency and elegance of the solution.
