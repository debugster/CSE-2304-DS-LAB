#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, *num;

    printf("How many numbers ? : ");
    scanf("%d", &n);

    printf("Enter %d numbers : ", n);
    n++;

    num = (int *) malloc(n * sizeof(int));

    for (i = 1; i < n; i++) {
        scanf("%d", &num[i]);
    }

    printf("Before Sorting\n");
    for (i = 1; i < n; i++) {
        printf("number[%d] = %d\n", i, num[i]);
    }

    for (i = 1; i < n - 1; i++) {
        j = 1;
        while (j <= n - i) {
            if (num[j] > num[j + 1]) {
                num[0] = num[j];
                num[j] = num[j + 1];
                num[j + 1] = num[0];
            }
            j++;
        }
    }

    printf("After Sorting\n");
    for (i = 1; i < n; i++) {
        printf("number[%d] = %d\n", i, num[i]);
    }

    return 0;
}

