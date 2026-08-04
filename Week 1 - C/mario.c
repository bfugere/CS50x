#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int height;
    do
    {
        // Prompt the user for the pyramid's height
        height = get_int("Height? ");
    }
    while (height < 1 || height > 8);

    // Print a pyramid of the set height
    for (int row = 0; row < height; row++)
    {
        // Print a row of bricks
        print_row(height - (row + 1), row + 1);
    }
}

void print_row(int spaces, int bricks)
{
    // Print blank spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // Print row of bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    printf("\n");
}
