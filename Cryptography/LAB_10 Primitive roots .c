#include <stdio.h>

// Function to check if an array contains a given number
int contains(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
            return 1;
    }
    return 0;
}

// Function to check if 'a' is a primitive root modulo 'p'
int is_primitive_root(int a, int p)
{
    if (a <= 0 || p <= 0)
        return -1;

    int arr[p - 1];
    int size = 0;

    long long temp = 1;
    for (int i = 0; i < p - 1; i++)
    {
        temp = (temp * a) % p;
        printf("%d^%d mod %d = %lld\n", a, i + 1, p, temp);

        if (contains(arr, size, temp))
        {
            return -1;
        }
        arr[size++] = temp;
    }

    return 1;
}

int main()
{
    int a, p;
    printf("\t****NISHAN DHAKAL****\n      ****Primitive Root****\n\n");
    printf("Enter a number a: ");
    scanf("%d", &a);
    printf("Enter prime number p: ");
    scanf("%d", &p);

    int primitive_root = is_primitive_root(a, p);
    if (primitive_root == 1)
        printf("%d is a primitive root of %d\n", a, p);
    else
        printf("%d is not a primitive root of %d\n", a, p);

    return 0;
}
