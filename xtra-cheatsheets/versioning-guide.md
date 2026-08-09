# Versioning Cheat Sheet

Version control tracking and release versioning conventions provide structure for managing software updates and dependencies.

## 1. Version Control System (VCS) Basics
A system that records changes to files over time so you can recall specific versions later.

* **Why It Is Used:**
  * **Change History:** Tracks every modification, who made it, and when.
  * **Rollback:** Allows reverting to a stable previous version if an update introduces bugs.
  * **Collaboration:** Enables multiple people to work on the same project in parallel without overwriting each other's work.
* **Main Types:**
  * **Centralized (e.g., SVN):** A single central server stores the history; local clients only hold the latest version of the files.
  * **Distributed (e.g., Git):** Every developer has a complete local copy of the repository, including the entire commit history.
* **Core Pillars of Git:**
  * **Working Directory:** The local folder where you actively modify files.
  * **Staging Area (Index):** An intermediate area where changes are queued before being saved.
  * **Repository:** The local database storing the permanent project history through commits.

## 2. Semantic Versioning (SemVer)
The standard convention for software versioning based on functional and structural impact, structured as **`MAJOR.MINOR.PATCH`**.

* **`MAJOR` (e.g., `2.0.0`):** Incremented for incompatible API changes or breaking updates.
* **`MINOR` (e.g., `1.1.0`):** Incremented when adding backwards-compatible new features.
* **`PATCH` (e.g., `1.0.2`):** Incremented for backwards-compatible bug fixes and minor patches.
* **Initial Development:** Versions starting with `0.y.z` indicate initial, unstable development where APIs and rules can change at any time.

## 3. Calendar Versioning (CalVer)
A versioning convention based on a project's release calendar and timeline rather than semantic logic.

* **Common Formats:**
  * **`YYYY.MM.Micro`** (e.g., `2026.4.1`): Full year, month, and sequence number.
  * **`YY.MM`** (e.g., `26.04`): Short year and month (commonly used by time-driven software like Ubuntu).
  * **`YY.Minor.Patch`**: Year-based prefix combined with traditional identifiers.
* **Advantages:** Instantly communicates *when* a version was released; ideal for scheduled software or games with fixed calendar release cycles.
* **Drawbacks:** Does not signal breaking API changes or provide insight into the technical scope of the changes.

## 4. Alternative Release Schemes
* **Sequential Versioning:** A single progressive number that increases with every release (e.g., `v1`, `v2`, `v3`), often used in consumer software and games.
* **Build / Revision Numbering:** Appends an automated counter to track individual builds, packages, or CI/CD deployments (e.g., `1.0.0.452`).

## 5. Real-World Gaming Examples
* **Minecraft:** 
  * **Previous System:** Historically relied on a modified version-based and sequential structure (e.g., `1.20`, `1.21`) for major updates.
  * **Current System:** Transitioned to Calendar Versioning (CalVer) for major releases (e.g., `26.1`) to tie updates directly to the release year.
  * **Snapshots:** Utilizes weekly chronological snapshots for pre-release testing following a `YYwWW[a-z]` format (e.g., `26w10a` representing the tenth week of 2026).
  * *(Reference/Source: [Minecraft Update Numbering Is Changing in 2026! What You Need to Know](https://www.youtube.com/watch?v=vy__HW5x73k))*
* **Hytale:** 
  * **Early Access:** Manages its production timeline through an Early Access framework leading up to the stable `1.0.0` release.
  * **Modding & Ecosystem:** Enforces strict Semantic Versioning (SemVer) across its modding APIs, plugin ecosystems, and asset packages to prevent breaking changes and ensure smooth dependency resolution.
