# my CheatSheet
[Terminal](#1-terminal-navigation--file-management) | [Flags](#2-terminal-modifier-flags) | [Compilation](#3-c-compilation--execution) | [Shortcuts](#4-essential-terminal-shortcuts) | [VSC](#5-visual-studio-code-efficiency-shortcuts) | [Data Types](#6-c-data-types-ram-footprint--format-specifiers)

Personal reference guide for terminal navigation, environment shortcuts, and low-level C programming concepts.

---

## 1. Terminal Navigation & File Management

| Command | Action | Visual Metaphor / Analogy |
| :--- | :--- | :--- |
| `pwd` | **P**rint **W**orking **D**irectory. Shows exactly where you are in the folder tree. | "GPS / You are here" |
| `ls` | **L**i**s**t. Shows all files and folders in the current directory. | Opening a chest to see its contents |
| `cd <dir>` | **C**hange **D**irectory. Moves inside the specified folder. | Walking through a door |
| `cd ..` | Moves up one level (to the parent directory). | Taking a step back / Exiting a room |
| `code <file>` | Creates a new file (or opens an existing one) directly in VS Code. | Spawning an item into your workspace |
| `mkdir <dir>`| **M**a**k**e **D**irectory. Creates a new empty folder. | Placing an empty box |
| `mv <src> <dest>` | **M**o**v**e. Moves a file/folder, or **renames** it if the path stays the same. | Shifting an item / Changing a label |
| `cp <src> <dest>` | **C**o**p**y. Duplicates a file from source to destination. | Cloning an item |
| `rm <file>` | **R**e**m**ove. Permanently deletes a file. | Throwing an item into lava (No Recycle Bin!) |
| `rmdir <dir>`| **R**e**m**ove **D**irectory. Deletes a folder *only if it is completely empty*. | Breaking an empty container |

---

## 2. Terminal Modifier Flags

Flags are options passed after a command (using `-`) to alter its behavior.

| Flag | Meaning | What it does | Minecraft / WorldEdit Parallel |
| :--- | :--- | :--- | :--- |
| `-f` | **F**orce | Bypasses confirmations. Overwrites or deletes without asking permission. | `//schematic save -f` (Forces overwrite) |
| `-r` | **R**ecursive | Acts on a folder *and* everything inside it (subfolders and files). | `//replace` or broad radius operations |
| `rm -r <dir>`| Recursive Delete | Deletes a folder and **all** its contents permanently. **Use with caution!** | `/kill` selector targeting a whole block radius |
| `cp -r <src> <dest>`| Recursive Copy | Clones an entire folder structure along with all its files. | `//copy` and `//paste` of a massive structure |

---

## 3. C Compilation & Execution

| Command | Action | What happens behind the scenes |
| :--- | :--- | :--- |
| `make <program>` | Compiles the `<program>.c` file into a machine-code executable binary. | Converts human-readable text into raw `0`s and `1`s for the RAM. |
| `./<program>` | Executes/Runs the compiled binary program. | Loads the machine code into the RAM and tells the CPU to run it. |
| `debug50 ./<program>` | Launches the CS50 graphical debugger for that specific program. | Freezes time inside the CPU, letting you inspect the RAM line by line. |

---

## 4. Essential Terminal Shortcuts

| Shortcut | Action | Efficiency Impact |
| :--- | :--- | :--- |
| `Tab` | **Auto-completes** file or folder names while typing. | Massive time saver; prevents typos. |
| `Arrow Up / Down` | Scrolls through your previously typed commands history. | Saves you from retyping long commands or paths. |
| `Ctrl + L` | Clears the terminal screen. | Wipes away the visual clutter without resetting your state. |
| `Ctrl + U` | Wipes out the current line from the cursor backward. | Instant reset if you mess up a long command before hitting Enter. |
| `Ctrl + C` | **Interrupted / Kill**. Instantly forces the running program to stop. | Emergency brake if you trigger an infinite loop or a memory leak. |

---

## 5. Visual Studio Code Efficiency Shortcuts

| Shortcut (Windows/Linux) | Shortcut (macOS) | Action | Context / Visual Use Case |
| :--- | :--- | :--- | :--- |
| `Ctrl + /` | `Cmd + /` | **Toggle Line Comment**. Comments out selected code. | Hides a snippet from the compiler without deleting it. |
| `Alt + Shift + A` | `Shift + Option + A` | **Toggle Block Comment** (`/* ... */`). | Safely wraps entire old chunks of code in a comment block. |
| `Ctrl + \`` (Backtick) | `Ctrl + \`` (Backtick) | Toggles the built-in terminal window open/closed. | Quick switch between writing code and compiling it. |
| `Alt + Up / Down` | `Option + Up / Down` | **Moves the current line** (or selection) up or down. | Instantly moves a variable declaration or a loop boundary. |
| `Shift + Alt + Down` | `Shift + Option + Down`| **Duplicates the line** directly below. | Perfect for creating repetitive test arrays or `printf` lines. |
| `Ctrl + F` | `Cmd + F` | Find text within the open file. | Locates where a specific variable or array index is used. |
| `Ctrl + Z` | `Cmd + Z` | Undo last action. | Ultimate safety net when you delete code by accident. |

---

## 6. C Data Types, RAM Footprint & Format Specifiers

| Data Type | RAM Size (Bytes) | RAM Size (Bits) | Format Specifier | What it stores / Notes |
| :--- | :--- | :--- | :--- | :--- |
| `char` | 1 Byte | 8 bits | `%c` | A single character/letter (e.g., `'A'`). Wrapped in single quotes. |
| `int` | 4 Bytes | 32 bits | `%i` or `%d` | Integers / whole numbers (positive and negative). No decimals. |
| `float` | 4 Bytes | 32 bits | `%f` | Standard floating-point numbers. Good for general decimals. |
| `double` | 8 Bytes | 64 bits | `%lf` | Double-precision floating-point numbers. Used by default for numbers written with `.0`. |
| `string` | Variable | Variable | `%s` | Text (a sequence of characters). Wrapped in double quotes `""`. *(Requires <cs50.h>)* |
| `long` | 8 Bytes | 64 bits | `%li` | Extremely large integers (like credit card numbers in the *Credit* pset). |
