# Calories Calculator

A simple and efficient C program to calculate the total caloric intake of a dish. It dynamically handles ingredients with compound names (e.g., spaces) and custom quantities.

## Demo

![Program Demo](demo.gif)
*Recorded with [asciinema](https://asciinema.org) and converted to GIF using [agg](https://github.com/asciinema/agg).*

## How to Run

1. Compile the program linking the CS50 library:
   ```bash
   gcc calories.c -lcs50 -o calories
2. Run the program by passing the dish name as an argument:
   ```bash
   ./calories Chickpea Pasta
