#include <bits/stdc++.h>

using namespace std;

int main()
{
    char TEXT[1000], PATTERN[1000];
    int LenText, LenPattern, i, j, k, Limit;
    bool found;

    printf("Input original Text : ");
    gets(TEXT);
    printf("Input Pattern string: ");
    gets(PATTERN);

    LenText = strlen(TEXT);
    LenPattern = strlen(PATTERN);

    Limit = LenText - LenPattern + 1;

    for (k = 0; k < Limit; k++) {
        found = true;

        for (i = k, j = 0; j < LenPattern; i++, j++) {
            if (TEXT[i] != PATTERN[j]) {
                found = false;
                break;
            }
        }
        if (found == true) {
                break;
        }
    }

    if (found) {
        printf("%s was found in %s at position : %d.\n", PATTERN, TEXT, k + 1);
    }
    else {
        printf("%s was not found in %s\n", PATTERN, TEXT);
    }

    return 0;
}
