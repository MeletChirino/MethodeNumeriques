/* Example using log by TechOnTheNet.com */

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    /* Define temporary variables */
    double value;
    double result;

    /* Assign the value we will calculate the log of */
    value = 1.5;

    /* Calculate the log of the value */
    result = log(value);

    /* Display the result of the calculation */
    printf("The Natural Logarithm of %f is %f\n", value, result);

    return 0;
}
