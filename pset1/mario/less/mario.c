#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    int i, j, k;
    for (i = 0; i < height; i++) // make lines
    {
        for (j = (height - i); j > 1; j--)
        {
            printf(" "); // prints spaces
        }
        for (k = 0; k < (i + 2); k++)
        {
            printf("#"); // prints hashes
        }
        printf("\n"); // creates newlines
    }
    return 0;
}