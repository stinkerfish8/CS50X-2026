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
