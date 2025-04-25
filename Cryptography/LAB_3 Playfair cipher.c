#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to prepare the Playfair cipher key matrix
void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE])
{
    int used[26] = {0}; // Track which letters are used
    int k = 0;

    // Replace 'J' with 'I' in the key
    for (int i = 0; key[i]; i++)
    {
        if (key[i] == 'J')
            key[i] = 'I';
    }

    // Fill matrix with key (skipping duplicates)
    for (int i = 0; key[i]; i++)
    {
        if (!used[key[i] - 'A'])
        {
            keyMatrix[k / SIZE][k % SIZE] = key[i];
            used[key[i] - 'A'] = 1;
            k++;
        }
    }

    // Fill remaining spots with unused letters
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (c == 'J')
            continue; // Skip 'J'
        if (!used[c - 'A'])
        {
            keyMatrix[k / SIZE][k % SIZE] = c;
            used[c - 'A'] = 1;
            k++;
        }
    }
}

// Format the message: replace J->I, insert X between duplicates, handle odd length
void formatMessage(char message[])
{
    int len = strlen(message);

    // Replace 'J' with 'I'
    for (int i = 0; i < len; i++)
    {
        if (message[i] == 'J')
            message[i] = 'I';
    }

    // Insert 'X' between duplicate letters in a pair
    for (int i = 0; i < len - 1; i += 2)
    {
        if (message[i] == message[i + 1])
        {
            for (int j = len; j > i + 1; j--)
            {
                message[j] = message[j - 1]; // Shift right
            }
            message[i + 1] = 'X';
            len++;
        }
    }

    // If the length is odd, append 'X'
    if (len % 2 != 0)
    {
        message[len] = 'X';
        message[len + 1] = '\0';
    }
}

// Find the position of a letter in the key matrix
void findPosition(char keyMatrix[SIZE][SIZE], char c, int *row, int *col)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (keyMatrix[i][j] == c)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Encrypt the message using Playfair cipher rules
void encrypt(char message[], char keyMatrix[SIZE][SIZE])
{
    for (int i = 0; message[i] && message[i + 1]; i += 2)
    {
        int r1, c1, r2, c2;
        findPosition(keyMatrix, message[i], &r1, &c1);
        findPosition(keyMatrix, message[i + 1], &r2, &c2);

        if (r1 == r2)
        { // Same row
            message[i] = keyMatrix[r1][(c1 + 1) % SIZE];
            message[i + 1] = keyMatrix[r2][(c2 + 1) % SIZE];
        }
        else if (c1 == c2)
        { // Same column
            message[i] = keyMatrix[(r1 + 1) % SIZE][c1];
            message[i + 1] = keyMatrix[(r2 + 1) % SIZE][c2];
        }
        else
        { // Rectangle swap
            message[i] = keyMatrix[r1][c2];
            message[i + 1] = keyMatrix[r2][c1];
        }
    }
}

// Decrypt the message using Playfair cipher rules
void decrypt(char message[], char keyMatrix[SIZE][SIZE])
{
    for (int i = 0; message[i] && message[i + 1]; i += 2)
    {
        int r1, c1, r2, c2;
        findPosition(keyMatrix, message[i], &r1, &c1);
        findPosition(keyMatrix, message[i + 1], &r2, &c2);

        if (r1 == r2)
        { // Same row
            message[i] = keyMatrix[r1][(c1 - 1 + SIZE) % SIZE];
            message[i + 1] = keyMatrix[r2][(c2 - 1 + SIZE) % SIZE];
        }
        else if (c1 == c2)
        { // Same column
            message[i] = keyMatrix[(r1 - 1 + SIZE) % SIZE][c1];
            message[i + 1] = keyMatrix[(r2 - 1 + SIZE) % SIZE][c2];
        }
        else
        { // Rectangle swap
            message[i] = keyMatrix[r1][c2];
            message[i + 1] = keyMatrix[r2][c1];
        }
    }
}

int main()
{
    char key[26], message[100];
    char keyMatrix[SIZE][SIZE];

    printf("\t****NISHAN DHAKAL****\n      ****Playfair Cipher****\n\n");
    printf("Enter the key (uppercase letters only): ");
    scanf("%s", key);
    printf("Enter the message (uppercase letters only): ");
    scanf("%s", message);

    prepareKeyMatrix(key, keyMatrix);
    formatMessage(message);

    printf("\nKey Matrix:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", keyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nFormatted Message: %s\n", message);

    encrypt(message, keyMatrix);
    printf("Encrypted Message: %s\n", message);

    decrypt(message, keyMatrix);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
