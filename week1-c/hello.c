/*-------------------------------------------------------------------------
  HELLO WORLD BASICS
-------------------------------------------------------------------------*/
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}

/*
  TERMINOLOGY & SHORTCUTS:
  GUI = Graphical User Interface
  CLI = Command Line Interface (The terminal)
  $   = Shell prompt (indicates the terminal is ready for a command)

  PRINTF DETAILS:
  The 'f' in printf stands for "Formatted".
  \n  = Newline character.
  \" \' \\ = Escape sequences used to print special characters.
  Ctrl+L   = Shortcut to clear the terminal screen.

  WORKFLOW:
  1. CREATE/EDIT: code hello.c
  2. COMPILE:     make hello
  3. RUN:         ./hello

  Note: If you change the source code, you must RECOMPILE before running again.

  LIBRARIES & DOCUMENTATION:
  Files ending in .h are Header Files (libraries).
  stdio.h: Standard Input/Output library (contains printf).
  manual.cs50.io: Official documentation for functions and libraries.
*/

/*-------------------------------------------------------------------------
  INPUT AND VARIABLES
-------------------------------------------------------------------------*/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Syntax: type variableName = value;
    // get_string is a CS50 library function.
    string answer = get_string("What's your name? ");

    // %s is a "Format Specifier" (placeholder) for a string.
    printf("hello, %s\n", answer);
}

/*
  COMMON LINUX COMMANDS:
  ls    = List files in the current directory.
  cd    = Change directory (e.g., cd notes/).
  mkdir = Make a new directory.
  cp    = Copy a file (cp source destination).
  mv    = Move or Rename a file (mv source destination).
  rm    = Remove/Delete a file.
  rmdir = Remove an empty directory.
  ..    = Represents the parent directory (one level up).
  ./    = Execute a program in the current directory.
*/

/*-------------------------------------------------------------------------
  CONTROL FLOW (CONDITIONALS)
-------------------------------------------------------------------------*/
// The space before the parenthesis indicates this is a "Control Statement", not a function.
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else // Implicitly means x == y; no further condition is needed.
{
    printf("x is equal to y\n");
}

/*
  OPERATORS:
  Assignment: =
  Comparison: == (equal), != (not equal), <, <=, >, >=
  Syntactic Sugar: counter++ (increments value by 1).

  DATA TYPES & PRECISION:
  bool:   Boolean (true/false).
  char:   Single character.
  int:    32-bit integer (up to ~2 billion).
  long:   64-bit integer (for much larger numbers).
  float:  32-bit "Floating Point" (decimal numbers with limited precision).
  double: 64-bit decimal (double precision).
  string: A sequence of characters.

  CS50 INPUT FUNCTIONS:
  get_char, get_double, get_float, get_int, get_long, get_string

  FORMAT SPECIFIERS:
  %c  = char
  %f  = float / double
  %i  = int
  %li = long (long int)
  %s  = string
*/
