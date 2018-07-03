#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    //declare variables
    long long cc_num, temp_cc, doublenum;
    int sum, product;

    // prompt user for cc number
    do
    {
        printf("Credit card number: ");
        cc_num = get_long_long();
    }
    while (cc_num < 0);

    // double every other digit starting from second to last
    for (doublenum = cc_num / 10, product = 0; doublenum > 0; doublenum /= 100)
    {
        // if doubling results in 2-digit product, separate digits and add to sum...
        if ((doublenum % 10) * 2 >= 10)
        {
            product += ((doublenum % 10) * 2) / 10;
            product += ((doublenum % 10) * 2) % 10;
        }
        // else if it's one digit, add to sum
        else
        {
            product += (doublenum % 10) * 2;
        }
    }

    // create another temp variable to push to sum, add remaining unused CC digits
    for (temp_cc = cc_num, sum = 0; temp_cc > 0; temp_cc /= 100)
    {
        sum += temp_cc % 10;
    }

    // add sum of every-other-digits to sum of the remaining digits
    int checksum = sum + product;


    // check type of card and number length is valid, else return invalid
    if (checksum % 10 == 0)
    {
        if ((cc_num >= 340000000000000 && cc_num < 350000000000000) || (cc_num >= 370000000000000 && cc_num < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if (cc_num >= 5100000000000000 && cc_num < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((cc_num >= 4000000000000 && cc_num < 5000000000000) || (cc_num >= 4000000000000000 && cc_num < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

