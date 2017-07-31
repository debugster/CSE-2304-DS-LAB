#include <bits/stdc++.h>

using namespace std;

int main()
{
    char TEXT[1000], STRING[1000], temp[1000];
    int LenText, LenString, LenTemp, pos, i, j;

    printf("Input Original Text : ");
    gets(TEXT);
    LenText = strlen(TEXT);

    printf("Input String to be inserted in Text : ");
    gets(STRING);
    LenString = strlen(STRING);

    do {
        printf("\nIn which position do you want to insert ? : ");
        scanf("%d", &pos);

        if (pos > LenText || pos <= 0) {
            printf("\nInvalid position. Try Again.\n\n");
        }
    } while (pos > LenText || pos <= 0);

    for (i = 0; i < pos - 1; i++) {
        temp[i] = TEXT[i];
    }

    temp[i] = '\0';

    strcat(temp, STRING);

    LenTemp = strlen(temp);

    for (i = pos - 1, j = LenTemp; i <= LenText; i++, j++) {
        temp[j] = TEXT[i];
    }

    strcpy(TEXT, temp);
    printf("%s\n", TEXT);

    return 0;
}
