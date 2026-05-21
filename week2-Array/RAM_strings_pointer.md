# RAM Memory, Strings, and Pointers

In C, strings do not exist as a native data type. The `string` type included in the `<cs50.h>` library is actually an alias for `char *`, which means a **pointer to a character**.

---

## 1. What is a Pointer?
A pointer is a variable that does not contain a direct value (like a number or text), but instead contains a **memory address**. This address points to the specific cell in the RAM where the actual data is stored.

* **Fixed Size:** On a 64-bit system (like the CS50 cloud environment), every memory address occupies exactly 64 bits, which equals **8 bytes**.
* **How `sizeof` behaves:** Consequently, running `sizeof(string)` will always return **8**, because it measures the size of the container (the 64-bit address), not the content.
* **How `strlen` behaves:** On the other hand, the `strlen()` function physically walks through the memory starting from that initial address, counting characters one by one until it hits the string terminator `\0`.

---

## 2. Anatomy of the RAM: Where are variables located?
When we run a program, the RAM allocated to it is divided into distinct areas with different purposes. Let's take this line of code as an example:

```c
string name = "Hi!";

    RAM (Stack)                          RAM (Data Segment / Heap)
 ┌─────────────────┐                    ┌─────────────────┐
 │ Variable: name  │ ──(points to)────> │ 'H' | 'i' | '!' │ '\0'
 │ Value: 0x7fff00 │                    └─────────────────┘
 │ Size: 8 bytes   │                    Address: 0x7fff00
 └─────────────────┘
```
#### The Stack
This is the memory area where the computer automatically places local variables created inside functions (such as those defined in `main`).
* **What is inside:** The `name` variable (the pointer).
* **Size:** It rigidly occupies **8 bytes** (the address of the very first character of the text).
* **Management:** It is extremely fast and handled automatically by the operating system: when the function ends, this memory is immediately cleaned up.

#### The Data Segment / The Heap (Dynamic Memory)
This is the area where string literals or dynamically allocated data reside.
* **What is inside:** The actual characters making up the text (`'H'`, `'i'`, `'!'`, `\0`).
* **Size:** It depends entirely on the content. In the case of `"Hi!"`, it will occupy **4 bytes** (3 bytes for the letters + 1 byte for the null terminator `\0`). If it contained the entire *Divine Comedy*, this area would occupy several megabytes.
* **Management:** This memory persists independently of the lifecycle of individual functions.

---

### 3. Analogy Summary

* **The House Analogy:** The *Stack* contains a small piece of paper with the street address written on it (8 bytes). The *Heap / Data Segment* is the actual physical house located at that address (whose size depends on how large the building is).
* **The Box Analogy:** `sizeof` measures the outer dimensions of the cardboard gift box (a standard 8-byte format). `strlen` opens the box and measures the actual length of the item placed inside.
