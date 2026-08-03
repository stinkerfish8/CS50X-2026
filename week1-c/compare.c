#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // PROMPT: Asking the user for input using the CS50 library
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    // MUTUALLY EXCLUSIVE CONDITIONS
    // Using 'else if' is more efficient than multiple 'if' statements.
    // As soon as one condition is true, the rest are skipped.
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    /* Optimization: If x is not less than y AND not greater than y,
       the only mathematical possibility left is that they are equal.
       Therefore, a simple 'else' is enough.
    */
    else
    {
        printf("x is equal to y\n");
    }
}
