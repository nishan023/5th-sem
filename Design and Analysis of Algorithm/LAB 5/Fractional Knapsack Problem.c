#include <stdio.h>

typedef struct
{
    int weight;
    int value;
    float ratio;
} Item;

int compare(const void *a, const void *b)
{
    return ((Item *)b)->ratio - ((Item *)a)->ratio; // Sort in descending order
}

void fractionalKnapsack(int W, Item items[], int n)
{
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    float totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= W)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    printf("Total value in knapsack = %.2f\n", totalValue);
}

int main()
{
    int W, n;
    printf("\n\t****NISHAN DHAKAL****\n      **** Fractional Knapsack Problem ****\n\n");

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    fractionalKnapsack(W, items, n);

    return 0;
}
