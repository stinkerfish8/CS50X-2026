# Git Essential Guide

A quick reference guide for managing your repositories via the command line.
[Git - Install for Windows](https://git-scm.com/install/windows)

---

## 1. The Daily Workflow
These are the core commands you will use most frequently during development:

| Command | Description |
| :--- | :--- |
| `git status` | Shows modified files and what is staged for the next commit. |
| `git add <file>` | Stages a specific file, preparing it for a commit. |
| `git add .` | Stages **all** modified and new files in the current directory. |
| `git commit -m "message"` | Saves your staged changes locally with a descriptive message. |
| `git push` | Sends your local commits to the remote repository (GitHub). |

---

## 2. Synchronizing & Setup
Commands used to initialize repositories or fetch updates from the remote server:

* `git init`
  Initializes a brand new local Git repository in the current folder.
* `git clone <url>`
  Copies an existing remote repository to your computer.
* `git pull`
  Fetches changes from the remote server and merges them into your local files.
* `git fetch`
  Downloads updates from the remote server *without* modifying your local files.

---

## 3. Advanced & Maintenance
Useful commands for fixing mistakes and managing untracked configuration paths:

> [!TIP]
> Always use the `--cached` flag when you want to stop tracking a file on GitHub without deleting it from your actual hard drive.

* `git rm --cached <file>`
  Removes a file from GitHub tracking while keeping the local file intact.
* `git rm -r --cached <folder>`
  Recursively removes an entire folder from GitHub tracking while preserving your local directory.
* `git log --oneline`
  Shows a simplified, clean history of your recent commits.

<hr style="border: 2px solid gray;">

# Git Flags Explained: Single vs. Double Dashes

When running commands in the terminal, anything written after the main command (like `git rm`) is an option or parameter called a **flag**. Flags modify how the command behaves.

---

## 1. The Single Dash (`-r`)
* **Meaning:** Stands for **"recursive"**.
* **Purpose:** By default, file removal commands are designed to handle one file at a time. If you target a folder, the system will block the action for safety. Adding `-r` instructs Git to enter the directory and recursively remove everything inside it (including all subfolders and files).
* **Syntax Rule:** In Unix-like environments (such as Git Bash), options consisting of a **single letter** are conventionally preceded by a single dash (e.g., `-r`, `-m`, `-v`).

---

## 2. The Double Dash (`--cached`)
* **Meaning:** Instructs Git to operate **only on the index** (the staging area/cache of tracked files) and ignore the physical hard drive.
* **Purpose:** If you run `git rm -r .obsidian`, Git deletes the folder from both the GitHub repository and your local storage. By adding `--cached`, you tell Git: *"Stop tracking this folder for GitHub, but leave my local physical files completely untouched."*
* **Syntax Rule:** Options that are spelled out as **full words** (rather than a single letter) are conventionally preceded by two dashes. This helps the terminal distinguish a full-word argument from a cluster of individual single-letter flags.

---

> [!SUMMARY]
> `-r` $\rightarrow$ Apply to the entire folder and its contents recursively.
> `--cached` $\rightarrow$ Apply only to Git's index; do not touch local files.

# Syncing Multiple Files at Once in Git

You can stage and commit all your modifications, new files, and deletions simultaneously using a single shortcut.
## The Directory Shortcut (`.`)
Instead of naming a specific file, use a dot (`.`) with the add command:

```bash
git add .
```

# Recursion in Action: Factorial and Fibonacci

In computer science, recursion is an algorithmic pattern where a function calls itself to solve smaller instances of the same problem. To avoid infinite loops and a subsequent **Stack Overflow**, every recursive function must possess a **Base Case** (the stopping condition) and a **Recursive Case** (the step that reduces the problem).

## 1. The Factorial Function ($n!$)

The factorial of a positive integer $n$ (written as $n!$) is the product of all positive integers less than or equal to $n$.

### Mathematical Concept

$$n! = n \times (n - 1) \times (n - 2) \times \dots \times 1$$

- _Example ($4!$):_ $4! = 4 \times 3 \times 2 \times 1 = 24$
### The Recursive Core

Factorial is naturally recursive because $4!$ can be rewritten as $4 \times 3!$. Therefore, the general rule to find the factorial of $n$ is to multiply $n$ by the factorial of $n - 1$.

- **Base Case:** If $n = 0$ or $n = 1$, return `1`. _(Note: $0! = 1$ because there is exactly 1 unique way to arrange 0 items - by leaving the space empty).

- **Recursive Case:** For any $n > 1$, return $n \times \text{factorial}(n - 1)$.

``` c
int factorial(int n)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // Recursive Case
    return n * factorial(n - 1);
}
```

## 2. The Fibonacci Sequence

The Fibonacci sequence is a famous mathematical series where each number is the sum of the two preceding ones, usually starting from 0 and 1.

$$\text{Sequence: } 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 \dots$$

### The Recursive Core

To find the Fibonacci number at position $n$, the system must split into **two recursive calls** simultaneously. It calculates the value of the two previous positions ($n-1$ and $n-2$) and adds them together.

- **Base Cases:**
    
    - If $n = 0$, return `0`.
        
    - If $n = 1$, return `1`.
        
- **Recursive Case:** For any $n > 1$, return $\text{fibonacci}(n - 1) + \text{fibonacci}(n - 2)$.
    

### C Code Implementation

C

```
int fibonacci(int n)
{
    // Base Cases
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    // Recursive Case
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

## Summary Comparison

| **Function**  | **Base Case Condition** | **Recursive Case Formula**                | **Call Stack Behavior**                            |
| ------------- | ----------------------- | ----------------------------------------- | -------------------------------------------------- |
| **Factorial** | `n == 0` or `n == 1`    | $n \times \text{func}(n - 1)$             | Single linear chain of frames on the stack.        |
| **Fibonacci** | `n == 0` or `n == 1`    | $\text{func}(n - 1) + \text{func}(n - 2)$ | Generates a branching tree of frames on the stack. |