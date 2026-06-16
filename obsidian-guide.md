# Obsidian Quick Start Guide

Official Website & Download: [https://obsidian.md](https://obsidian.md)

---

## 1. What is Obsidian?
Obsidian is a powerful, local-first knowledge base that operates on top of a local folder of plain text Markdown files (`.md`). It allows you to build a **"Second Brain"** by connecting notes together, turning a flat folder structure into a network of ideas.

---

## 2. Core Concepts You Must Know

### 📁 1. The "Vault"
In Obsidian, a **Vault** is simply a folder on your computer. When you open Obsidian for the first time, choose **"Open folder as vault"** and select your local GitHub `CS50X-2026` directory. Obsidian will instantly recognize your weeks, folders, and markdown files.

### 🔗 2. Internal Links (The Superpower)
You can link notes together dynamically. To link another note, just type **double square brackets**: `[[Note Name]]`.
* *Example:* Inside your `week3-algorithms.md` note, you can type `[[week2-Arrays]]` to instantly link back to the previous week.
* If the note doesn't exist yet, clicking the link will **automatically create** that new file for you.

### 🕸️ 3. Graph View (Mappa Visiva)
On the left sidebar, you will see an icon that looks like a network diagram. Clicking it opens the **Graph View**. This is an interactive visual map where every note is a node and every internal link is a connection. As your CS50 notes grow, you will literally see your knowledge expanding.

---

## 3. Essential Hotkeys (Scorciatoie da Tastiera)

| Key Combination | Action | Description |
| :--- | :--- | :--- |
| <kbd>Ctrl</kbd> + <kbd>E</kbd> | **Toggle Preview/Edit** | Switch between writing raw Markdown and seeing the formatted result. |
| <kbd>Ctrl</kbd> + <kbd>O</kbd> | **Quick Switcher** | Open a search bar to instantly jump to any note in your Vault. |
| <kbd>Ctrl</kbd> + <kbd>Click</kbd> | **Open Link in New Tab** | Open a linked note in a separate tab next to your current one. |
| <kbd>Alt</kbd> + <kbd>←</kbd> / <kbd>→</kbd> | **Navigate Back/Forward** | Go back to the previous note you were viewing (like a web browser). |

---

## 4. Tips for Developers and Students

1. **Native Mermaid Support:** Obsidian renders Mermaid code blocks perfectly without needing any extra plugins or extensions.
2. **Git Integration:** Since Obsidian saves raw `.md` files on your hard drive, you can keep using Git Bash, VS Code, or GitHub Desktop to push your changes to your GitHub repository just like you've always done.
3. **Plugins Environment:** If you ever want to expand its features, you can explore the *Community Plugins* section in the settings (e.g., for automatic git syncing or advanced calendar tools).
