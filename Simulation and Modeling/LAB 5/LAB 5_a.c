#include <stdio.h>

void autocorrelation(float data[], int N, int k)
{
    float correlation = 0.0;

    for (int i = 0; i < N - k; i++)
    {
        correlation += data[i] * data[i + k];
    }

    correlation /= (N - k);

    printf("Autocorrelation at lag %d: %.4f\n", k, correlation);
}

int main()
{
    int N, k;
    printf("\t****NISHAN DHAKAL****\n\n  ");
    printf("Enter the number of data points (N): ");
    scanf("%d", &N);
    float data[N];
    printf("Enter the data points (float values):\n");
    for (int i = 0; i < N; i++)
    {
        printf("data[%d]: ", i);
        scanf("%f", &data[i]);
    }
    printf("Enter the lag value (k): ");
    scanf("%d", &k);

    if (k >= N || k < 0)
    {
        printf("Invalid lag value!\n");
        return 1;
    }

    autocorrelation(data, N, k);

    return 0;
}
