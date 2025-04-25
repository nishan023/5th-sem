#include <stdio.h>

int main()
{
    int m, a, X, n;

    printf("\t****NISHAN DHAKAL****\n\n  ");

    printf("3 digit number means m should be 1000\n");
    printf("Enter modulus (m): ");
    scanf("%d", &m);
    printf("Enter multiplier (a): ");
    scanf("%d", &a);
    printf("Enter seed value (X0): ");
    scanf("%d", &X);
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    printf("\nGenerated %d three-digit random integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        X = (a * X) % m;
        printf("%03d ", X % 1000);
    }
    printf("\n");

    return 0;
}
