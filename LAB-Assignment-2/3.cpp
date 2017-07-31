#include <bits/stdc++.h>

int main()
{
    int **matA;
    int row, col, i, j, sum;

    printf("How many rows ? : ");
    scanf("%d", &row);
    printf("How many columns ? : ");
    scanf("%d", &col);

    row++;
    col++;

    matA = (int **) malloc(row * sizeof(int *));

    for (i = 1; i < row; i++) {
        matA[i] = (int *) malloc(col * sizeof(int));
    }

    printf("Enter %d values for Matrix A according to Row-major Order :\n", (row - 1) * (col - 1));
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Printing Row and Column Sum of given matrix :\n");
    for (i = 1; i < row; i++) {
        sum = 0;
        for (j = 1; j < col; j++) {
            printf("%3d ", matA[i][j]);
            sum += matA[i][j];
        }
        printf("%3d\n", sum);
    }

    for (i = 1; i < col; i++) {
        sum = 0;
        for (j = 1; j < row; j++) {
            sum += matA[j][i];
        }
        printf("%3d ", sum);
    }

    printf("\n");

    return 0;
}
