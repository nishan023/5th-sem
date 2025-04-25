#include <stdio.h>

// Function to implement Extended Euclidean Algorithm
int extendedGCD(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

// Function to find multiplicative inverse
int multiplicativeInverse(int a, int m)
{
    int x, y;
    int gcd = extendedGCD(a, m, &x, &y);

    if (gcd != 1)
    {
        // Inverse does not exist if gcd is not 1
        return -1;
    }
    else
    {
        // Make sure x is positive
        return (x % m + m) % m;
    }
}

int main()
{
    int a, m;
    printf("\t****NISHAN DHAKAL****\n ****Multiplicative Inverse****\n\n");
    printf("Enter number and modulo value:\n");
    printf("a = ");
    scanf("%d", &a);
    printf("m = ");
    scanf("%d", &m);

    int inverse = multiplicativeInverse(a, m);
    if (inverse == -1)
    {
        printf("Multiplicative inverse does NOT exist for %d modulo %d.\n", a, m);
    }
    else
    {
        printf("Multiplicative inverse of %d modulo %d is: %d\n", a, m, inverse);
    }
    return 0;
}
