#include <stdio.h>
#include <math.h>

int main()
{
    int number[100], i, j, temp;
    FILE *fp;
    fp = fopen("RAND.DAT", "w");
    for (i = 0; i < 100; i++) {
        fprintf(fp, "%d\n", rand());
    }

    fclose(fp);

    printf("Reading numbers from files\n\n");
    fp = fopen("RAND.DAT", "r");
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%d", &number[i]);
        printf("%d\n", number[i]);
    }

    return 0;
}


