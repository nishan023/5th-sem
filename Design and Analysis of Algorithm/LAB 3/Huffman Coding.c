#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode
{
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap
{
    unsigned size, capacity;
    struct MinHeapNode **array;
};

struct MinHeapNode *newNode(char data, unsigned freq)
{
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

void swap(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx)
    {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *node)
{
    minHeap->array[minHeap->size++] = node;
    for (int i = minHeap->size / 2 - 1; i >= 0; i--)
        minHeapify(minHeap, i);
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    minHeapify(minHeap, 0);
    return temp;
}

void printCodes(struct MinHeapNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right)
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void huffmanCoding(char data[], int freq[], int size)
{
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));

    while (minHeap->size > 1)
    {
        struct MinHeapNode *left = extractMin(minHeap);
        struct MinHeapNode *right = extractMin(minHeap);

        struct MinHeapNode *top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    int arr[100], top = 0;
    printCodes(extractMin(minHeap), arr, top);
}

int main()
{
    int size;
    printf("\t****NISHAN DHAKAL****\n      **** Huffman Coding ****\n\n");
    printf("Enter number of characters: ");
    scanf("%d", &size);

    char data[size];
    int freq[size];

    printf("Enter characters and their frequencies:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Character %d: ", i + 1);
        scanf(" %c", &data[i]);
        printf("Frequency %d: ", i + 1);
        scanf("%d", &freq[i]);
    }

    huffmanCoding(data, freq, size);
    return 0;
}
