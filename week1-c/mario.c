#include <stdio.h>

/*
// EXAMPLE OF CODE WITH HARDCODED VALUE
// The number 4 is "hardcoded" (fixed). It makes the code less flexible.
int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("? ");
    }
    printf("\n");
}
*/

int main(void)
{
    // A constant is a variable whose value cannot be changed after initialization.
    // If you try to modify it later, the compiler will return an error.
    // Convention: Use UPPERCASE for constants (N instead of n).
    const int N = 3;

    // NESTED LOOPS
    // OUTER LOOP: For each row
    for (int row = 0; row < N; row++)
    {
        // INNER LOOP: For each column
        for (int column = 0; column < N; column++)
        {
            // Print one brick/character
            printf("#");
        }

        // Print a newline character to move to the next row
        printf("\n");
    }
}
