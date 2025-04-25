#include <stdio.h>

int main()
{
    double interarrival_time, service_time, lambda, mu;
    printf("\t****NISHAN DHAKAL****\n\n  ");

    printf("Enter the mean interarrival time (minutes): ");
    scanf("%lf", &interarrival_time);

    printf("Enter the mean service time (minutes): ");
    scanf("%lf", &service_time);

    lambda = 1.0 / interarrival_time;
    mu = 1.0 / service_time;

    if (lambda >= mu)
    {
        printf("The system is unstable (arrival rate >= service rate). Try different values.\n");
        return 1;
    }

    double P0 = 1 - (lambda / mu);
    double L = lambda / (mu - lambda);
    double W = 1 / (mu - lambda);

    printf("\nResults:\n");
    printf("Probability that a customer will not have to wait: %.2f\n", P0);
    printf("Expected number of customers in the bank: %.2f\n", L);
    printf("Expected time a customer spends in the bank: %.2f minutes\n", W);

    return 0;
}
