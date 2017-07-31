#include <bits/stdc++.h>

int main()
{
    int **matA, **matB, **matC;
    int row, col, i, j;

    printf("How many rows ? : ");
    scanf("%d", &row);
    printf("How many columns ? : ");
    scanf("%d", &col);

    row++;
    col++;

    matA = (int **) malloc(row * sizeof(int *));
    matB = (int **) malloc(row * sizeof(int *));
    matC = (int **) malloc(row * sizeof(int *));

    for (i = 1; i < row; i++) {
        matA[i] = (int *) malloc(col * sizeof(int));
        matB[i] = (int *) malloc(col * sizeof(int));
        matC[i] = (int *) malloc(col * sizeof(int));
    }

    printf("Enter %d values for Matrix A according to Row-major Order :\n", (row - 1) * (col - 1));
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter %d values for Matrix B according to Row-major Order :\n", (row - 1) * (col - 1));
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }

    printf("Matrix A :\n");
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            printf("%3d ", matA[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B :\n");
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            printf("%3d ", matB[i][j]);
        }
        printf("\n");
    }

    printf("Matrix A + Matrix B :\n");
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            printf("%3d ", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
