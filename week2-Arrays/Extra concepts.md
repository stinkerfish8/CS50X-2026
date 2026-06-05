# C Programming - Extra Concepts

This document collects advanced and extra concepts encountered during practical exercises, outside of standard lessons.

## ANSI Escape Codes

### What are they?
ANSI escape codes are special sequences of characters that you can include in your text output (such as inside a `printf` function). Instead of printing these characters literally, the terminal interprets them as commands to change the text formatting, move the cursor, or modify the console appearance.

### Style and Formatting Codes
To change the text style, the sequence always follows this specific structure:
1. **Initiator**: `\033[` (or `\e[` in some systems), which signals the start of an escape sequence.
2. **Style Parameter**: A specific number representing the visual change (e.g., bold, underline, colors).
3. **Terminator**: The letter `m`, which finishes the style command.

### The Importance of Reseating Styles
When you apply a style, it remains active for all subsequent print statements until you explicitly turn it off. To prevent the formatting from bleeding into the rest of your program's output, you must apply the **Reset Code** (`0`).

### Example: Making Text Bold
* **Bold Code**: `1` &rarr; Full sequence: `\033[1m`
* **Reset Code**: `0` &rarr; Full sequence: `\033[0m`

#### Code Snippet
```c
#include <stdio.h>

int main(void)
{
    // The terminal prints "Bold Text" in bold, then resets to normal
    printf("\033[1mBold Text\033[0m This text is back to normal.\n");
}
```
## Format Specifiers (Placeholders) & The Scanset Exclusion (`^`)

### Limiting Decimal Places
By default, the `%f` placeholder prints a floating-point number with 6 decimal places. To control the precision and reduce the number of decimals shown, you can insert a dot (`.`) followed by the desired number of digits between the `%` and the `f`.

* **Example (`%.2f`)**: Limits the output to exactly 2 decimal places and rounds the value automatically.

#### Code Snippet
```c
float price = 19.995;
printf("Total: $%.2f\n", price); // Outputs: Total: $20.00
```

### The Scanset Exclusion Operator (^)
​When reading strings with functions like sscanf, the standard %s placeholder stops reading at the first whitespace (space, tab, or newline). To read strings that contain spaces, you can use a scanset with the caret (^) symbol, which acts as a "read until" or "read everything except" operator.
​Syntax (%[^...]): Tells the program to read and store every character until it encounters any of the characters listed after the ^.


char input[] = "Delicious Chickpea Pasta, 350";
char dish_name[50];
int calories;

// Read everything EXCEPT a comma (%[^,]), then match the comma and space, then read the integer
sscanf(input, "%[^,], %d", dish_name, &calories); 

printf("Dish: %s\n", dish_name);   // Outputs: Dish: Delicious Chickpea Pasta
printf("Calories: %d\n", calories); // Outputs: Calories: 350





