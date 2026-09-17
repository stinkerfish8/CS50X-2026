# Week 4: Memory

## 1. Memory & Hexadecimal System (Base-16)

The hexadecimal system uses 16 symbols (`0-9` and `A-F`) and is used in computer science to represent data in a more compact and readable way compared to binary.

* **System Comparison:**
  * **Binary (Base-2):** `0`, `1`
  * **Decimal (Base-10):** `0` - `9`
  * **Hexadecimal (Base-16):** `0` - `9` + `A`, `B`, `C`, `D`, `E`, `F` (`A=10`, `B=11`, `C=12`... )

* **Byte Representation (1 Byte = 8 bits):**
  * Maximum value for 1 byte: $2^8 - 1 = 255$ in decimal, corresponding to **`FF`** in hexadecimal
  * **RGB Pixel Example:** `#000000` (black) and `#FFFFFF` (white), where each pair of digits represents 1 byte per channel (R, G, B).

* **Memory Address Sequence:**

<table>
  <tr>
    <td>00</td><td>01</td><td>02</td><td>03</td><td>04</td><td>05</td><td>06</td><td>07</td>
  </tr>
  <tr>
    <td>08</td><td>09</td><td>0A</td><td>0B</td><td>0C</td><td>0D</td><td>0E</td><td>0F</td>
  </tr>
  <tr>
    <td>10*</td><td>11</td><td>12</td><td>13</td><td>14</td><td>15</td><td>16</td><td>17</td>
  </tr>
  <tr>
    <td>18</td><td>19</td><td>1A</td><td>1B</td><td>1C</td><td>1D</td><td>1E</td><td>1F</td>
  </tr>
</table>

*\* In hexadecimal, 0x10 equals decimal 16.*

---

### RAM & Addressing

* **Structure:** Each RAM memory cell corresponds to a single **byte** and is identified by a unique address expressed in hexadecimal.
* **`0x` Prefix:** Convention used in code to indicate that the following numerical sequence is written in base 16.

---

### Data Type Sizes (Integers)

#### CS50x / C (Linux 64-bit)
In C, size depends on the architecture and compiler. 
In the 64-bit Linux environment used in CS50x:

* `char`: **1 byte** (8 bits)
* `short`: **2 bytes** (16 bits)
* `int`: **4 bytes** (32 bits, 4 contiguous memory cells)
* `long`: **8 bytes** on Linux/macOS (4 bytes on Windows)
* `long long`: **8 bytes** (64 bits)
* `<stdint.h>`: Library used to guarantee fixed and standardized sizes across different platforms (e.g., `int32_t`).

#### Other Languages
* **Java:** `int` **always occupies 4 bytes** on any machine to ensure portability.
* **Python:** Integers have dynamic sizing (starting from a base structure of 28 bytes and growing automatically as needed).

---

### New Operators

* **`&` (Ampersand):**
  * **Address-of operator:** Prepended to a variable (e.g., `&n`), it returns the memory address where that variable is stored in RAM.
* **`*` (Asterisk):**
  * **Dereference operator:** Prepended to a pointer (e.g., `*p`), it goes to the stored memory address and accesses or modifies the actual value located there.

> [!TIP]
> **Etymology:** The name **Ampersand** comes from a contraction of the 19th-century English school recitation *"and per se and"*, used when the `&` symbol concluded the alphabet as the 27th letter.

### Printing Memory Addresses

``` c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}
```

#### Code Notes:

- **`&n` (Address-of operator):** Retrieves the memory address of variable `n`.
    
- **`%p` (Pointer specifier):** Format specifier used in `printf` to print **pointers** (memory addresses). Automatically formats the value in hexadecimal with the **`0x`** prefix (e.g., `0x7ff7bfe897b4`).

---

## 2. Pointers

A pointer is a variable that stores the **memory address** of another variable.

`int n = 50;`  
`int *p = &n;`

* **`int *p` Syntax:** Indicates that `p` is a pointer to an integer (*pointer to an int*), not a simple integer.
* **Asterisk Position:** The asterisk can be attached to the type (`int* p`), placed between spaces (`int * p`), or attached to the variable name (`int *p`). These syntax variations are functionally identical and do not change the meaning of the code. In CS50x, attaching it to the variable name (`int *p`) is preferred.
* **Pointer Size:** On a 64-bit architecture, a pointer **always occupies 8 bytes** (64 bits).
* **RAM Representation:**
  * `p` occupies 8 bytes and contains the address `0x123`.
  * `n` occupies 4 bytes at address `0x123` and contains the value `50`.

#### Dereferencing Operator

`printf("%i\n", *p); // Prints 50`

The asterisk `*` used in front of an existing pointer variable performs **dereferencing**: "go to the address stored in `p` and read the value present in that memory cell".

---

## 3. Strings

In C, **there is no native data type called `string`**. A string is a **contiguous array of characters in memory** ending with a special character called the **NULL Terminator** (`\0`, byte `0`).

#### Memory Structure of `"Hi!"`
* `s[0]` = `'H'` (Address `0x123`)
* `s[1]` = `'i'` (Address `0x124`)
* `s[2]` = `'!'` (Address `0x125`)
* `s[3]` = `'\0'` (Address `0x126` - NULL Terminator)

> [!NOTE]
> Enclosing text in double quotes (`" "`) automatically appends the **NULL Terminator** (`\0`) to the end of the character array in memory. 

#### Address of a String
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

---

### Pointer Arithmetic

To print the entire string, I must pass the character addresses to `printf`. I can use pointer arithmetic instead of array indexing syntax:

`printf("%c\n", *s);`  
`printf("%c\n", *(s + 1));`  
`printf("%c\n", *(s + 2));`  

Standard array indexing (`s[0]`, `s[1]`) remains the most readable syntax.

---

#### Why does `printf("%s\n", s)` print the entire string?

When using `%s`, `printf` expects a **memory address** (a `char *` like `s`).

1. **Starting Point:** Receives the address stored in `s` (the first character).
2. **Scanning:** Prints that character, moves to the next address (`s + 1`), then the next (`s + 2`), and so on.
3. **Stop Point:** Continues reading until it encounters the **NULL Terminator (`\0`)** in memory, automatically inserted by the compiler via double quotes (`"..."`).

#### What happens with offsets?

* `printf("%s\n", s);` -> Starts from the beginning and prints the full string (e.g., `HI!`).
* `printf("%s\n", s + 1);` -> Starts from the second character and reads until `\0` (e.g., `I!`).
* `printf("%s\n", s + 2);` -> Starts from the third character and reads until `\0` (e.g., `!`).

> [!NOTE]
> **Memory Allocation: Prompts and Strings**
> 
> 1. **Pointer Declaration (Stack):**
>    At startup, `char *s1` and `char *s2` immediately allocate **8 bytes** each on the *Stack* to hold future addresses.
> 
> 2. **User Input (Heap):**
>    At the prompt, the system dynamically allocates a block of **N + 1 bytes** on the *Heap*:
>    * `1 byte` for each typed character (`N`).
>    * `1 final byte` for the NULL Terminator (`\0`).
> 
> 3. **Assignment:**
>    The address of the allocated block is saved into the corresponding pointer's 8 bytes.

## 4. Duplicate Strings with `malloc` and `free`

To duplicate a string in C, you must allocate a new block of memory on the Heap at runtime instead of simply copying pointer addresses.

### How the Computer Allocates Memory

To allocate memory on the **Stack**, the program must know the exact requirements beforehand: each variable has a fixed size defined at launch (including fixed-size character arrays).

On the **Heap**, however, memory can be allocated on demand at runtime—for example, when handling an input of unknown length from a prompt. The program must explicitly request this memory using `malloc` and release it with `free`.

Initially, this allocation work was handled automatically by the `get_string()` function from the CS50 library (where `string` is merely an alias for `char *`). Now, we manage dynamic memory directly using standard C functions.

> **Note on Memory Leaks:** If memory allocated on the Heap with `malloc` is not released using `free`, it remains occupied even after the program no longer needs it. Over time, failing to free this memory leads to a **memory leak**, which can exhaust system RAM and crash the application.

### Key Concepts

* **Pointer Copy vs. String Copy:** Assigning one pointer to another (`char *t = s`) copies only the memory address. Both pointers end up referencing the same string, so modifying one affects the other.
* **Dynamic Memory (`malloc`):** Requests a specific byte size from the Heap. For strings, always allocate `strlen(s) + 1` bytes to accommodate the null terminator (`\0`).
* **Safety Check (`NULL`):** Always verify if `malloc` returns `NULL` before accessing memory. A `NULL` return indicates allocation failure.
* **String Duplication (`strcpy`):** Once memory is allocated, `strcpy(dest, src)` copies the character sequence along with the null terminator.
* **Memory Cleanup (`free`):** Memory allocated via `malloc` must be explicitly released using `free()` to prevent memory leaks.

### Code Implementation

``` c
#include <cs50.h>   // Provides string type and get_string()
#include <ctype.h>  // Character manipulation functions (e.g., toupper)
#include <stdio.h>  // Standard I/O functions like printf()
#include <stdlib.h> // Dynamic memory management (malloc, free) and NULL macro
#include <string.h> // String manipulation (strlen, strcpy)

int main(void)
{
    // 1. INPUT ACQUISITION
    char *s = get_string("s: ");

    /*
     * NOTES ON NULL vs \0:
     * - NULL (all-caps): A NULL POINTER (address 0x0). Represents missing memory or an error.
     * - '\0' (NUL byte): The STRING TERMINATOR character (byte value 0). Indicates the end of a string.
     */
    if (s == NULL)
    {
        return 1; // get_string failed or user cancelled input
    }


    /* 
     * =========================================================================
     * TEST 1 (INCORRECT): Copying only the pointer address
     * =========================================================================
     * char *t = s;
     * 
     * This does NOT create a new string; it only copies the ADDRESS.
     * s and t now point to the exact same memory block on the Heap.
     * Modifying t[0] inevitably modifies s[0] as well.
     * =========================================================================
     */


    /*
     * NOTES ON malloc (Memory Allocation):
     * - What it is: A function from <stdlib.h> that requests a specific number of 
     *   bytes from the OS in the HEAP memory (dynamic memory).
     * - Why we use it: Used when the required memory size is UNKNOWN at compile-time 
     *   and depends on user input during runtime.
     * - What it returns: The memory address (pointer) to the FIRST byte of the allocated block.
     *   If RAM is full or allocation fails, it returns NULL.
     */

    // 2. DYNAMIC MEMORY ALLOCATION
    // Request a RAM block equal to: s length + 1 (for the '\0' terminator).
    char *t = malloc(strlen(s) + 1);

    // Always check if malloc returned NULL (out of memory)
    if (t == NULL)
    {
        return 1;
    }


    /* 
     * =========================================================================
     * TEST 2 (ACADEMIC): Manual character-by-character copy
     * =========================================================================
     * Condition 'i <= n' ensures the '\0' terminator is also copied.
     * 
     * for (int i = 0, n = strlen(s); i <= n; i++)
     * {
     *     t[i] = s[i];
     * }
     * =========================================================================
     */


    // 3. ACTUAL COPY (Standard solution)
    // strcpy(destination, source) automatically copies characters along with the '\0'.
    strcpy(t, s);

    // Capitalize the first letter of the copy if the string is not empty
    if (strlen(s) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // 4. PRINT RESULTS
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // 5. FREE MEMORY
    // Every block allocated with malloc() MUST be freed before the program ends.
    // Forgetting this leads to "Memory Leaks", consuming system RAM unnecessarily.
    free(t);

    return 0;
}
```

> [!NOTE] What is the `NULL` Macro?
> In C, a **macro** is a symbol defined via the `#define` preprocessor directive. Before compilation, the preprocessor replaces `NULL` with its actual value, typically defined in `<stdlib.h>` as `((void *)0)`.
>
> * **Not a Keyword:** Unlike `int` or `return`, `NULL` is not built into the C language itself, but provided by standard libraries.
> * **Type Safety & Readability:** It explicitly represents a null pointer (address `0x0`), making code far clearer than using a plain `0`.