#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, item, pos, *num;
    printf("How many numbers ? : ");
    scanf("%d", &n);
    printf("Enter %d number : ", n);

    n++;
    num = (int *) malloc((n + 1) * sizeof(int));
    for (i = 1; i < n; i++) {
        scanf("%d", &num[i]);
    }

    printf("Before Insertion\n");
    for (i = 1; i < n; i++) {
        printf("number[%d] = %d\n", i, num[i]);
    }

    printf("Enter the number to be inserted : ");
    scanf("%d", &item);
    printf("Desired position : ");
    scanf("%d", &pos);

    i = n;
    while (i >= pos) {
        num[i + 1] = num [i];
        i--;
    }
    num[pos] = item;

    n++;

    printf("After Insertion\n");
    for (i = 1; i < n; i++) {
        printf("number[%d] = %d\n", i, num[i]);
    }

    return 0;
}

