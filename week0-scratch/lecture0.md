# Lecture 0

72 73 33

Computers generally use eight bits (also known as a byte) to represent a number.

| 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

### Powers of 2 Table

| Power | Result | Meaning and Usage |
| :--- | :--- | :--- |
| 2^0 | **1** | Single bit (the smallest value) |
| 2^1 | **2** | The two states of binary (0 and 1) |
| 2^2 | **4** | Often used in graphics and colors |
| 2^3 | **8** | **1 Byte** (composed of 8 bits) |
| 2^4 | **16** | Base for Hexadecimal system (hex colors) |
| 2^5 | **32** | Max value counting with 5 fingers (0-31) |
| 2^6 | **64** | **A Minecraft stack** |
| 2^7 | **128** | Half of a byte's capacity |
| 2^8 | **256** | One byte limit (JRPG stats, RGB 0-255) |
| 2^9 | **512** | Common texture resolution in games |
| 2^10 | **1024** | **1 Kilobyte (KB)** |

> **Note:** In computer science, each subsequent power is exactly double the previous one. This allows computers to scale memory efficiently.

### Hexadecimal System (Base 16)

The Hexadecimal system is a way to represent numbers using **16 symbols**. It is widely used in computing because one hex digit represents exactly **4 bits**.

#### Symbols:
`0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F`
* **A-F** represent values from **10 to 15**.

#### Why use Hex?
It is much shorter than binary. For example, a full byte (8 bits):
* **Binary:** `11111111`
* **Decimal:** `255`
* **Hexadecimal:** `FF`

#### Example Conversion: The letter "A"
As seen in the Windows Character Map, the letter **A** has the hex code `41`.
To convert it to Decimal:
1. Multiply the first digit by 16: `4 * 16 = 64`
2. Add the second digit: `64 + 1 = 65`
3. Result: **65** (The ASCII code for "A")

#### Hex in Gaming and Design:
* **RGB Colors:** White is `#FFFFFF` (Max Red, Max Green, Max Blue).
* **Memory Addresses:** Often shown as hex codes like `0x0041`.

#### Quick Glossary
* **Digit**: A single symbol used to write numbers (e.g., 0-9 in Decimal, 0-1 in Binary).
* **Bit**: Binary digit.
* **Computing**: The process of using computer technology to complete a task or manage data.
* **Hex Digit**: A single hexadecimal symbol (0-F). One hex digit represents 4 bits.
* **Hex Codes**: A base-16 representation of RGB values. 
* **Structure**: #RRGGBB (2 digits per color channel).
* **Efficiency**: It's a "shorthand" for binary. One Hex digit represents exactly 4 bits (half a byte).
* **Logarithm (log)**: The inverse of an exponent. 
* **In Computing**: It tells us how many times we can split a problem in half.
* **Example**: log of 8 is 3 (8 -> 4 -> 2 -> 1).
* **Algorithm**: A step-by-step procedure for solving a problem or accomplishing a end. 
* **Core Principle**: It's not just about getting the answer, it's about the efficiency (correctness + speed) of the process.
* **Scratch**: Visual programming language developed by MIT.
* **Nybble**: Half a byte (4 bites).

---
<details>
<summary>Insight: Deduction vs. Inference</summary>
<ul>
  <li><strong>Deduction (Theory):</strong> Admins want a successful project ➔ A successful project requires communication and staff support ➔ Therefore, admins must support the Social Manager.</li>
  <li><strong>Inference (Reality):</strong> Admins ignore messages and refuse even a 1-second reaction on Telegram, claiming they have no time.</li>
  <li><strong>Conclusion:</strong> While the deduction is theoretically flawless, the practical <em>inference</em> reveals the truth: "having no time" is just an excuse. Human limitations (laziness, lack of foresight, and low engagement) break the ideal logical chain. Real-world actions always override theoretical axioms.</li>
</ul>
</details>



