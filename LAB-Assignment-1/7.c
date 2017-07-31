#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, item, pos = 0, *num;

    printf("How many numbers ? : ");
    scanf("%d", &n);

    printf("Enter %d numbers : ", n);
    n++;

    num = (int *) malloc(n * sizeof(int));

    for (i = 1; i < n; i++) {
        scanf("%d", &num[i]);
    }

    printf("Which number to search ? : ");
    scanf("%d", &item);

    for (i = 1; i < n; i++) {
        if (num[i] == item) {
            pos = i;
            break;
        }
    }

    if (pos == 0) {
        printf("%d was not found.\n", item);
    }
    else {
        printf("%d was found at position %d.\n", item, pos);
    }

    return 0;
}

