#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int row1, col1, row2, col2, row, col, i, j, k, sum;
    int **matA, **matB, **matC;

    printf("Number of Rows of Matrix A : ");
    scanf("%d", &row1);
    printf("Number of Columns of Matrix A : ");
    scanf("%d", &col1);
    printf("Number of Rows of Matrix B : ");
    scanf("%d", &row2);
    printf("Number of Columns of Matrix B : ");
    scanf("%d", &col2);

    if (col1 == row2) {

        row = row1;
        col = col2;

        matA = (int **) malloc(row1 * sizeof(int *));
        matB = (int **) malloc(row2 * sizeof(int *));
        matC = (int **) malloc(row * sizeof(int *));

        for (i = 0; i < row1; i++) {
            matA[i] = (int *) malloc(col1 * sizeof(int));
        }

        for (i = 0; i < row2; i++) {
            matB[i] = (int *) malloc(col2 * sizeof(int));
        }

        for (i = 0; i < row; i++) {
            matC[i] = (int *) malloc(col * sizeof(int));
        }

        printf("Enter %d values for Matrix A in row-major order : ", row1 * col1);
        for (i = 0; i < row1; i++) {
            for (j = 0; j < col1; j++) {
                scanf("%d", &matA[i][j]);
            }
        }

        printf("\nMatrix A is : \n");
        for(i = 0; i < row1; i++) {
            printf("|\t");
            for(j = 0; j < col1; j++) {
                printf("%d\t", matA[i][j]);
            }
            printf("|\n");
        }

        printf("Enter %d values for Matrix B in row-major order : ", row2 * col2);
        for (i = 0; i < row2; i++) {
            for (j = 0; j < col2; j++) {
                scanf("%d", &matB[i][j]);
            }
        }

        printf("\nMatrix B is : \n");
        for(i = 0; i < row2; i++) {
            printf("|\t");
            for(j = 0; j < col2; j++) {
                printf("%d\t", matB[i][j]);
            }
            printf("|\n");
        }

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                sum = 0;
                for (k = 0; k < col1; k++) {
                    sum += matA[i][k] * matB[k][j];
                }
                matC[i][j] = sum;
            }
        }

        printf("Matrix A X Matrix B :\n");
        for(i = 0; i < row; i++) {
            printf("|\t");
            for(j = 0; j < col; j++) {
                printf("%d\t", matC[i][j]);
            }
            printf("|\n");
        }
    }
    else {
        printf("For multiplication of two matrices, number of columns of first matrix must be equal to number of rows of second matrix.\n");
    }

    return 0;
}
