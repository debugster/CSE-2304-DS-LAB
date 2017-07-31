#include <bits/stdc++.h>

using namespace std;

int main()
{
    int lowerCase[26] = {0}, upperCase[26] = {0};
    int LenText, i;
    char TEXT[1000];

    printf("Enter a Text : ");
    gets(TEXT);

    LenText = strlen(TEXT);

    for (i = 0; i < LenText; i++) {
        if (TEXT[i] >= 'A' && TEXT[i] <= 'Z') {
            upperCase[TEXT[i] - 'A']++;
        }
        else if (TEXT[i] >= 'a' && TEXT[i] <= 'z') {
            lowerCase[TEXT[i] - 'a']++;
        }
    }

    printf("Printing Statistics of Letters in Text:\n\n");

    for (i = 0; i < 26; i++) {
        printf("%c - %d time(s)\n", i + 'A', upperCase[i]);
        printf("%c - %d time(s)\n\n", i + 'a', lowerCase[i]);
    }

    return 0;
}
