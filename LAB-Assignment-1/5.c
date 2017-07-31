#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, pos, *num;
    printf("How many numbers ? : ");
    scanf("%d", &n);
    printf("Enter %d number : ", n);

    n++;
    num = (int *) malloc(n * sizeof(int));
    for (i = 1; i < n; i++) {
        scanf("%d", &num[i]);
    }

    printf("Before Deletion\n");
    for (i = 1; i < n; i++) {
        printf("number[%d] = %d\n", i, num[i]);
    }

    printf("Enter the position of number to be deleted : ");
    scanf("%d", &pos);

    for (i = pos; i < n - 1; i++) {
        num[i] = num[i + 1];
    }

    n--;

    printf("After Deletion\n");
    for (i = 1; i < n; i++) {
        printf("number[%d] = %d\n", i, num[i]);
    }

    return 0;
}


