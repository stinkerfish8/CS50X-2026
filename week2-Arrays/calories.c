// C Practice: program to calculate dish calories with custom functions.
// To test the code, install the cs50 library or run it on cs50.dev
// Stinker_Fish (github.com/stinkerfish8) - 2026

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

void print_title(int argc, string argv[]);
float get_ingredient(int index, char name[]);
void print_report(int argc, string argv[], int num, char names[][50], float calories[], float total);

int main(int argc, string argv[])
{
    // Check if the user provided at least one word for the dish name
    if (argc < 2)
    {
        printf("Usage: ./calories [name of the dish]\n");
        return 1;
    }

    // Ask the user for the total number of ingredients
    int num = get_int("How many ingredients in your dish? ");
    printf("Usage: name, grams, kcal/100g\n\n");

    // Arrays to store data for the final output report
    char saved_names[num][50];
    float saved_calories[num];
    float total_calories = 0.0;

    // Loop to gather data using the custom input function
    for (int i = 0; i < num; i++)
    {
        // get_ingredient gets and validates input, saves the name, and returns the calories
        saved_calories[i] = get_ingredient(i, saved_names[i]);
        total_calories += saved_calories[i];
    }

    // Print the final summary using the custom report function
    print_report(argc, argv, num, saved_names, saved_calories, total_calories);

    return 0;
}

// --- FUNCTIONS
// Prints the dish title header in BOLD using ANSI escape codes.
void print_title(int argc, string argv[])
{
    printf("Calories report for: \033[1m");
    for (int i = 1; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\033[0m\n");
}

// Prompts the user, validates the format, stores the ingredient name, and returns its calories.
float get_ingredient(int index, char name[])
{
    string line;
    int grams;
    float kcal_per_100g;

    while (true)
    {
        line = get_string("#%i ingredient: ", index + 1);

        // Parse the input directly into the temporary variables and the name array
        if (sscanf(line, "%[^,], %d, %f", name, &grams, &kcal_per_100g) == 3)
        {
            break; 
        }

        printf("Invalid format! Please use: name, grams, kcal/100g\n");
    }

    // Return the calculated calories
    return (grams * kcal_per_100g) / 100.0;
}

// Prints the formatted final summary with all ingredients and the grand total.
void print_report(int argc, string argv[], int num, char names[][50], float calories[], float total)
{
    printf("\n===================================\n");
    print_title(argc, argv);
    printf("===================================\n");

    // Loop through the arrays to print every saved ingredient
    for (int i = 0; i < num; i++)
    {
        printf("- %s: %.2f kcal\n", names[i], calories[i]);
    }

    // Print the final line and the total in bold
    printf("-----------------------------------\n");
    printf("Total calories: \033[1m%.2f kcal\033[0m\n", total);
    printf("===================================\n");
}
