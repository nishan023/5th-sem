#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TOTAL_POINTS 1000000 // Number of random points

int main()
{
    printf("\t****NISHAN DHAKAL****\n\n  ");
    int i, inside_circle = 0;
    double x, y, pi_estimate;

    // Seed the random number generator
    srand(time(NULL));

    // Monte Carlo simulation
    for (i = 0; i < TOTAL_POINTS; i++)
    {
        x = (double)rand() / RAND_MAX; // Random x in [0,1]
        y = (double)rand() / RAND_MAX; // Random y in [0,1]

        // Check if point is inside the quarter-circle
        if (x * x + y * y <= 1)
        {
            inside_circle++;
        }
    }

    // Estimate Pi
    pi_estimate = 4.0 * inside_circle / TOTAL_POINTS;

    // Display result
    printf("Estimated value of Pi: %.6f\n", pi_estimate);

    return 0;
}
