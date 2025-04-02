// Write a program to test the prime numbers using Fermat’s theorem.
#include <stdio.h>
#include <math.h>
// Function to check Fermat's Theorem for primality test
int fermatsTheorem(int a, int p)
{
    int res = pow(a, p - 1);
    printf("\n");
    // Check if a^(p-1) mod p == 1 (Fermat's Theorem)
    if (res % p == 1)
    {
        printf(" Fermat's Theorem Check Passed!\n");
        printf("Since %d^(%d-1) mod %d = %d i.e. is equal to 1 \n", a, p, p, res % p);
        printf("   It suggests that %d might be a prime number.\n", p);
    }
    else
    {
        printf(" Fermat's Theorem Check Failed!\n");
        printf("    Since %d^(%d-1) mod %d = %d i.e. not equal to 1 \n", a, p, p, res % p);
        printf("   This indicates that %d is definitely NOT a prime number.\n", p);
    }
}

int main()
{
    int a, p;
    printf("\t****NISHAN DHAKAL****\n*****Fermat's Theorem*****\n\n");
    printf("\nEnter a number(p) to check whether it is prime or not: ");
    scanf("%d", &p);
    printf("\nEnter an integer(a) which is less than %d: ", p);
    scanf("%d", &a);
    fermatsTheorem(a, p);
}
