# 1. History of the Linux Operating System

### The Rise of Unix & The GNU Project

In the early 1980s, Unix became widely adopted across universities, research centers, and enterprise environments. In 1983, Unix creators Dennis Ritchie and Ken Thompson received the Turing Award. That same year, Richard Stallman launched the GNU Project at MIT to create a free, Unix-compatible operating system. Unlike proprietary Unix, GNU software was free to use and modify. In 1989, Stallman published the GNU General Public License (GPL) to legally safeguard open-source software. By 1990, the GNU Project possessed compilers (GCC), text editors, and system libraries, but lacked an open-source operating system kernel.

### The Birth of the Linux Kernel & Ecosystem Evolution

In 1991, 21-year-old Finnish student Linus Torvalds created a free operating system kernel for his Intel 80386 PC. On August 25, 1991, he publicly announced the project. Compiled using GNU GCC, the Linux kernel was combined with GNU tools by the global developer community. 

| Era | Key Milestones |
|---|---|
| **1992** | First Linux distributions released, pairing the Linux kernel with GNU utilities. |
| **1993** | 100+ global developers joined the project; major distributions like Debian launched. |
| **Late 1990s** | Enterprise hardware vendors (IBM, Dell, HP) officially adopted Linux compatibility. |
| **2000s** | Linux became the primary operating system architecture for global web servers. |
| **2010s–Present** | Dominates 70% of web servers, 90% of smartphones (Android/iOS Unix base), and 99% of supercomputers. Embedded in consoles (PlayStation), routers, and smart devices. |

---

# 2. Command Line Interface Fundamentals

### Command Structure & Execution Rules

A Command Line Interface (CLI) is a text-based interface used to interact with the operating system. Commands follow a standard structural syntax:

`command [options] [files_or_data]`

* **Command:** Executable program or system tool placed at the start of the line.
* **Options:** Modifies execution behavior. Single-letter flags use a single dash (e.g., `-j`), while full-word options use double dashes (e.g., `--help`). Short flags can be combined (e.g., `-la`).
* **Files/Data:** Input target acted upon by the command.

### Shell Prompt Symbols

> [!NOTE] Definition: Shell
> The **shell** is the command language interpreter program. It sits between the user and the operating system kernel: it reads the text input from the terminal, expands syntax (like wildcards `*` and `?`), requests the kernel to execute the commands, and displays the result back to the screen. Common examples include `sh` and `bash`.

| Symbol | Name | Description |
|---|---|---|
| `~` | Tilde | Represents the current user's **Home Directory** shortcut. |
| `$` | Dollar Sign | Indicates a **Standard User** privilege level. |
| `#` | Hash / Pound | Indicates a **Superuser (root)** administrator privilege level. |

### Command Execution Modes

| Mode | Characteristics | Examples |
|---|---|---|
| **Standard (Non-Interactive)** | Executes an action, outputs results to stdout, and immediately returns control to the prompt. | `whoami`, `date`, `echo` |
| **Interactive (Full-Screen)** | Occupies the entire terminal screen to provide a navigable workspace until explicitly closed. | `nano`, `vim`, `top`, `less` |

---

# 3. System Information & Basic Utilities

### System Identity & Diagnostics

| Command | Primary Function | Notes / Useful Flags |
|---|---|---|
| `whoami` | Displays current effective username. | Default WebLinux user: `user`. |
| `id` | Prints User ID (UID), Group ID (GID), and group memberships. | UID 1000 represents the standard user. |
| `logname` | Prints user login name. | Functions similarly to `whoami`. |
| `hostname` | Displays system network/DNS name. | Default WebLinux host: `openrisk`. |
| `uname` | Prints operating system name. | `-a` prints full kernel, architecture, and build data. |
| `uptime` | Displays system running time, current time, and CPU load. | Useful for system stability monitoring. |
| `echo $0` | Identifies active shell interpreter. | Returns `sh` or `bash`. |

### Terminal Control & Formatting Utilities

| Command | Description | Syntax Examples |
|---|---|---|
| `clear` | Clears terminal screen buffer. | `clear` |
| `history` | Lists previously executed commands. | Use Up/Down arrows to navigate history. |
| `echo` | Prints input text to terminal output. | `echo hello` |
| `cal` | Displays text calendar. | `cal -j` (displays Julian day count). |
| `date` | Displays or formats system date/time. | Uses `+` prefix with format specifiers. |

### Date Format Specifiers (`%`)

| Specifier | Component Output | Example Output |
|---|---|---|
| `%T` | Time in 24-hour format (`HH:MM:SS`) | `14:30:05` |
| `%A` | Full weekday name | `Thursday` |
| `%d` | Zero-padded day of the month (`01`–`31`) | `09` |
| `%B` | Full month name | `September` |
| `%Y` | 4-digit year | `2026` |

---

# 4. Interactive Applications & Control Shortcuts

### Interactive Text Editors & Tools

| Application | Primary Use | Exit Method |
|---|---|---|
| `man` | System manual pages viewer (disabled on WebLinux). | Press `q` |
| `top` | Real-time system process and resource monitor. | Press `q` or `Ctrl + C` |
| `htop` | Text-graphical interactive process manager. | Press `F10` (or `Fn + F10`), `q`, or `Ctrl + C` |
| `nano` | Basic text editor with on-screen menu. | Press `Ctrl + X` |
| `vim` | Advanced modal text editor. | Press `Esc`, type `:q!` (quit) or `:wq` (save & quit) |

### Terminal Control Signals (Caret Notation `^`)

| Shortcut | Signal Code | Action Performed |
|---|---|---|
| `Ctrl + C` (`^C`) | `SIGINT` | Interrupts and terminates the currently running process. |
| `Ctrl + D` (`^D`) | `EOT` / `EOF` | End-of-File signal; exits session or closes input streams. |
| `Ctrl + Z` (`^Z`) | `SIGTSTP` | Suspends active process and places it into the background. |
| `Ctrl + L` (`^L`) | Form Feed | Redrafts prompt and clears visible screen (matches `clear`). |
| `Ctrl + U` | Line Clear | Erases text from cursor to beginning of the line. |
| `Ctrl + K` | Line Clear | Erases text from cursor to end of the line. |

### Visuals & Terminal Games

| Utility | Type | Description | Exit Shortcut |
|---|---|---|---|
| `hello` | Text | Prints basic greeting string. | Automatic |
| `worm` / `firework` / `rain` | Visuals | ASCII graphic animations. | `Ctrl + C` or `q` |
| `hanoi` | Game | Tower of Hanoi disk logic puzzle. | `q` |
| `knight` | Game | Chess knight movement puzzle. | `q` or `x` |

---

# 5. Linux File System Architecture & Navigation

### Core File System Structure

The Linux file system is organized as a single inverted tree hierarchy starting from the root directory (`/`). The Filesystem Hierarchy Standard (FHS) governs directory organization across distributions.

| Directory | Name / Acronym | Functional Purpose |
|---|---|---|
| `/` | Root | Top-level parent directory of the entire file system. |
| `/bin` | Binaries | Essential user commands required across all access modes (`ls`, `cp`). |
| `/sbin` | System Binaries | Administrative executables reserved for root/superuser. |
| `/home` | Home | User personal workspaces (e.g., `/home/username/`). |
| `/root` | Root Home | Isolated home workspace for system administrator account. |
| `/etc` | Configuration | System-wide editable text configuration files. |
| `/lib` | Libraries | Shared code libraries required by `/bin` and `/sbin` executables. |
| `/tmp` | Temporary | Temporary storage area wiped automatically upon system reboot. |
| `/var` | Variable Data | Dynamic operational files (logs in `/var/log`, mail, spool queues). |
| `/usr` | Unix Resources | Secondary hierarchy for non-essential software applications (`/usr/bin`). |
| `/dev` | Devices | Virtual device nodes representing hardware (*Everything is a file*). |

### Navigation Utilities & Syntax

| Command / Symbol | Operation | Description / Usage |
|---|---|---|
| `pwd` | Print Working Directory | Outputs current absolute path location. |
| `ls` | List Directory | Lists files/folders (`-a` shows hidden files starting with `.`, `-la` shows long detail). |
| `cd` | Change Directory | Navigates path locations (`cd` alone jumps to `~`, `cd /` moves to root). |
| `.` | Current Directory | Reference pointer to current location. |
| `..` | Parent Directory | Reference pointer to directory one level up (chainable: `cd ../..`). |
| `~` | Home Directory | Shortcut path to active user workspace. |

### Absolute vs. Relative Paths

* **Absolute Path:** Begins with a leading root slash `/`. Defines exact file location from top of system hierarchy regardless of current location (e.g., `cd /home/user/sys`).
* **Relative Path:** Does **not** begin with a leading slash `/`. Evaluates target path relative to current working directory location (e.g., `cd sys` or `cd ..`).

**Examples:**

* `pwd` (Prints current absolute directory path)
* `ls -la /var/log` (Displays detailed list of log directory including hidden files)
* `cd ../etc` (Navigates to the /etc directory relative to current location)

---

# 6. File Types & Inspection Utilities

### System Inspection Tools

| Tool | Primary Purpose | Usage Example |
|---|---|---|
| `file <name>` | Inspects file header to determine file format or encoding. | Identifies ASCII text, directories, ELF binaries, or symlinks. |
| `realpath <target>` | Resolves symbolic links to display canonical absolute path. | Traces link pointer directly to source target location. |
| `which <command>` | Displays executable binary path assigned to system commands. | `which cat` returns `/bin/cat`. |

### File Types & BusyBox Architecture

* **Text / Source Files:** Plain text files encoded in formats such as ASCII.
* **Directory:** Structural file system folder container.
* **Symbolic Link:** Shortcut reference pointing directly to another file or path location.
* **ELF Executable:** Compiled architecture-specific binary executable.
* **BusyBox Unified Architecture:** In storage-constrained environments (like WebLinux), system utilities are consolidated into a single binary (`/bin/busybox`). Utilities like `/bin/cat` exist as symbolic links pointing directly to `/bin/busybox`.

**Examples:**

* `file /bin/cat` (Inspects target to verify if it is an ELF executable or symbolic link)
* `which nano` (Displays executable location for nano text editor)
* `realpath /bin/cat` (Resolves symbolic link to reveal origin binary target)

---

# 7. File Reading, Writing & Redirection

### File Creation & Escaping Rules

Empty files are created or timestamp-updated using `touch <filename>`. Filenames containing spaces must handle argument splitting using escape backslashes (`touch my\ file.txt`) or single quotes (`touch 'my file.txt'`). Using underscores (`my_file.txt`) is standard best practice. Unclosed quotes trap the shell in a secondary prompt (`>`); exit by typing the matching closing quote, pressing `Ctrl + D`, or using `Ctrl + C`.

### Output Redirection & Piping

| Operator / Command | Function | Description |
|---|---|---|
| `>` | Overwrite Redirection | Redirects output to file, creating it or overwriting existing content. |
| `>>` | Append Redirection | Redirects output to file, appending content to end of file. |
| `cat > file.txt` | Direct Terminal Input | Accepts terminal text input into file until `Ctrl + D` (`^D`) is sent. |
| `\|` | Pipeline | Passes stdout of left command as stdin to right command. |

### Interactive Paging (`less`)

| Function | Shortcuts / Flags | Description |
|---|---|---|
| **Navigation** | `j` / `k` (or Down/Up), `Space` / `b`, `g` / `G` | Move by line, move by page, jump to top / bottom. |
| **Search** | `/pattern` (forward), `?pattern` (backward) | Search text (`n` moves to next match, `N` to previous). |
| **Flags** | `-N` (line numbers), `-M` (status & percentage) | Toggles view status parameters. Exit with `q`. |

**Examples:**

* `touch 'new file.txt'` (Creates a file containing spaces using single quotes)
* `echo "data" >> notes.txt` (Appends text to file end without overwriting existing data)
* `less -NM /etc/services` (Opens services file displaying line numbers and progress percentage)

---

# 8. Directory & File Management

### Command Operations Table

| Command | Action | Key Options | Usage Notes |
|---|---|---|---|
| `mkdir` | Create Directory | `-p` | `-p` creates nested parent directories recursively. |
| `rm` | Remove File/Directory | `-r`, `-i` | `-r` enables recursive directory deletion; `-i` prompts for confirmation before removal. |
| `mv` | Move / Rename | `-i`, `-n` | Renames files within path or moves locations. `-i` prompts before overwriting; `-n` prevents overwrites. |
| `cp` | Copy File/Directory | `-r`, `-i` | `-r` recursively copies directory contents; `-i` prompts before file overwrites. |

**Examples:**

* `mkdir -p projects/2026/notes` (Creates nested directory structure recursively in a single command)
* `rm -ri test_folder/` (Recursively deletes folder while asking confirmation for each item)
* `mv -i file1.txt file2.txt` (Renames file1.txt to file2.txt, prompting if file2.txt already exists)
* `cp -r -i folder1/ folder2/` (Recursively copies folder1 into folder2 with interactive overwrite prompt)

---

# 9. File Searching Methods

### Search Mechanisms Overview

* **`locate`:** Queries a pre-built indexed database for fast file searches. Refreshed manually via `updatedb`. Excluded on lightweight environments like WebLinux.
* **`echo` Expansion:** Uses shell globbing wildcard stars (`*`) to match variable characters or question marks (`?`) to match single-character placeholders.
* **`find` System Search:** Recursively traverses directory paths directly. Double quotes around search patterns prevent premature shell expansion.

### `find` Options & Redirection

| Search Parameters | Purpose | Example Syntax |
|---|---|---|
| `-name` | Exact case-sensitive filename search. | `find /home -name "notes.txt"` |
| `-iname` | Case-insensitive filename search. | `find . -iname "readme.md"` |
| `-ipath` | Case-insensitive path search. | `find /usr -ipath "*src/mail*"` |
| `2> /dev/null` | Discards permission denied error streams. | `find / -name "config.sys" 2> /dev/null` |
**Standard Streams** 

In Linux, every process automatically opens 3 numbered communication channels:

 **`0` = `stdin`** (Standard Input): data input (by default, the keyboard).
 **`1` = `stdout`** (Standard Output): standard data output (by default, the terminal).
 **`2` = `stderr`** (Standard Error): output reserved for error messages.

The `2>` symbol redirects only stream number 2 (errors).

**Examples:**

* `echo *.txt` (Lists all files with .txt extension in the current directory using shell expansion)
* `find / -name "config.sys" 2> /dev/null` (Searches entire file system for config.sys while discarding access permission errors)
* `find . -iname "readme.md"` (Searches current directory for readme.md ignoring case differences)
* `find /usr -ipath "*src/mail*" | less` (Searches path matching target pattern case-insensitively and pipes results to less)

---

# 10. C Program Compilation with GCC

In C, source code written in human-readable files must be converted into machine language before execution. This translation is handled by a **compiler**.

### Compilation vs. Interpretation

| Feature | Compiler (e.g., `gcc`) | Interpreter (e.g., `python`, `bash`) |
|---|---|---|
| **Translation** | Whole program translated all at once in advance | Line by line during execution |
| **Execution Speed** | Very fast (pre-translated binary) | Slower (overhead from live translation) |
| **Startup Time** | Requires initial compilation step | Starts executing immediately |
| **Debugging** | Catches syntax errors before running | Finds errors only when reaching that line |
| **Primary Use Cases** | System programming, high-performance apps, C/C++ | Scripting, rapid prototyping, Web (JavaScript) |

* **Interpreter** (`Inter` = *between*): Sits continuously between the code and the computer, translating each line as it runs.
* **Compiler** (`Compile` = *to pile together*): Piles together the entire program and converts it into a single executable file.

### What is GCC?

**GCC** (**GNU Compiler Collection**) is the default compiler toolset for Linux and Unix-like operating systems. Its primary role is to convert human-readable source code (such as C files) into binary machine code that the processor can execute.

* **Origin:** Originally created in 1987 by Richard Stallman as the *GNU C Compiler*, it later expanded to support multiple programming languages (C, C++, Fortran, Go).
* **Compilation Pipeline:** Automatically handles all four main build stages: **Preprocessing** -> **Compiling** (to Assembly) -> **Assembling** (to Machine Code) -> **Linking**.
* **Role in C Development:** It is the primary tool used in Linux terminals to turn `.c` source files into executable binaries like `a.out` or custom-named programs.

### Basic GCC Compilation Commands

| Command | Description |
|---|---|
| `gcc program.c` | Compiles `program.c` and outputs the default executable named `a.out`. |
| `./a.out` | Executes the compiled output file in the current directory. |
| `gcc program.c -o program` | Compiles `program.c` and names the output executable `program`. |
| `./program` | Executes the custom-named compiled program. |

---

# 11. Compiling and Executing C Programs on WebLinux

WebLinux automates compilation and execution through two editable command lines at the bottom of the Code Editor.

### Build and Run Workflow

1. **Build Command (Compilation):**
   `gcc program.c -o program`
   * `gcc`: Invokes the GNU C Compiler.
   * `program.c`: The input C source file.
   * `-o program`: Specifies the output binary name (`-o` stands for output).

2. **Execution Command:**
   `./program`
   * `./`: Refers to the current working directory.
   * `program`: The name of the binary file to execute.

* **WebLinux "Run It" Button:** Automatically saves the open file, executes the Build Command to compile the `.c` file into a binary, clears the screen, and runs the Execution Command.

### GCC Compiler Flags

Compiler flags give precise control over how `gcc` analyzes and translates C code.

| Flag | Purpose |
|---|---|
| `-o <filename>` | **Output:** Specifies the name of the output binary (`-o` = output). |
| `-std=c11` | **Language Standard:** Sets the C standard version (e.g., C11). |
| `-Wall` | **Warnings All:** Enables the primary suite of compiler warnings. |
| `-Wextra` | **Extra Warnings:** Enables additional strict safety and quality checks. |
| `-fmax-errors=10` | **Error Limit:** Caps terminal error output to 10 lines to prevent clutter. |

**Full Compilation Command Example:**

`gcc -std=c11 -Wall -Wextra -fmax-errors=10 program.c -o program`

### Working with Multiple C Files

When working with a new file (e.g., `otherprogram.c`), WebLinux does **not** automatically update the build/exec inputs. You must manually adjust them:

* **Build command:** `gcc -std=c11 -Wall -Wextra -fmax-errors=10 otherprogram.c -o otherprogram` (**`-o prog`**: definisce il nome dell'output binario (otherprogram).)
* **Execution command:** `./otherprogram`

### Verifying File Types with `file`

You can verify the file types in the terminal using the `file` command:

* `file program.c` -> Output: `C source, ASCII text`
* `file program` -> Output: `ELF executable` (binary file for the system architecture)

---

# 12. Computer Memory Architecture & Addressing

### Memory Classification: RAM vs. Non-Volatile Storage

The operating system manages hardware memory, which is divided into two primary storage categories based on speed, access mode, and data persistence.

| Memory Type | Primary Purpose | Characteristics | Examples |
|---|---|---|---|
| **RAM (Volatile Memory)** | Executes active programs and holds runtime variable values. | Fast, temporary storage wiped when power is turned off. | Random Access Memory modules |
| **Non-Volatile Storage** | Long-term data retention for files and software binaries. | Slower than RAM, persistent storage surviving reboot cycles. | Hard Drives (HDD), Solid-State Drives (SSD) |

---

### Memory Hierarchy Units: Bits, Bytes, and Words

At the physical hardware level, memory is structured in hierarchical binary grouping units:

* **Bit:** The smallest fundamental cell of computer memory, holding a binary value of `0` or `1`.
* **Byte:** A standardized group of 8 bits (1 Byte = 8 bits).
* **Word:** The fundamental unit of data transferred simultaneously between RAM and the CPU processor. A word is formed by grouping multiple memory cells together.

> [!NOTE] Common Word Sizes
> Modern hardware architecture uses standard word lengths dictated by processor design, typically **8-bit**, **16-bit**, **32-bit**, or **64-bit**.

---

### Memory Addressing & Low-Level C Access

To store and retrieve variable values efficiently, the operating system assigns a unique numerical **memory address** (a whole number) to each word in RAM.

#### Addressing Mechanism Example

In a simplified 8-bit architecture system with a total capacity of 4 words:
* **Address 0:** Points to the 1st word (first 8 memory cells)
* **Address 1:** Points to the 2nd word (next 8 memory cells)
* **Address 2:** Points to the 3rd word (next 8 memory cells)
* **Address 3:** Points to the 4th word (next 8 memory cells)

#### Low-Level Access in C

Unlike high-level interpreted languages, the C programming language allows direct retrieval and manipulation of these exact memory locations during program execution:

* **Direct Memory Control:** Allows programs to obtain the exact memory address where a variable's value resides.
* **Performance & Optimization:** Enables fine-grained control over hardware memory allocation, traversal, and execution speed.

---

### (extra) Memory Management: C vs. High-Level Languages

Unlike C, which provides direct access to physical memory addresses via pointers, high-level languages like Java and Python hide raw memory behind a managed runtime environment (a **Virtual Machine** or Interpreter). These environments handle memory allocation and automatic garbage collection on behalf of the developer, **sacrificing low-level hardware control to eliminate memory corruption bugs** and ensure system safety.

---

---

### (extra) 32-Bit vs. 64-Bit Architecture & Word Size

The processor's native word size (typically 32-bit or 64-bit) dictates how much data the CPU can process in a single cycle and how much RAM it can address:

* **RAM Addressing Limits:** A 32-bit architecture supports up to $2^{32}$ unique memory addresses (capping usable RAM at 4 GB), while a 64-bit architecture supports up to $2^{64}$ addresses (up to 16 Exabytes of RAM).
* **Data Processing Efficiency:** A 64-bit CPU reads and manipulates 64-bit data blocks in a single hardware operation, avoiding the need to split large instructions into multiple 32-bit passes.
* **C Pointer Size:** Because memory addresses are longer in 64-bit systems, memory pointers in C expand from 4 Bytes (32 bits) on a 32-bit system to 8 Bytes (64 bits) on a 64-bit system.

---

# 13. System Memory Monitoring Utilities

### Overview: Monitoring vs. Managing RAM

Checking system memory involves inspecting both overall hardware capacity and individual per-process consumption. Commands like `free`, `top`, and `htop` provide real-time diagnostics to detect memory bottlenecks and identify resource-heavy processes before taking administrative action (such as killing a process).

---

### System-Wide Memory Inspection: `free`

The `free` utility displays a quick summary of total, used, and available system RAM.

| Option Flag | Output Measurement Unit | Usage Example |
|---|---|---|
| `-b` | Bytes | `free -b` |
| `-k` | Kilobytes (default) | `free -k` |
| `-m` | Megabytes | `free -m` |
| `-g` | Gigabytes | `free -g` |

* **Main Output Fields:**
  * **Total:** Physical RAM installed on the machine.
  * **Used:** Memory currently consumed by running processes and the system.
  * **Free:** Unallocated RAM immediately available for new tasks.

---

### Interactive Memory Diagnostics: `top`

The `top` utility provides a real-time, interactive process monitor. The system summary header displays total used and free memory in Kilobytes.

#### Memory Key Metrics & Shortcuts

* **`VSZ` / `VIRT` (Virtual Size):** Represents the total virtual memory allocated to a specific process (including shared libraries and mapped files).
* **`M` Key:** Sorts the running process list in descending order by memory usage (`VSZ`).
* **`S` Key:** Toggles a dedicated memory-focused display layout.
* **`q` Key:** Exits the application back to the shell prompt.

---

### Visual Process Management: `htop`

`htop` offers an interactive, visual representation of memory usage, featuring graphical progress bars for active vs. total RAM at the top of the interface.

#### Sorting Processes by Memory Usage in `htop`

1. Press **`F6`** (or **`Fn + F6`**) to open the bottom **Sort by** side menu.
2. Use the arrow keys to scroll down and select **`M_SIZE`** (Memory Size).
3. Press **`Enter`** to confirm.
4. Processes are now ordered dynamically by the **`VIRT`** (Virtual Memory) column from highest to lowest consumer.

---

# 14. Memory Inspection & Allocation in C

### Process Execution & Input Pausing (`scanf`)

To observe a running C program's footprint in system diagnostics (`htop`), the process must remain active in RAM. 

* **Execution Holding:** Using `scanf("%c", &c)` pauses program execution while waiting for user keyboard input.
* **Address-Of Operator (`&`):** Tells `scanf` the exact RAM memory location (address) of variable `c` where the input character should be stored.

``` c
#include <stdio.h>

int main() {
    char c;
    printf("Hello world!\n");
    printf("Please press a key to exit the program.\n");
    scanf("%c",&c);
    return 0;
}
```

* **Standard Headers:**
  * `<stdio.h>`: Standard I/O library containing functions like `printf` and `scanf`.
  * `<stdlib.h>`: Utility library containing dynamic memory management functions like `malloc()` and `free()`.

*La funzione **scanf** fa parte della libreria standard di C. Nel CS-50 abbiamo usato una libreria con funzioni semplificate per gli input da tastiera: get_int, get_string...*

---

### Virtual Memory (`VIRT`) Scaling by Data Type

Declaring large arrays increases the allocated **Virtual Memory (`VIRT`)**, with the memory footprint scaling directly according to the byte size of the underlying data type:

| Data Type               | Single Element Size | 1,000,000 Element Array Size | Observed `VIRT` Footprint |
| ----------------------- | ------------------- | ---------------------------- | ------------------------- |
| **Baseline (No array)** | N/A                 | N/A                          | ~952 KB                   |
| `char`                  | 1 Byte              | ~1 MB                        | ~1,800 KB (~1.8 MB)       |
| `int`                   | 4 Bytes             | ~4 MB                        | ~4,728 KB (~4.7 MB)       |
| `double`                | 8 Bytes             | ~8 MB                        | ~8,632 KB (~8.6 MB)       |

---

### Virtual Memory vs. Physical RAM Allocation

The Linux kernel decouples memory reservation from physical hardware allocation:

* **Lazy Allocation / Overcommit:** Declaring an uninitialized array reserves address space in Virtual Memory (`VIRT`), but **does not** immediately consume physical RAM (`RES`).
* **Physical RAM Usage:** Physical memory is only assigned when the program actively reads or writes data to those allocated memory cells.
* **Diagnostic Behavior:** In system monitors (`htop`), `VIRT` increases instantly with large array declarations, while physical RAM usage remains flat (e.g., staying at 2 MB out of 25 MB) until the array is actively accessed.

---

### Best Practices & Memory Management

1. **Avoid Unused Allocations:** Compilers emit warnings when large arrays are reserved but never accessed in code.
2. **Dynamic Memory Cleanup:** When allocating dynamic memory via `malloc()`, always release it using `free()` when no longer needed to prevent memory leaks and keep RAM available for other processes.

---

# Terminal Shortcut & Signals

| Combinazione | Codice ASCII | Nome Carattere | Funzione in Shell / Terminale |
| :--- | :--- | :--- | :--- |
| **`Ctrl + A`** | ASCII 1 (0x01) | **SOH** (Start of Header) | Sposta il cursore all'inizio della riga. |
| **`Ctrl + B`** | ASCII 2 (0x02) | **STX** (Start of Text) | Sposta il cursore indietro di un carattere (equivalente a $\leftarrow$). |
| **`Ctrl + C`** | ASCII 3 (0x03) | **ETX** (End of Text) | Invia `SIGINT`: interrompe e uccide il processo in corso. |
| **`Ctrl + D`** | ASCII 4 (0x04) | **EOT** (End of Transmission) | Invia `EOF`: segnala la fine dell'input o chiude la shell. |
| **`Ctrl + E`** | ASCII 5 (0x05) | **ENQ** (Enquiry) | Sposta il cursore alla fine della riga. |
| **`Ctrl + F`** | ASCII 6 (0x06) | **ACK** (Acknowledge) | Sposta il cursore avanti di un carattere (equivalente a $\rightarrow$). |
| **`Ctrl + G`** | ASCII 7 (0x07) | **BEL** (Bell) | Annulla la ricerca corrente o l'operazione di autocompletamento. |
| **`Ctrl + H`** | ASCII 8 (0x08) | **BS** (Backspace) | Cancella il carattere prima del cursore. |
| **`Ctrl + I`** | ASCII 9 (0x09) | **HT** (Horizontal Tab) | Autocompletamento di comandi e percorsi (equivalente a `Tab`). |
| **`Ctrl + J`** | ASCII 10 (0x0A) | **LF** (Line Feed) | Invio/Nuova riga (equivalente a `Enter`). |
| **`Ctrl + K`** | ASCII 11 (0x0B) | **VT** (Vertical Tab) | Cancella dal cursore fino alla fine della riga. |
| **`Ctrl + L`** | ASCII 12 (0x0C) | **FF** (Form Feed) | Pulisce lo schermo mantenendo la riga attuale (equivale a `clear`). |
| **`Ctrl + M`** | ASCII 13 (0x0D) | **CR** (Carriage Return) | Esegue il comando (equivalente a `Enter`). |
| **`Ctrl + N`** | ASCII 14 (0x0E) | **SO** (Shift Out) | Passa al comando successivo nella cronologia (equivalente a $\downarrow$). |
| **`Ctrl + O`** | ASCII 15 (0x0F) | **SI** (Shift In) | Esegue il comando corrente e carica il successivo dalla cronologia. |
| **`Ctrl + P`** | ASCII 16 (0x10) | **DLE** (Data Link Escape) | Passa al comando precedente nella cronologia (equivalente a $\uparrow$). |
| **`Ctrl + Q`** | ASCII 17 (0x11) | **DC1** (Device Control 1 / XON) | Ripristina l'output del terminale dopo un `Ctrl + S`. |
| **`Ctrl + R`** | ASCII 18 (0x12) | **DC2** (Device Control 2) | Avvia la ricerca inversa nella cronologia dei comandi (*reverse-i-search*). |
| **`Ctrl + S`** | ASCII 19 (0x13) | **DC3** (Device Control 3 / XOFF) | Congela l'output a schermo del terminale. |
| **`Ctrl + T`** | ASCII 20 (0x14) | **DC4** (Device Control 4) | Scambia il carattere sotto il cursore con quello precedente. |
| **`Ctrl + U`** | ASCII 21 (0x15) | **NAK** (Negative Acknowledge) | Cancella dal cursore fino all'inizio della riga. |
| **`Ctrl + V`** | ASCII 22 (0x16) | **SYN** (Synchronous Idle) | Permette di inserire letteralmente il carattere speciale successivo. |
| **`Ctrl + W`** | ASCII 23 (0x17) | **ETB** (End of Transmission Block) | Cancella la parola a sinistra del cursore. |
| **`Ctrl + X`** | ASCII 24 (0x18) | **CAN** (Cancel) | Prefisso per scorciatoie composte (es. `Ctrl + X` poi `Ctrl + E` apre l'editor). |
| **`Ctrl + Y`** | ASCII 25 (0x19) | **EM** (End of Medium) | Incolla l'ultimo elemento cancellato (*yank*). |
| **`Ctrl + Z`** | ASCII 26 (0x1A) | **SUB** (Substitute) | Invia `SIGTSTP`: sospende il processo e lo mette in pausa in background. |

---

# 15. C I/O Buffering, Input Redirection, and String Handling

## Standard Output Buffering & fflush

### Line Buffering Mechanism

By default, output sent to standard output (`stdout`) via `printf` is line-buffered on interactive terminals. Characters are kept in a temporary RAM buffer and printed only when:
- A newline character (`\n`) is encountered.
- The buffer fills up completely.
- The program exits normally.

### Flushing output with fflush(stdout)

If a prompt printed with `printf` does not end with a `\n`, the output might remain trapped in the buffer while the program waits for user input. To force the buffer to print immediately without adding a newline, use:

  printf("Enter name: ");
  fflush(stdout);
  scanf("%s", name);

Note: Buffering behavior can vary across different operating systems and C standard library implementations.

---

## Input Redirection and Piping

### Terminal Input Files (Ctrl + D)

You can create a plain text file directly from stdin using `cat`:
1. Execute `cat > answers.txt`
2. Enter values line by line.
3. Send `Ctrl + D` (EOF / End of Transmission) to signal completion.

### Injecting Input into Programs

To pass pre-written inputs into an interactive executable without manual typing:

- File Redirection (<): Directs a file's content into stdin.
  ./program < answers.txt

- Piping (|): Directs the output of another command into stdin.
  cat answers.txt | ./program

---

## Limits of scanf and Safer Alternatives

### The scanf("%s") Issue

Using `scanf("%s", ...)` for reading strings is problematic because:
1. It splits input on any whitespace (spaces, tabs, newlines). Typing multiple words separated by spaces feeds subsequent `scanf` calls immediately.
2. It does not perform bounds checking by default, risking buffer overflows.

### Safe Alternatives for String Input

1. fgets(buffer, size, stdin)
   - Standard C function (fully portable).
   - Reads up to `size - 1` characters, preserving spaces.
   - Retains the trailing `\n` in the buffer (requires manual removal).

2. getline(&buffer, &size, stdin)
   - POSIX standard function.
   - Dynamically allocates and resizes memory as needed to fit the line.
   - Retains the trailing `\n`.

3. readline(prompt)
   - GNU Readline library function (Linux-focused).
   - Provides line-editing features and history navigation.
   - Strips the trailing `\n` automatically.