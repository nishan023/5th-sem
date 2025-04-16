#include <stdio.h>

float chi_square(int o[], int e[], int n)
{
    float chi = 0;
    for (int i = 0; i < n; i++)
        chi += ((o[i] - e[i]) * (o[i] - e[i])) / (float)e[i];
    return chi;
}

int main()
{
    int n;
    printf("Enter number of categories: ");
    scanf("%d", &n);

    int o[n], e[n];
    printf("Enter observed values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &o[i]);

    printf("Enter expected values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &e[i]);

    float result = chi_square(o, e, n);
    printf("Chi-Square Value = %.3f\n", result);
    return 0;
}
