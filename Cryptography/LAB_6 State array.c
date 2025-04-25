#include <stdio.h>
#include <string.h>

int main()
{
    char message[17]; // 16 chars + 1 for null terminator
    char state[4][4];
    int k = 0;
    printf("\t****NISHAN DHAKAL****\n        ****State Array****\n\n");
    printf("Enter a 16-character message: ");
    fgets(message, sizeof(message), stdin);

    // If user enters less than 16 characters, pad with spaces
    int len = strlen(message);
    if (len < 16)
    {
        for (int i = len; i < 16; i++)
        {
            message[i] = ' ';
        }
        message[16] = '\0'; // Null-terminate
    }

    // Fill state array column-wise
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 4; row++)
        {
            state[row][col] = message[k++];
        }
    }

    // Display state array
    printf("\nState Array:\n");
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            printf("%c ", state[row][col]);
        }
        printf("\n");
    }

    return 0;
}
