#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *num;
    printf("How many numbers ? : ");
    scanf("%d", &n);
    printf("Enter %d number : ", n);

    n++;
    num = (int *) malloc(n * sizeof(int));
    for (i = 1; i < n; i++) {
        scanf("%d", &num[i]);
    }

    num[0] = num[1];
    for (i = 2; i < n; i++) {
        if (num[i] > num[0]) {
            num[0] = num[i];
        }
    }

    printf("Maximum value is %d\n", num[0]);
    return 0;
}
