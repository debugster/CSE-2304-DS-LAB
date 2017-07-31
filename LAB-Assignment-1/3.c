#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *num;
    printf("How many students ? : ");
    scanf("%d", &n);
    printf("Enter marks of %d students : ", n);

    n++;
    num = (int *) malloc(n * sizeof(int));
    for (i = 1; i < n; i++) {
        scanf("%d", &num[i]);
    }

    num[0] = 0;
    for (i = 1; i < n; i++) {
        if (num[i] >= 40) {
            num[0]++;
        }
    }

    printf("%d student(s) have passed.\n", num[0]);
    return 0;
}

