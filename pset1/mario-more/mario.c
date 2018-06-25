#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: "); // get height from user
    }
    while (height < 0 || height > 23);

    int i, j, k;
    for (i = 1; i <= height; i++) // make lines
    {
        for (j = 0; j < (height - i); j++)
        {
            printf(" "); // prints spaces
        }
        for (k = 0; k < i; k++)
        {
            printf("#"); // prints hashes
        }
        printf("  "); // divides the stairs

        for (k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n"); // creates newlines
    }
    return 0;
}