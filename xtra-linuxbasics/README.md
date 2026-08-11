# Linux Basics: The Command Line Interface

This section is dedicated to my study of Linux basics and command-line fundamentals. 

EdX course by Dartmouh College: [Linux Basics: The Command Line Interface](https://www.edx.org/learn/linux/dartmouth-college-linux-basics-the-command-line-interface)

---
# Core Concepts Summary

### 1. Introduction to UNIX & CLI
* **Shell & Prompt:** Shell mechanics (`sh`/`bash`), terminal modes, prompt symbols (`~`, `$`, `#`).
* **Basic Commands:** System diagnostics (`whoami`, `uname`), date formatting, session history.
* **Signals:** Interrupts (`Ctrl+C`), EOF (`Ctrl+D`), process suspend (`Ctrl+Z`), screen clear (`Ctrl+L`).

### 2. File System Navigation
* **Hierarchy:** Root structure (`/`), core directories (`/bin`, `/home`, `/etc`, `/var`, `/tmp`).
* **Navigation:** Absolute vs relative paths, path traversal (`pwd`, `cd`, `ls -la`), shortcuts (`.`, `..`, `~`).
* **File Types:** File type inspection (`file`), binary location (`which`), symlinks (`realpath`).

### 3. File & Directory Management
* **Operations:** Creation (`touch`, `mkdir -p`), moving/renaming (`mv`), copying (`cp`), deletion (`rm -r`).
* **I/O & Piping:** Streams (`stdin`/`stdout`/`stderr`), redirection (`>`, `>>`, `2>`), pipes (`|`), paging (`less`).
* **Search:** Shell globbing (`*`, `?`), recursive searching (`find` with `-name`, `-iname`).

### 4. System Monitoring & Processes
* **Memory & Storage:** RAM vs persistent storage, addressing concepts.
* **Diagnostics:** Memory inspection (`free`), process management (`top`, `htop`).
* **Signals & Control:** Process signals (`SIGINT`, `SIGKILL`), process termination (`kill`).

---

## Tools
*   **Platform:** edX (Dartmouth College)
*   **Practice Environment:** [WebLinux (built-in course terminal)](https://remisharrock.github.io/sysbuild/#/VM)
*   **Dark Mode Fix:** [edx-darkmode.user.js](./edx-darkmode.user.js) | [Install edX DarkMode](https://raw.githubusercontent.com/stinkerfish8/CS50X-2026/main/xtra-linuxbasics/edx-darkmode.user.js)
