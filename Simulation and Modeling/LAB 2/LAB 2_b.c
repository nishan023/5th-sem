
#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    if (n == 0)
        return 1;
    double fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

double poisson_probability(int x, double lambda)
{
    return (pow(lambda, x) * exp(-lambda)) / factorial(x);
}

int main()
{
    double lambda;
    int max_x = 15;

    printf("\t****NISHAN DHAKAL****\n\n  ");

    printf("Enter the mean arrival rate (lambda): ");
    scanf("%lf", &lambda);

    printf("\nPoisson Distribution (Lambda = %.2f):\n", lambda);
    printf("X\tP(X)\n");

    for (int x = 0; x <= max_x; x++)
    {
        double probability = poisson_probability(x, lambda);
        printf("%d\t%.6f\n", x, probability);
    }

    return 0;
}
