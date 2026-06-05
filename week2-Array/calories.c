// C Practice: program to calculate dish calories.
// Stinker_Fish (github.com/stinkerfish8) - 2026

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, string argv[])
{
    // Check if the user provided at least one word for the dish name
    if (argc < 2)
    {
        printf("Usage: ./calories [name of the dish]\n");
        return 1;
    }

    // Print the title header
    printf("Calculate calories for: ");

    // Loop through all command-line arguments to print the full dish name
    for (int i = 1; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n\n");

    // Ask the user for the total number of ingredients
    int num = get_int("How many ingredients? ");
    printf("Usage: ingredient, grams, kcal/100g\n");

    float total_calories = 0.0;

    // Loop to get data for each ingredient
    for (int i = 0; i < num; i++)
    {
        string line;
        char name[50];
        int grams;
        float kcal_per_100g;

        // Input validation loop
        while (true)
        {
            // Prompt the user for the current ingredient (1-indexed for the user)
            line = get_string("#%i ingredient: ", i + 1);

            // Parse the input string and check if all 3 fields were successfully extracted
            if (sscanf(line, "%[^,], %d, %f", name, &grams, &kcal_per_100g) == 3)
            {
                break; // Valid input, exit the validation loop
            }

            // Print error message if the input format is incorrect
            printf("Invalid format! Please use: name, grams, kcal/100g\n");
        }

        // Calculate calories for the current ingredient using floating-point math
        float calories = (grams * kcal_per_100g) / 100.0;

        // Add the current ingredient's calories to the running total
        total_calories += calories;
    }

    // Print the final calorie report
    printf("-------------------\n");
    printf("Total calories: %.2f kcal\n", total_calories);

    return 0;
}
