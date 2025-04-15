#include <stdio.h>

// Function to calculate autocorrelation at lag k
void autocorrelation(float data[], int N, int k)
{
    float correlation = 0.0;

    // Compute autocorrelation for lag k
    for (int i = 0; i < N - k; i++)
    {
        correlation += data[i] * data[i + k];
    }

    correlation /= (N - k); // Normalize by the number of terms

    printf("Autocorrelation at lag %d: %.4f\n", k, correlation);
}

int main()
{
    int N, k;
    printf("\t****NISHAN DHAKAL****\n\n  ");

    // Input number of data points
    printf("Enter the number of data points (N): ");
    scanf("%d", &N);

    // Declare and input the data array
    float data[N];
    printf("Enter the data points (float values):\n");
    for (int i = 0; i < N; i++)
    {
        printf("data[%d]: ", i);
        scanf("%f", &data[i]);
    }

    // Input lag value k
    printf("Enter the lag value (k): ");
    scanf("%d", &k);

    // Check if k is valid
    if (k >= N || k < 0)
    {
        printf("Invalid lag value!\n");
        return 1;
    }

    // Calculate autocorrelation for the given lag
    autocorrelation(data, N, k);

    return 0;
}
