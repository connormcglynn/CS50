#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float change;

    do
    {
        change = get_float("Change: "); // ask user for input
    }
    while (change < 0); // check for invalidity

    int changeAmt, numCoins; // initialize variables

    changeAmt = (int) round(change * 100); // convert to int from float

    numCoins = 0;

    while (changeAmt >= 25) // counts quarters
    {
        changeAmt -= 25; // reduces changeAmt by 25
        numCoins++; // adds a coin per quarter
    }

    while (changeAmt >= 10) // counts dimes
    {
        changeAmt -= 10; // reduces changeAmt by 10
        numCoins++; // adds a coin per dime
    }

    while (changeAmt >= 5) // counts nickels
    {
        changeAmt -= 5; // reduces changeAmt by 5
        numCoins++; // adds a coin per nickel
    }

    while (changeAmt >= 1) // counts pennies
    {
        changeAmt -= 1; // reduces changeAmt by 1
        numCoins++; // adds a coin per penny
    }

    printf("%i\n", numCoins); // returns number of coins

}