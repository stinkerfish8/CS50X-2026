# Arrays

## What is an Array?
An array is a chunk of contiguous (consecutive) memory space in the RAM partitioned into small, identically-sized blocks.
* **The Post Office Analogy:** Think of an array like a large mail bank on a post office wall. The entire wall is the array, each individual mailbox is an **element**, the content inside is the **data**, and the mailbox number is the **index** used to access it directly.
* **Type Restriction:** All elements in an array must be of the exact same data type (e.g., all `int` or all `char`). You cannot mix different types in a single array.

---

## Indexing and Counting
* **Zero-Indexed:** In C, array indexing always starts at `0`. The very first element of an array is at index `0`.
* **The Last Element:** If an array consists of `n` elements, the final element is always located at index `n - 1`. For example, in an array of 5 items, the indexes are `0, 1, 2, 3, 4`.

---

## Syntax: Declaration, Initialization, and Usage

### Declaration
To declare an array, specify the data type, the name of the array, and the number of elements inside square brackets.
* `int scores[5];` (Allocates memory for 5 integers. At this point, they contain random garbage values from the RAM).

### Initialization
You can initialize an array at the moment of declaration using curly braces.
* `int scores[5] = {95, 82, 73, 90, 88};` (Fills the array with specific values).
* `int scores[] = {95, 82, 73};` (If you initialize it immediately, you can omit the size; the compiler automatically counts 3 elements).
* `int scores[5] = {0};` (A quick shortcut to initialize all 5 elements to zero).

### Usage (Accessing and Modifying)
Use square brackets with the index number to read or overwrite specific values.
* **To read:** `printf("%i", scores[0]);` (Prints the first element).
* **To modify:** `scores[2] = 100;` (Overwrites the third element with the value 100).

---

## Multidimensional Arrays

### What are they?
You can create arrays of arrays. The most common type is a 2D array, which works like a grid, a matrix, or a spreadsheet with rows and columns.
* **Declaration (2D):** `int matrix[3][4];` (Creates a grid with 3 rows and 4 columns).
* **Initialization (2D):** `int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };`

### How many dimensions can you have?
Theoretically, C allows you to have as many dimensions as you want (3D, 4D, etc.). The only actual limit is the physical amount of RAM memory available on your computer. However, anything beyond 3D becomes extremely difficult for humans to conceptualize and track in code.

---

## Critical Warnings and Behaviors

### Out of Bounds
* **C is Lenient:** The C compiler does not check if the index you are requesting actually exists within the array's boundaries.
* **The Danger:** If you have an array of size 5 and you try to access or overwrite index `5` or `10`, C will not stop you. It will silently look into or alter whatever data happens to be stored next to your array in the RAM. This leads to dangerous bugs, segmentation faults, or corrupted data. Always ensure your loops stop before reaching index `n`.

### Size Alteration
* **Fixed Size:** Once an array is declared with a specific size, its size cannot be changed or resized during the execution of the program. If you need a flexible list that grows or shrinks dynamically, you cannot use standard arrays; you will need to handle memory manually using pointers and dynamic memory allocation (`malloc`).
