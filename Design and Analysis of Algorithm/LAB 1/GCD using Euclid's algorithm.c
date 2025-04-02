#include <stdio.h>

// Function to compute GCD using Euclid's algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main()
{
    int num1, num2;
    printf("\t****NISHAN DHAKAL****\n      **** Euclid's algorithm****\n\n");
    // Taking input from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Compute and print the GCD
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}
