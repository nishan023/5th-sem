#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gapTest(int data[], int N)
{
    int gaps[10] = {0};

    for (int i = 0; i < N - 1; i++)
    {
        int gap = data[i + 1] - data[i];
        if (gap >= 0 && gap < 10)
        {
            gaps[gap]++;
        }
    }

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
    printf("Enter the number of data points (N): ");
    scanf("%d", &N);
    if (N <= 1)
    {
        printf("Number of data points must be greater than 1.\n");
        return 1;
    }

    int data[N];
    srand(time(0));

    printf("Generated random data points:\n");
    for (int i = 0; i < N; i++)
    {
        data[i] = rand() % 100;
        printf("data[%d]: %d\n", i, data[i]);
    }
    gapTest(data, N);

    return 0;
}
