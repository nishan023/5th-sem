// #include <stdio.h>
// #include <math.h>

// #define LAMBDA 12 // Average arrival rate (cars per hour)
// #define MAX_X 15  // Maximum value of x

// // Function to compute factorial
// double factorial(int n)
// {
//     if (n == 0)
//         return 1;
//     double fact = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         fact *= i;
//     }
//     return fact;
// }

// // Function to compute Poisson probability
// double poisson_probability(int x, double lambda)
// {
//     return (pow(lambda, x) * exp(-lambda)) / factorial(x);
// }

// int main()
// {
//     printf("Poisson Distribution (Lambda = %d):\n", LAMBDA);
//     printf("X\tP(X)\n");

//     for (int x = 0; x <= MAX_X; x++)
//     {
//         double probability = poisson_probability(x, LAMBDA);
//         printf("%d\t%.6f\n", x, probability);
//     }

//     return 0;
// }

#include <stdio.h>
#include <math.h>

// Function to compute factorial
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

// Function to compute Poisson probability
double poisson_probability(int x, double lambda)
{
    return (pow(lambda, x) * exp(-lambda)) / factorial(x);
}

int main()
{
    double lambda;
    int max_x = 15; // We compute for x = 0 to 15

    printf("\t****NISHAN DHAKAL****\n\n  ");
    // User input
    printf("Enter the mean arrival rate (lambda): ");
    scanf("%lf", &lambda);

    // Display results
    printf("\nPoisson Distribution (Lambda = %.2f):\n", lambda);
    printf("X\tP(X)\n");

    for (int x = 0; x <= max_x; x++)
    {
        double probability = poisson_probability(x, lambda);
        printf("%d\t%.6f\n", x, probability);
    }

    return 0;
}
