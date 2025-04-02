#include <stdio.h>
#include <stdlib.h>

void strassenMultiply(int A[2][2], int B[2][2], int C[2][2])
{
    int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int M2 = (A[1][0] + A[1][1]) * B[0][0];
    int M3 = A[0][0] * (B[0][1] - B[1][1]);
    int M4 = A[1][1] * (B[1][0] - B[0][0]);
    int M5 = (A[0][0] + A[0][1]) * B[1][1];
    int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

void inputMatrix(int M[2][2])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &M[i][j]);
}

void printMatrix(int M[2][2])
{
    for (int i = 0; i < 2; i++, printf("\n"))
        for (int j = 0; j < 2; j++)
            printf("%d ", M[i][j]);
}

int main()
{
    int A[2][2], B[2][2], C[2][2];
    printf("\t****NISHAN DHAKAL****\n      **** Strassen's Matrix Multiplication ****\n\n");
    printf("Enter elements of first 2x2 matrix:\n");
    inputMatrix(A);
    printf("Enter elements of second 2x2 matrix:\n");
    inputMatrix(B);

    strassenMultiply(A, B, C);
    printf("Resultant matrix:\n");
    printMatrix(C);
    return 0;
}
