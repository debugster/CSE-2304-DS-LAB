#include <bits/stdc++.h>

int main()
{
    int **matA, **matB;
    int row, col, i, j;

    printf("How many rows ? : ");
    scanf("%d", &row);
    printf("How many columns ? : ");
    scanf("%d", &col);

    row++;
    col++;

    matA = (int **) malloc(row * sizeof(int *));
    matB = (int **) malloc(col * sizeof(int *));

    for (i = 1; i < row; i++) {
        matA[i] = (int *) malloc(col * sizeof(int));
    }

    for (i = 1; i < col; i++) {
        matB[i] = (int *) malloc(row * sizeof(int));
    }

    printf("Enter %d values for Matrix A according to Row-major Order :\n", (row - 1) * (col - 1));
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    for (i = 1; i < col; i++) {
        for (j = 1; j < row; j++) {
            matB[i][j] = matA[j][i];
        }
    }

    printf("Original Matrix :\n");
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            printf("%3d ", matA[i][j]);
        }
        printf("\n");
    }

    printf("Interchanged Matrix :\n");
    for (i = 1; i < col; i++) {
        for (j = 1; j < row; j++) {
            printf("%3d ", matB[i][j]);
        }
        printf("\n");
    }

    return 0;
}
