# Versioning Cheat Sheet

Version control tracking and release versioning conventions provide structure for managing software updates and dependencies.

## 1. Semantic Versioning (SemVer)
The standard convention for software versioning based on functional and structural impact, structured as **`MAJOR.MINOR.PATCH`**.

* **`MAJOR` (e.g., `2.0.0`):** Incremented for incompatible API changes or breaking updates.
* **`MINOR` (e.g., `1.1.0`):** Incremented when adding backwards-compatible new features.
* **`PATCH` (e.g., `1.0.2`):** Incremented for backwards-compatible bug fixes and minor patches.
* **Initial Development:** Versions starting with `0.y.z` indicate initial, unstable development where APIs and rules can change at any time.

## 2. Calendar Versioning (CalVer)
A versioning convention based on a project's release calendar and timeline rather than semantic logic.

* **Common Formats:**
  * **`YYYY.MM.Micro`** (e.g., `2026.4.1`): Full year, month, and sequence number.
  * **`YY.MM`** (e.g., `26.04`): Short year and month (commonly used by time-driven software like Ubuntu).
  * **`YY.Minor.Patch`**: Year-based prefix combined with traditional identifiers.
* **Advantages:** Instantly communicates *when* a version was released; ideal for scheduled software or games with fixed calendar release cycles.
* **Drawbacks:** Does not signal breaking API changes or provide insight into the technical scope of the changes.

## 3. Alternative Schemes
* **Sequential Versioning:** A single progressive number that increases with every release (e.g., `v1`, `v2`, `v3`), often used in consumer software and games.
* **Build / Revision Numbering:** Appends an automated counter to track individual builds, packages, or CI/CD deployments (e.g., `1.0.0.452`).
