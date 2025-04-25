#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TOTAL_POINTS 1000000

int main()
{
    printf("\t****NISHAN DHAKAL****\n\n  ");
    int i, inside_circle = 0;
    double x, y, pi_estimate;

    srand(time(NULL));

    for (i = 0; i < TOTAL_POINTS; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1)
        {
            inside_circle++;
        }
    }

    pi_estimate = 4.0 * inside_circle / TOTAL_POINTS;

    printf("Estimated value of Pi: %.6f\n", pi_estimate);

    return 0;
}
