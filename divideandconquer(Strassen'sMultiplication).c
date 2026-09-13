#include <stdio.h>

void add(int A[2][2], int B[2][2], int C[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            C[i][j] = A[i][j] - B[i][j];
}

int main() {
    int A[2][2], B[2][2], C[2][2];
    int P1, P2, P3, P4, P5, P6, P7;
    int i, j;

    printf("Enter elements of first 2x2 matrix:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second 2x2 matrix:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    P1 = A[0][0] * (B[0][1] - B[1][1]);
    P2 = (A[0][0] + A[0][1]) * B[1][1];
    P3 = (A[1][0] + A[1][1]) * B[0][0];
    P4 = A[1][1] * (B[1][0] - B[0][0]);
    P5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    P6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    P7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

    C[0][0] = P5 + P4 - P2 + P6;
    C[0][1] = P1 + P2;
    C[1][0] = P3 + P4;
    C[1][1] = P5 + P1 - P3 - P7;

    printf("Resultant matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
