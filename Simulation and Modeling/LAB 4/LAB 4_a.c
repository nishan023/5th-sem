#include <stdio.h>


void generate_random_numbers(int m, int a, int c, int X0, int n)
{
    int X = X0;
    printf("\nFirst %d random numbers generated:\n", n);
    for (int i = 0; i < n; i++)
    {
        X = (a * X + c) % m;
        printf("%d ", X);
    }
    printf("\n");
}

int main()
{
    int m, a, c, X0, n;
    printf("\t****NISHAN DHAKAL****\n\n  ");

    printf("Enter modulus (m): ");
    scanf("%d", &m);
    printf("Enter multiplier (a): ");
    scanf("%d", &a);
    printf("Enter increment (c): ");
    scanf("%d", &c);
    printf("Enter seed value (X0): ");
    scanf("%d", &X0);
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);


    generate_random_numbers(m, a, c, X0, n);

    return 0;
}