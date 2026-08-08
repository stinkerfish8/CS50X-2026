---

---
---

# 🐧 Linux & Command Line Interface (CLI)
# History of the Linux Operating System

### The Rise of Unix and the GNU Project
* By the early 1980s, the Unix operating system was widely adopted by universities, research centers, startups, and companies.
* In 1983, Unix inventors Dennis Ritchie and Ken Thompson received the Turing Award.
* In the same year, Richard Stallman of MIT launched the GNU Project, a collaborative project to develop free and open software compatible with Unix.
* Unlike Unix, which was owned by Bell Labs and required paid licenses, the GNU Project was free for anyone to use and modify.
* In 1989, Stallman created the GNU General Public License (GPL) to legally preserve the freedom to use, study, modify, and distribute software.
* By 1990, the GNU Project possessed an extensive collection of software, including text editors, a graphical user interface, libraries, and the GNU C Compiler (GCC). However, users still had to run this free software on top of a proprietary, paid Unix operating system.

---

### The Birth of the Linux Kernel
* In 1991, Linus Torvalds, a 21-year-old Finnish computer science student at the University of Helsinki, became frustrated by proprietary operating system licenses.
* On August 25, 1991, he announced to the community that he was working on a free operating system as a hobby.
* This project became the Linux kernel. It was written specifically to run on Torvalds' PC (utilizing an 80386 processor) and was compiled using the GNU C Compiler (GCC), which remains the primary compiler for Linux today.
* The community quickly integrated the free GNU software tools with the free Linux kernel.

---

### Distribution and Commercial Adoption
* In 1992, the first Linux distributions were released, combining the free Linux operating system kernel with the GNU Project's software collection (editors, libraries, compilers).
* By 1993, more than 100 global developers were actively modifying and improving Linux. This year also marked the launch of highly popular distributions, such as Debian.
* By the end of the 1990s, major hardware manufacturers like Dell, IBM, and HP officially announced compatibility of their hardware with Linux.
* During the 2000s, Linux was increasingly deployed as the primary operating system running web servers.

---

### Modern Dominance (2010s and Beyond)
* In the 2010s, Linux and Unix-based operating systems became the most widely used systems globally:
  * **Internet Servers:** Powered around 70% of the market share.
  * **Smartphones:** Powered around 90% of the market share, with Android being based on Linux and iOS being based on Unix.
  * **Supercomputers:** Dominated around 99% of the market share, serving scientific calculations and the film/special effects industries.
* Today, Linux and Unix derivatives are embedded across everyday technologies, including PlayStation game consoles, internet boxes, Wi-Fi routers, and smart connected devices.
---
# CLI & Command Line Basics

### What is a Command Line Interface (CLI)
* A **CLI** (Command Line Interface) is a text-based human-machine interface that enables communication between the user and the computer.
* **The user types a command using the keyboard to request that the computer perform an operation.**
* The computer responds by displaying text representing the execution result, or by asking the user questions if the application requires further input.
* The CLI is used both for fundamental interaction with the operating system and to launch and execute various software applications.

---

### The Command Prompt
* When the command line is ready to receive input, it displays the **command prompt**.
* The prompt displays useful information at the beginning of the line, such as the user account name, the computer name, the current working directory, or the date.
* The prompt always ends with a specific character signaling that the system is ready to receive commands. The most common are the dollar sign (`$`), the pound/hash sign (`#`), or the greater-than sign (`>`).

### Linux Prompt Symbols: `~` and `$`

In the command-line prompt (e.g., `~$` ), these two symbols represent the **current directory** and the **user privilege level**:

- **Tilde (`~`)**: Represents the current working directory. The tilde is the system shortcut for the user's **Home Directory**. If you navigate to a different directory, this symbol is replaced by the path of that current folder.
    
- **Dollar sign (`$`)**: Indicates that the terminal is ready for input and running under **Standard User** privileges.
    
    - _Note_: If you are operating as the system administrator (`root`), the `$` symbol is replaced by `#`.

---

### Unix & Linux Heritage
* A fundamental feature of the Unix operating system, inherited by Linux, is the presence of more than 100 software applications since its early beginnings.
* These programs perform very simple, targeted tasks, and they are all designed to be used directly from the command line.

---

### Anatomy of a Command
Elementary commands follow a standard structure where options and files or data are optional:

$$\text{command} \quad [\text{options}] \quad [\text{files\_or\_data}]$$

* **Command:** Positioned at the very beginning of the line, this is almost always the name of the software application to execute. It can be an operating system command or a program written by the user, often in the C programming language.
* **Option:** Modifies the behavior and execution of the command. It immediately follows the command name and is separated by spaces. The specific effect of an option depends entirely on the command being used.
* **Files or Data:** Represent the inputs or data upon which the program will operate.

---

### Practical Example: The `cal` Command
* Typing the `cal` command and pressing Enter executes the application that displays the calendar for the current month in text mode.
* Adding the `-j` option (typing `cal -j`) modifies the output to display the calendar in Julian days, representing the number of days elapsed since January 1st.
---
# Basic CLI Commands & Navigation

### The Command Prompt & The Shell
* In WebLinux, the command prompt is represented by ` ~ $ ` followed by a blinking cursor, signaling that the system is ready for user input.
* When the user presses Enter, the **shell (command interpreter)** processes the command and displays the output on the terminal.
* Running `echo $0` displays the name of the **active shell interpreter** (e.g., `sh` for shell). The shell is the application that reads lines, interprets them, and requests the system to execute the corresponding operations.

---

### User Identification & Verification
* `whoami`: Prints the username associated with the current effective user ID (on the WebLinux environment, the default user is `user`).
* `id`: Displays specific identification details, including the User ID (UID), Group ID (GID), and associated groups (e.g., UID 1000 for the default user).
* `logname`: Outputs the login name of the current user, functioning similarly to `whoami`.
* On standard Linux systems, users must authenticate with a username and password. Linux is natively multi-user, meaning different users can coexist with unique passwords and isolated home directories.

---

### System Information & Status
* `hostname`: Retrieves or sets the system's network name or DNS domain name (defaults to `openrisk` on WebLinux).
* `uname`: Prints basic system information (e.g., "Linux").
  * **Option `-a`:** Running `uname -a` prints all system information, including the system name, hostname, kernel release version, build date, and architecture.
* `uptime`: Displays how long the system has been running, the current time, and CPU load averages.

---

### Terminal Navigation & History
* `history`: Outputs a list of previously executed commands in the current session.
* **Navigation Arrows:** Users can scroll backward through command history using the **Up Arrow** and forward using the **Down Arrow**.
* `clear`: Clears the screen of all previous commands and outputs, returning the prompt to the top of the terminal.

---

### Basic Output & Utility Commands
* `echo`: Prints the text argument passed to it directly onto the screen (e.g., `echo hello` outputs `hello`).
* `cal`: Displays a text-based calendar of the current month.
  * **Option `-j`:** Running `cal -j` displays the calendar using Julian days (counting sequentially from January 1st).
* `date`: Prints the current system date and time. It supports custom formatters to display specific segments of time:
  * `date +"%T"`: Formats and displays only the current time.
  * `date +"%A %d %B %Y"`: Formats and displays the full day name, day number, month name, and year (e.g., "Thursday 13 September 2018").

---

### Getting Help & System Documentation
* **`--help` Option:** Appending `--help` after almost any command (e.g., `whoami --help`) displays basic usage guidelines, syntax, and available options directly in the terminal.
* **`man` Command:** On standard Linux installations, typing `man` followed by a command name (e.g., `man cal`) opens the complete reference manual for that utility. 
  * Running `man man` opens the manual for the manual page viewer itself.
  * To exit a manual page and return to the command prompt, the user must press the **Q** key.
  * *Note:* The `man` tool is disabled on WebLinux to save storage space. An alternative is searching the web for "man [command] Linux".

# Linux Basic Commands Reference

``` bash
whoami
whoami --help
id
logname
echo hello
echo $0 # Ti dice quale shell stai usando, per esempio sh. è il software che interpreta i tuoi comandi in Linux
hostname
uname
uname -a
history  # Use UP ARROW to navigate history
clear
uptime
cal
cal --help
cal -j
date
date +"%T"
date +"%A %d %B %Y"
man
```

> [!NOTE] Date Format Specifiers (`%`)
> When using the `date` command in Linux, formatting strings start with a `+` sign. Inside the string, the `%` symbol acts as a **placeholder** (or format specifier) that gets replaced by a specific component of the current date or time:
> 
> * `%T` Time in 24-hour format (`HH:MM:SS`)
> * `%A` Full weekday name (e.g., `Thursday`)
> * `%d` Day of the month, zero-padded (`01`–`31`)
> * `%B` Full month name (e.g., `September`)
> * `%Y` Full 4-digit year (e.g., `2018`)
> 
> *Note: Format specifiers are case-sensitive

> [!NOTE] Linux Command Options: `--help` vs `man` and Flag Syntax
> 
> ### Documentation Tools
> * **`man <command>`** — Opens an interactive, full-page manual. Best for detailed study and offline reference. (Press `q` to exit).
> * **`<command> --help`** — Prints a quick summary of options directly in the terminal and exits immediately.
> 
> ### Flag Syntax Rules
> Options modify how a command behaves. The number of dashes indicates the option format:
> 
> * **Single Dash (`-`)** — Used for **single-letter** flags (e.g., `-h`, `-l`). Multiple short flags can often be combined (e.g., `-la`).
> * **Double Dash (`--`)** — Used for **full-word** options (e.g., `--help`, `--version`). 
> 
> *Caution: Using a single dash with a full word like `-help` may cause the terminal to interpret it as a cluster of individual flags (`-h -e -l -p`), leading to errors.*

> [!NOTE] Command Execution Modes
> * **Standard / Non-Interactive Commands:** Execute a specific action, print the result directly into the terminal output stream, and immediately yield control back to the prompt (e.g., `whoami`, `date`, `echo`).
> * **Interactive / Full-Screen Applications:** Take over the entire terminal interface to provide a navigable workspace, temporarily hiding the prompt until explicitly closed with an exit shortcut (e.g., `man` via the `q` key).


# Interactive CLI Commands & How to Exit Them

Some terminal commands launch interactive programs that do not immediately return to the shell prompt. You must explicitly exit these applications to regain control of the command line.

---

## 1. Common Interactive Commands

| Command | Description | How to Exit |
| :--- | :--- | :--- |
| `top` | Displays real-time system processes and CPU/memory usage. | Press `q` or `Ctrl + C`. |
| `htop` | Advanced, text-graphical process viewer. | Press `F10` (or `Fn + F10`), `q`, or `Ctrl + C`. |
| `nano` | Basic, user-friendly text editor with a bottom menu. | Press `Ctrl + X`. |
| `vim` | Advanced modal text editor. | Press `Esc`, then type `:q!` and press `Enter`. |

---

## 2. Key Concepts & Notation

* **Caret Notation (`^`)**: Represents the `Ctrl` key in terminal documentation (e.g., `^C` = `Ctrl + C`).
* **Universal Interrupt (`Ctrl + C`)**: The standard key combination to stop running programs, though it does not work in modal editors like `nano` or `vim`.
* **Exiting Vim**:
  * If stuck in **Insert Mode** (entered by pressing `i`), press `Esc` to return to Normal Mode.
  * Type `:q!` and press `Enter` to quit without saving changes.
  * Type `:wq` and press `Enter` to save changes and quit.

# Bonus Commands (Games and visuals)

| Command | Type | Description | Exit |
| :--- | :--- | :--- | :--- |
| `hello` | Text | Prints `"Hello world!"` | Auto |
| `worm` / `firework` / `rain` | Visuals | ASCII animations | `Ctrl + C` / `q` |
| `hanoi` | Puzzle | Tower of Hanoi game (move disks by size) | `q` |
| `knight` | Game | Chess knight logic puzzle | `q` / `x` |

### Linux File System Architecture

#### File System Hierarchy & Standards

- **File System Structure:** Organized as a single inverted tree hierarchy.
    
- **Root Directory (`/`):** The top-level directory of the entire Linux file system. All absolute paths originate from `/`.
    
- **FSSTD / FHS (1993):** The **Filesystem Hierarchy Standard** defines directory structure rules across GNU/Linux distributions to maintain system compatibility.
    

#### Core Linux Directories

|**Directory**|**Full Name / Acronym**|**Description**|
|---|---|---|
|**`/`**|Root|The top-level root directory of the entire file system hierarchy.|
|**`/bin`**|Binaries|Essential basic system commands required for all users (e.g., `ls`, `cp`).|
|**`/sbin`**|System Binaries|Executable binaries reserved for system administration (**superuser / root**).|
|**`/home`**|Home|Personal workspace directories for regular users (e.g., `/home/username/`).|
|**`/root`**|Root's Home|Dedicated home directory for the **root** administrator account.|
|**`/etc`**|Editable Text Configuration|System-wide configuration files in editable text format.|
|**`/lib`**|Libraries|Shared software libraries required by system binaries in `/bin` and `/sbin`.|
|**`/tmp`**|Temporary|Temporary storage. **Warning:** Typically wiped upon system reboot.|
|**`/var`**|Variable Data|Dynamic operational files, including log files (`/var/log`), mail, and spool queues.|
|**`/usr`**|Unix System Resources|Secondary hierarchy containing non-essential user utilities and software (`/usr/bin`, `/usr/lib`).|
|**`/dev`**|Devices|Special device nodes representing physical hardware (e.g., storage, audio, memory). _Linux treats everything as a file_.|