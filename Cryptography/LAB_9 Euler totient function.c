#include <stdio.h>

// Function to compute GCD using Euclid's algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute Euler's Totient Function
int eulerTotient(int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (gcd(i, n) == 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int num;
    printf("\t****NISHAN DHAKAL****\n ****Euler totient function****\n\n");
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num <= 0)
    {
        printf("Please enter a positive integer.\n");
    }
    else
    {
        int result = eulerTotient(num);
        printf("Euler's Totient Function of (%d) = %d\n", num, result);
    }
    return 0;
}
