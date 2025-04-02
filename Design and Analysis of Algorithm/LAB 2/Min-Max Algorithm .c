#include <stdio.h>

// Function to find the minimum and maximum in an array
void findMinMax(int arr[], int n, int *min, int *max)
{
    *min = *max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < *min)
            *min = arr[i];
        if (arr[i] > *max)
            *max = arr[i];
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;

    printf("\t****NISHAN DHAKAL****\n      **** Min-Max Algorithm ****\n\n");
    // Taking input from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    printArray(arr, n);

    int min, max;
    findMinMax(arr, n, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
