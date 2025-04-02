#include <stdio.h>
#include <string.h>
#define MAX 100

//  Function to create Rail Fence pattern
void createRailFence(char *text, int rails, char rail[][MAX])
{
    int len = strlen(text);
    int row = 0, dir_down = 0;

    // Initialize the matrix
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = ' ';

    // Build the zig-zag pattern
    for (int i = 0; i < len; i++)
    {
        rail[row][i] = text[i];
        if (row == 0)
            dir_down = 1;
        else if (row == rails - 1)
            dir_down = 0;

        row += dir_down ? 1 : -1;
    }
}

//  Function to print the Rail Fence matrix with box graphics
void printRailFence(char rail[][MAX], int rails, int len)
{
    printf("\n========== Rail Fence Cipher ==========\n");

    // Print top horizontal border
    for (int j = 0; j < len; j++)
        printf("*---");
    printf("+\n");

    // Print characters row by row with vertical lines
    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("| %c ", rail[i][j]);
        }
        printf("|\n");

        // Print horizontal border after each row
        for (int j = 0; j < len; j++)
            printf("*---");
        printf("*\n");
    }
}

//  Function to perform Encryption
void encrypt(char *text, int rails)
{
    char rail[rails][MAX];
    createRailFence(text, rails, rail);
    int len = strlen(text);

    // Print the rail fence pattern
    printRailFence(rail, rails, len);

    // Read the rail row-wise to get the ciphertext
    printf("\n Encrypted Message: ");
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != ' ')
                printf("%c", rail[i][j]);
    printf("\n");
}

//  Function to perform Decryption
void decrypt(char *cipher, int rails)
{
    int len = strlen(cipher);
    char rail[rails][MAX];
    int i, j, index = 0;

    // Initialize the rail matrix
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = ' ';

    // Mark the zig-zag positions with '*'
    int row = 0, dir_down;
    for (i = 0; i < len; i++)
    {
        if (row == 0)
            dir_down = 1;
        if (row == rails - 1)
            dir_down = 0;
        rail[row][i] = '*';
        row += dir_down ? 1 : -1;
    }

    // Fill the cipher text into the marked positions
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = cipher[index++];

    // Print the rail fence pattern
    printRailFence(rail, rails, len);

    // Read the matrix in zig-zag order to decrypt
    printf("\n Decrypted Message: ");
    row = 0;
    for (i = 0; i < len; i++)
    {
        if (row == 0)
            dir_down = 1;
        if (row == rails - 1)
            dir_down = 0;
        if (rail[row][i] != ' ')
            printf("%c", rail[row][i]);
        row += dir_down ? 1 : -1;
    }
    printf("\n");
}

//  Main Function
int main()
{
    char text[MAX], cipher[MAX];
    int rails;
    printf("\t****NISHAN DHAKAL****\n*****Rail-Fence Cipher*****\n\n");
    printf(" Enter the message : ");
    scanf("%s", text);

    printf(" Enter the number of rails: ");
    scanf("%d", &rails);

    // Perform encryption
    encrypt(text, rails);

    printf("\n Enter the cipher text for decryption: ");
    scanf("%s", cipher);

    // Perform decryption
    decrypt(cipher, rails);

    return 0;
}
