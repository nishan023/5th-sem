#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

int main()
{
    int n;
    printf("\t****NISHAN DHAKAL****\n\n  ");
    printf("Enter number of data points: ");
    scanf("%d", &n);
    float x[n];
    printf("Enter %d values (between 0 and 1):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);

    qsort(x, n, sizeof(float), cmp);
    float d = 0;
    for (int i = 0; i < n; i++)
    {
        float d1 = (i + 1.0) / n - x[i];
        float d2 = x[i] - (i * 1.0) / n;
        if (d1 > d)
            d = d1;
        if (d2 > d)
            d = d2;
    }
    printf("D = %f\n", d);
    return 0;
}
