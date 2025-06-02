#include <stdio.h>
#include <string.h>

#define MATRIX_SIZE 16
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

void convertToStateArray(char message[], int stateArray[])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        if (message[i] != '\0')
        {
            stateArray[i] = (int)message[i];
        }
        else
        {
            stateArray[i] = 0x00;
        }
    }
}

// Print the state array as a 4x4 hex matrix
void printStateArrayMatrixHex(int stateArray[])
{

    printf("State Array :\n");
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        for (int j = 0; j < MATRIX_COLS; j++)
        {
            int index = i * MATRIX_COLS + j;
            printf("%02X ", stateArray[index]);
        }
        printf("\n");
    }
}

int main()
{
    char message[MATRIX_SIZE + 1];
    int stateArray[MATRIX_SIZE];
    printf("\t****NISHAN DHAKAL****\n        ****State Array****\n\n");
    printf("Enter a 16-character message:  ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    convertToStateArray(message, stateArray);

    printStateArrayMatrixHex(stateArray);

    return 0;
}
