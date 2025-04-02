#include <stdio.h>

int main()
{
    int m, a, c, X, n;
    printf("\t****NISHAN DHAKAL****\n\n  ");

    // User inputs
    printf("5 digit number means m should be 100000\n");
    printf("Enter modulus (m): ");
    scanf("%d", &m);
    printf("Enter multiplier (a): ");
    scanf("%d", &a);
    printf("Enter increment (c): ");
    scanf("%d", &c);
    printf("Enter seed value (X0): ");
    scanf("%d", &X);
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    printf("\nGenerated %d five-digit random integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        X = (a * X + c) % m; // Mixed Congruential Method formula
        printf("%05d ", X);  // Ensures 5-digit format
    }
    printf("\n");

    return 0;
}
