#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, item, beg, mid, end, *num;

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

    beg = 1;
    end = n - 1;
    mid = (beg + end) / 2;

    while (beg <= end && num[mid] != item) {
        if (item > num[mid]) {
            beg = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = (beg + end) / 2;
    }

    if (num[mid] == item) {
        printf("%d was found at position %d.\n", item, mid);
    }
    else {
        printf("%d was not found.\n", item);
    }

    return 0;
}


