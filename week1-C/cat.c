#include <cs50.h>
#include <stdio.h>

/* --- THE WRONG WAY (Hardcoded)
   Repetitive and hard to maintain.

int main(void)
{
    printf("meow\n");
    printf("meow\n");
    printf("meow\n");
}
*/

/* --- THE INEFFICIENT WAY (While Loop)
   Functional, but manual. You have to handle initialization,
   condition, and increment (i++) separately.

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("Meow\n");
        i++;
    }
}
*/

/* --- FOR LOOP
   The standard way to repeat an action a specific number of times.
   Cleans up the code by putting the counter logic on one line.

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Meow\n");
    }
}
*/

/* --- INFINITE LOOP
   Use "while (true)" if you need a loop that runs forever.
   Requires <cs50.h> or <stdbool.h> for the 'true' keyword.

int main(void)
{
    while (true)
    {
        printf("Meow\n");
    }
}
*/

/* --- BREAKING AN INFINITE LOOP (Input Validation)
   Useful to force a specific user behavior.
   NOTE: Declare 'int n' outside the braces for a wider SCOPE,
   otherwise it won't be accessible to the code below the loop.

int main(void)
{
    int n;
    while (true)
    {
        // If 'n' was declared inside these braces, it would only exist
        // within the local SCOPE of the while loop.
        n = get_int("What's n? ");
        if (n > 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Meow\n");
    }
}
*/

/* --- DO-WHILE LOOP
   Use it when you need to execute the code block AT LEAST ONCE
   before checking the condition.

int main(void)
{
    int n;
    do
    {
        n = get_int("What's n? ");
    }
    while (n < 0);

    for (int i = 0; i < n; i++)
    {
        printf("Meow\n");
    }
}
*/

/* --- CUSTOM FUNCTIONS (Like "Pink Blocks" in Scratch)
   - void meow(void): 'void' means it returns no value, it only has a side effect.
   - void meow(int n): Includes a parameter to make the function flexible.
*/

// --- FUNCTION PROTOTYPE (or Signature)
// This tells the compiler the function exists before it is used.
// 1st 'void': The function returns nothing.
// 'int times': The function takes one integer as input.
void meow(int times);

int main(void) // 2nd void: The function takes no argument (no input)
{
    int n = get_int("What's n? ");
    meow(n);
}

// --- FUNCTION DEFINITION
void meow(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("Meow\n");
    }
}
