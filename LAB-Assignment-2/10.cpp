#include <bits/stdc++.h>

using namespace std;

int main()
{
    char TEXT[1000], temp[1000];
    int LenText, LenTemp, LenString, pos, i, j, k;

    printf("Input Original Text : ");
    gets(TEXT);
    LenText = strlen(TEXT);

    do {
        printf("\nFrom which position do you want to delete ? : ");
        scanf("%d", &pos);

        if (pos > LenText || pos <= 0) {
            printf("\nInvalid position. Try Again.\n\n");
        }
    } while (pos > LenText || pos <= 0);

    /// Calculating maximum number of characters may be deleted from TEXT from scanned position
    i = LenText - pos + 1;

    do {
        printf("\nHow many characters do you want to delete ? : ");
        scanf("%d", &LenString);

        if (LenString > i) {
            printf("\nThere are not too much characters left from Position : %d to be deleted.\n", pos);
            printf("Try Again.\n\n");
        }

        if (LenString <= 0) {
            printf("\nInvalid length. Try Again.\n\n");
        }
    } while (LenString > i || LenString <= 0);

    for (i = 0; i < pos - 1; i++) {
        temp[i] = TEXT[i];
    }

    j = i;
    i += LenString;

    for (k = i; j <= LenText; k++, j++) {
        temp[j] = TEXT[k];
    }

    strcpy(TEXT, temp);
    printf("%s\n", TEXT);

    return 0;
}
