#include <stdio.h>

// Permutation tables
int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int P8[8] = {6, 3, 7, 4, 8, 5, 10, 9};

// Function to apply permutation
void permute(int input[], int output[], int perm[], int n) {
    for (int i = 0; i < n; i++) {
        output[i] = input[perm[i] - 1];
    }
}

// Function for left shift
void leftShift(int key[], int shifts, int size) {
    for (int s = 0; s < shifts; s++) {
        int temp = key[0];
        for (int i = 0; i < size - 1; i++) {
            key[i] = key[i + 1];
        }
        key[size - 1] = temp;
    }
}

int main() {
    int key[10], permutedKey[10], left[5], right[5], combined[10], subKey1[8], subKey2[8];
    printf("\t****NISHAN DHAKAL****\n ****Sub generation for DES algorithm****\n\n");
    printf("Enter 10-bit key (space-separated): ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &key[i]);
    }

    // Step 1: Apply P10 permutation
    permute(key, permutedKey, P10, 10);

    // Step 2: Split into two halves
    for (int i = 0; i < 5; i++) {
        left[i] = permutedKey[i];
        right[i] = permutedKey[i + 5];
    }

    // Step 3: Left shift both halves by 1
    leftShift(left, 1, 5);
    leftShift(right, 1, 5);

    // Step 4: Combine halves
    for (int i = 0; i < 5; i++) {
        combined[i] = left[i];
        combined[i + 5] = right[i];
    }

    // Step 5: Apply P8 to generate Subkey 1
    permute(combined, subKey1, P8, 8);

    // Step 6: Left shift both halves by 2
    leftShift(left, 2, 5);
    leftShift(right, 2, 5);

    // Step 7: Combine halves again
    for (int i = 0; i < 5; i++) {
        combined[i] = left[i];
        combined[i + 5] = right[i];
    }

    // Step 8: Apply P8 to generate Subkey 2
    permute(combined, subKey2, P8, 8);

    // Print the subkeys
    printf("Subkey 1 (K1): ");
    for (int i = 0; i < 8; i++) {
        printf("%d", subKey1[i]);
    }
    printf("\n");

    printf("Subkey 2 (K2): ");
    for (int i = 0; i < 8; i++) {
        printf("%d", subKey2[i]);
    }
    printf("\n");

    return 0;
}
