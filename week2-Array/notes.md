# Computer Science & Low-Level Programming Notes

## 1. Low-Level Concepts & Memory Representation
Low-Level Definition: Indicates how close a language or system is to the actual hardware. High-level languages (like Python or Java) abstract the hardware away, while low-level languages (like C) force the programmer to manage memory and the processor directly.

The Reality of Characters: In computing, letters do not actually exist; everything is a number. Characters are just numeric values interpreted through encoding standards like ASCII or Unicode.
Example: The character 'A' is stored as the number 65. Adding 1 results in 66, which represents 'B'.

The State of RAM: RAM is physically 100% full at all times. There is no such thing as a "non-existent" or "empty" slot in terms of hardware. Every single bit always holds either a 0 (low voltage) or a 1 (high voltage).
Garbage Values: When a variable is declared without initialization, it contains the random leftover binary data previously stored in that memory slot by other programs.
Data vs. "Nothing": Software and programming languages create logical rules (like the Null Terminator \0 in strings or NULL pointers) to simulate the concept of emptiness or the end of a data structure.

## 2. Hardware & Microscopic Structure of RAM
The "Water Glass" Analogy: A RAM cell behaves like a microscopic glass filled with water. 
1 = High electrical charge (full glass).
0 = Low/no electrical charge (empty glass).

Microscopic Architecture: Under an electron microscope, modern DRAM consists of a massive, geometric grid made of billions of cylindrical pillars. Each single bit is composed of:
1.  A Capacitor: A vertical trench/pillar structure in the silicon that physically holds the electrical charge (the glass).
2.  A Transistor: The electronic switch that reads or updates the charge state (the faucet).

Scale: RAM cells are microscopic, measuring roughly 10 to 15 nanometers (nm). Over 5,000 cells can sit side-by-side within the width of a single human hair.

Physical Shape (Cylindrical vs. Square): Although mapped logically as a square grid, the physical cells are round due to:
1.  Light Diffraction: At nanometer scales, lithographic light naturally rounds off sharp corners during manufacturing.
2.  Electrical Stability: Sharp corners would cause an "edge effect," concentrating electrical fields and causing electrons to leak out faster. Round shapes distribute the charge evenly.

Volatility and Refresh: Because these containers are atomic in scale, the electrical charge leaks constantly. RAM requires a continuous "Refresh" cycle where the computer recharges the cells holding a 1 hundreds of times per second. When power is cut, all charges dissipate instantly.

## 3. C Syntax & Typographic Clarifications
The Unsigned Qualifier: The unsigned keyword shifts the entire capacity of a data type above zero, removing the ability to store negative numbers but doubling the maximum positive range.
Example: A standard signed char ranges from -128 to +127. An unsigned char shifts this capacity entirely to a range of 0 to 255.
Trade-off: You can no longer use -1 as a special error or EOF (End of File) signal within that variable.

Dash vs. Hyphen Differentiation:
Hyphen (-): The standard key to the right of the zero. In programming, it functions as the minus sign (-o flags in terminal commands use this character).
En-dash (–): Equal to the width of a capital letter "N". Historically used in typesetting for ranges (e.g., pages 10–20).
Em-dash (—): Equal to the width of a capital letter "M". Used in typography for parenthetical breaks or sentence interruptions.
