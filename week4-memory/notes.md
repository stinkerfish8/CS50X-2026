# Week 4: Memory

# 1. Memory & Hexadecimal System

## Hexadecimal System (Base-16)

The hexadecimal system uses 16 symbols (`0-9` and `A-F`) and is used in computer science to represent data in a more compact and readable way compared to binary.

* **System Comparison:**
  * **Binary (Base-2):** `0`, `1`
  * **Decimal (Base-10):** `0` - `9`
  * **Hexadecimal (Base-16):** `0` - `9` + `A`, `B`, `C`, `D`, `E`, `F` (`A=10`, `B=11`, `C=12`... )

* **Byte Representation (1 Byte = 8 bits):**
  * Maximum value for 1 byte: $2^8 - 1 = 255$ in decimal, corresponding to **`FF`** in hexadecimal
  * **RGB Pixel Example:** `#000000` (black) and `#FFFFFF` (white), where each pair of digits represents 1 byte per channel (R, G, B).

* **Memory Address Sequence:**
  * `0  1  2  3  4  5  6  7`
  * `8  9  A  B  C  D  E  F`
  * `10 11 12 13 14 15 16 17` *(`0x10` equals decimal 16)*
  * `18 19 1A 1B 1C 1D 1E 1F`

---

## RAM & Addressing

* **Structure:** Each RAM memory cell corresponds to a single **byte** and is identified by a unique address expressed in hexadecimal.
* **`0x` Prefix:** Convention used in code to indicate that the following numerical sequence is written in base 16.

---

## Data Type Sizes (Integers)

### CS50x / C (Linux 64-bit)
In C, size depends on the architecture and compiler. 
In the 64-bit Linux environment used in CS50x:

* `char`: **1 byte** (8 bits)
* `short`: **2 bytes** (16 bits)
* `int`: **4 bytes** (32 bits, 4 contiguous memory cells)
* `long`: **8 bytes** on Linux/macOS (4 bytes on Windows)
* `long long`: **8 bytes** (64 bits)
* `<stdint.h>`: Library used to guarantee fixed and standardized sizes across different platforms (e.g., `int32_t`).

### Other Languages
* **Java:** `int` **always occupies 4 bytes** on any machine to ensure portability.
* **Python:** Integers have dynamic sizing (starting from a base structure of 28 bytes and growing automatically as needed).

---

## New Operators

* **`&` (Ampersand):**
  * **Address-of operator:** In C, prepended to a variable (e.g., `&n`), it returns the hexadecimal memory address where the variable is allocated.
  * *Historical note:* The name **Ampersand** comes from a contraction of the 19th-century English school recitation *"and per se and"*, used when the `&` symbol concluded the alphabet as the 27th letter.

## Printing Memory Addresses

``` c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}
```

### Code Notes:

- **`&n` (Address-of operator):** Retrieves the memory address of variable `n`.
    
- **`%p` (Pointer specifier):** Format specifier used in `printf` to print **pointers** (memory addresses). Automatically formats the value in hexadecimal with the **`0x`** prefix (e.g., `0x7ff7bfe897b4`).

# 2. Pointers

A pointer is a variable that stores the **memory address** of another variable.

`int n = 50;`  
`int *p = &n;`

* **`int *p` Syntax:** Indicates that `p` is a pointer to an integer (*pointer to an int*), not a simple integer.
* **Asterisk Position:** The asterisk can be attached to the type (`int* p`), the space (`int * p`), or the variable (`int *p`). In CS50x, attaching it to the variable name (`int *p`) is preferred.
* **Pointer Size:** On a 64-bit architecture, a pointer **always occupies 8 bytes** (64 bits) regardless of the data type it points to, as it must hold a long memory address.
* **RAM Representation:**
  * `p` occupies 8 bytes and contains the address `0x123`.
  * `n` occupies 4 bytes at address `0x123` and contains the value `50`.

### Dereferencing Operator

`printf("%i\n", *p); // Prints 50`

The asterisk `*` used in front of an existing pointer variable performs **dereferencing**: "go to the address stored in `p` and read the value present in that memory cell".

---

## 3. Strings

In C, **there is no native data type called `string`**. A string is a **contiguous array of characters in memory** ending with a special character called the **NULL Terminator** (`\0`, byte `0`).

### Memory Structure of `"Hi!"`
* `s[0]` = `'H'` (Address `0x123`)
* `s[1]` = `'i'` (Address `0x124`)
* `s[2]` = `'!'` (Address `0x125`)
* `s[3]` = `'\0'` (Address `0x126` - NULL Terminator)

### Address of a String
To represent a string, knowing **the address of its first character** is sufficient.

`char *s = "Hi!";`

`printf("%p\n", s);`          // Prints the address of s, hence the first character 
`printf("%p\n", &s[0]);`   // Identical to s (address of 'H')  
`printf("%p\n", &s[1]);`   // Address of 'i'  
`printf("%p\n", &s[2]);`   // Address of '!'  
`printf("%p\n", &s[3]);`   // Address of NULL Terminator '\0'  

---

### `typedef` and the `<cs50.h>` Library

The `typedef` keyword allows creating an alias ("new name") for an existing data type.

*Example*: `typedef int integer; // Creates the alias 'integer' for type 'int'`

The `cs50.h` library defines the `string` type using a simple `typedef` that hides the character pointer syntax (`char *`):

`typedef char *string;`

It declares that the word `string` is equivalent to writing `char *`. 
Outside CS50x, strings are declared using native C syntax directly:

`char *s = "Hi!";`

## 4. Pointer Arithmetic

To print the entire string, I must pass the character addresses to `printf`. I can use pointer arithmetic instead of array indexing syntax:

`printf("%c\n", *s);`  
`printf("%c\n", *(s + 1));`  
`printf("%c\n", *(s + 2));`  

Standard array indexing (`s[0]`, `s[1]`) remains the most readable syntax.

---

### Why does `printf("%s\n", s)` print the entire string?

When using `%s`, `printf` expects a **memory address** (a `char *` like `s`).

1. **Starting Point:** Receives the address stored in `s` (the first character).
2. **Scanning:** Prints that character, moves to the next address (`s + 1`), then the next (`s + 2`), and so on.
3. **Stop Point:** Continues reading until it encounters the **NULL Terminator (`\0`)** in memory, automatically inserted by the compiler via double quotes (`"..."`).

### What happens with offsets?

* `printf("%s\n", s);` -> Starts from the beginning and prints the full string (e.g., `HI!`).
* `printf("%s\n", s + 1);` -> Starts from the second character and reads until `\0` (e.g., `I!`).
* `printf("%s\n", s + 2);` -> Starts from the third character and reads until `\0` (e.g., `!`).

> [!info] Memory Allocation: Prompts and Strings
> 1. **Pointer Declaration (Stack):**  
>    At startup, `char *s1` and `char *s2` immediately allocate **8 bytes** each on the *Stack* to hold future addresses.
> 
> 2. **User Input (Heap):**  
>    At the prompt, the system dynamically allocates a block of **`N + 1` bytes** on the *Heap*:
>    * `1 byte` for each typed character (`N`).
>    * `1 final byte` for the NULL Terminator (`\0`).
> 
> 3. **Assignment:**  
>    The address of the allocated block is saved into the corresponding pointer's 8 bytes.