#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Permute bits according to a given table
void permute(const char *input, char *output, const int *table, int size)
{
    for (int i = 0; i < size; i++)
    {
        output[i] = input[table[i] - 1];
    }
    output[size] = '\0';
}

// Left circular shift for a 5-bit string
void leftShift(const char *half, char *result, int shifts)
{
    for (int i = 0; i < 5; i++)
    {
        result[i] = half[(i + shifts) % 5];
    }
    result[5] = '\0';
}

// Generate multiple subkeys
void generateSubKeys(const char *key10, int numKeys)
{
    int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    int P8[8] = {6, 3, 7, 4, 8, 5, 10, 9};

    char permutedKey[11];
    permute(key10, permutedKey, P10, 10);

    char left[6], right[6];
    strncpy(left, permutedKey, 5);
    left[5] = '\0';
    strncpy(right, permutedKey + 5, 5);
    right[5] = '\0';

    int totalShift = 0;

    for (int i = 1; i <= numKeys; i++)
    {
        int shift = (i == 1) ? 1 : 2;
        totalShift += shift;

        char lshifted[6], rshifted[6], combined[11], subkey[9];
        leftShift(left, lshifted, totalShift % 5);
        leftShift(right, rshifted, totalShift % 5);

        strcpy(left, lshifted);
        strcpy(right, rshifted);

        snprintf(combined, 11, "%s%s", lshifted, rshifted);
        permute(combined, subkey, P8, 8);

        printf("Subkey K%d: %s\n", i, subkey);
    }
}

int main()
{
    char key10[11];
    int numKeys;

    printf("\t****NISHAN DHAKAL****\n ****Sub generation for DES algorithm****\n\n");
    printf("Enter a 10-bit key (e.g. 1010000010): ");
    scanf("%10s", key10);

    // Validate input
    if (strlen(key10) != 10 || strspn(key10, "01") != 10 || key10[0] != '1')
    {
        printf("Invalid key. Key must be 10 bits, all 0s and 1s, and start with 1.\n");
        return 1;
    }

    printf("How many subkeys do you want to generate? ");
    scanf("%d", &numKeys);

    if (numKeys <= 0)
    {
        printf("Please enter a valid number greater than 0.\n");
        return 1;
    }

    generateSubKeys(key10, numKeys);

    return 0;
}
