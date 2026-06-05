// C Practice: program to calculate triangle properties.
// To test the code, install the cs50 library or run it on cs50.dev
// Stinker_Fish (github.com/stinkerfish8) - 2026

#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define M_PI 3.1415926

bool valid_triangle(float x, float y, float z);
float triangle_area(float x, float y, float z);
float perimeter(float x, float y, float z);
float triangle_angle(float x, float y, float z, char target);
void triangle_type(float x, float y, float z);
void print_ascii_triangle(void);

int main(void)
{
    float x = 0;
    float y = 0;
    float z = 0;

    char next;
    print_ascii_triangle();
    printf("Provide the sides of your triangle:\n");
    printf("---------------------------\n");
    // Loop to prompt for sides until they form a valid triangle.
    do
    {
        x = get_float("Get x: ");
        y = get_float("Get y: ");
        z = get_float("Get z: ");
    }
    while (!(valid_triangle(x, y, z)));
    printf("---------------------------\n");
    do
    {
        char choice;
        do
        {
            choice = get_char("WHAT DO YOU WANT TO DO?\nType A: Calculate area\nType B: Calculate "
                              "perimeter\nType C: "
                              "Calculate angle\nType D: Determine triangle type\nType E: Terminate "
                              "the program\n");
        }
        while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b' && choice != 'C' &&
               choice != 'c' && choice != 'D' && choice != 'd' && choice != 'E' && choice != 'e');

        // Calculate area.
        if (choice == 'A' || choice == 'a')
        {
            float area = triangle_area(x, y, z);
            printf("Area is: %f\n", area);
        }
        // Calculate perimeter.
        else if (choice == 'B' || choice == 'b')
        {
            float perim = perimeter(x, y, z);
            printf("Perimeter is: %f\n", perim);
        }
        else if (choice == 'C' || choice == 'c')
        {
            char angle_choice;
            do
            {
                angle_choice =
                    get_char("Which angle do you want to calculate?\nType X: Angle opposite to "
                             "x.\nType Y: Angle opposite to y.\nType Z: Angle opposite to z.\n");
            }
            while (angle_choice != 'X' && angle_choice != 'x' && angle_choice != 'Y' &&
                   angle_choice != 'y' && angle_choice != 'Z' && angle_choice != 'z');
            float angle = triangle_angle(x, y, z, angle_choice);
            printf("The angle opposite to %c measures %f degrees.\n", angle_choice, angle);
        }
        // Determines the triangle type.
        else if (choice == 'D' || choice == 'd')
        {
            triangle_type(x, y, z);
        }
        // Terminate program.
        else if (choice == 'E' || choice == 'e')
        {
            return 0;
        }
        do
        {
            next = get_char("Do you want to know anything else? Y/N ");
        }
        while (next != 'Y' && next != 'y' && next != 'N' && next != 'n');
    }
    while (next == 'Y' || next == 'y');
    return 0;
}

// --- FUNCTIONS
// 1- Determines if the provided numbers can form a valid triangle.
bool valid_triangle(float x, float y, float z)
{
    if (x > 0 && y > 0 && z > 0 && x + y > z && y + z > x && x + z > y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 2- Calculates the triangle's area using Heron's formula.
float triangle_area(float x, float y, float z)
{
    // Calculate the semiperimeter using the perimeter function.
    float p = perimeter(x, y, z) / (float) 2;

    // Calculate the area.
    float area = sqrt(p * (p - x) * (p - y) * (p - z));

    return area;
}

// 3- Calculates the perimeter of the triangle.
float perimeter(float x, float y, float z)
{
    return x + y + z;
}

// 4- Calculate the triangle angle.
float triangle_angle(float x, float y, float z, char target)
{
    if (target == 'x' || target == 'X')
    {
        float angle = acos((y * y + z * z - x * x) / (2 * y * z)) * (180.0 / M_PI);
        return angle;
    }
    else if (target == 'y' || target == 'Y')
    {
        float angle = acos((x * x + z * z - y * y) / (2 * x * z)) * (180.0 / M_PI);
        return angle;
    }
    else
    {
        float angle = acos((x * x + y * y - z * z) / (2 * x * y)) * (180.0 / M_PI);
        return angle;
    }
}

// 5- Determines the triangle type.
void triangle_type(float x, float y, float z)

{
    // Equilateral Triangle (all sides are equal)
    if (x == y && y == z)
    {
        printf("This is an equilateral triangle.\n");
    }
    // Isosceles Triangle (x = y || y = z || x = z)
    else if (x == y || y == z || x == z)
    {
        printf("This is an isosceles triangle.\n");
    }
    // Scalene Triangle (all three sides are different)
    else
    {
        printf("This is a scalene triangle.\n");
    }
}

// 6- Print ASCII art triangle.
void print_ascii_triangle(void)
{
    printf("       /\\\n");
    printf("      /  \\\n");
    printf("     /    \\\n");
    printf("    /      \\\n");
    printf("   /________\\\n\n");
}
