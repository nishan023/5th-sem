#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform the gap test
void gapTest(int data[], int N)
{
    int gaps[10] = {0}; // Array to store the counts of gaps

    // Count the gaps between the values
    for (int i = 0; i < N - 1; i++)
    {
        int gap = data[i + 1] - data[i];
        if (gap >= 0 && gap < 10)
        {
            gaps[gap]++;
        }
    }

    // Output the gap distribution
    printf("\nGap Test Distribution (number of occurrences of each gap size):\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Gap size %d: %d occurrences\n", i, gaps[i]);
    }
}

int main()
{
    int N;
    printf("\t****NISHAN DHAKAL****\n\n  ");

    // Get user input for the number of data points
    printf("Enter the number of data points (N): ");
    scanf("%d", &N);

    // Check for valid N
    if (N <= 1)
    {
        printf("Number of data points must be greater than 1.\n");
        return 1;
    }

    int data[N];
    srand(time(0)); // Seed for random number generation

    // Generate random data points
    printf("Generated random data points:\n");
    for (int i = 0; i < N; i++)
    {
        data[i] = rand() % 100; // Random numbers between 0 and 99
        printf("data[%d]: %d\n", i, data[i]);
    }

    // Perform the gap test
    gapTest(data, N);

    return 0;
}
