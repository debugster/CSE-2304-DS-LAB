#include <bits/stdc++.h>

using namespace std;

char STRING_1[1000];
char STRING_2[1000];
int Len1;
int Len2;

void menu();
void inputString();
int stringLength(char *s);
void stringCopy(char *to, char *from);
void stringConcatenate(char *s1, char *s2);
int stringCompare(char *s1, char *s2);
void stringReverse(char *s);

int main()
{
    int choice, comp;
    char dump;

    do {
        menu();
        scanf("%d", &choice);
        dump = getchar();

        switch (choice) {
            case 1:
                printf("\nInput a string (Press Enter to terminate) : ");
                gets(STRING_1);

                Len1 = stringLength(STRING_1);

                printf("\nString : %s\n", STRING_1);
                printf("Length : %d\n\n", Len1);

                break;

            case 2:

                inputString();

                stringCopy(STRING_1, STRING_2);

                printf("\nAfter copying S2 to S1 :\n");
                printf("\nS1 : %s\n", STRING_1);
                printf("S2 : %s\n\n", STRING_2);

                break;

            case 3:

                inputString();

                stringConcatenate(STRING_1, STRING_2);

                printf("\nAfter concatenating S2 to S1 :\n");
                printf("\nS1 : %s\n", STRING_1);
                printf("S2 : %s\n\n", STRING_2);

                break;

            case 4:

                inputString();

                comp = stringCompare(STRING_1, STRING_2);

                switch (comp) {
                    case -1:
                        /// S2 is greater than S1
                        printf("\n%s is greater than %s\n\n", STRING_2, STRING_1);
                        break;

                    case 0:
                        /// Both strings are equal
                        printf("\n%s and %s both are equal\n\n", STRING_1, STRING_2);
                        break;

                    case 1:
                        /// S1 is greater than S2
                        printf("\n%s is greater than %s\n\n", STRING_1, STRING_2);
                        break;
                }

                break;

            case 5:

                printf("\nInput a string (Press Enter to terminate) : ");
                gets(STRING_1);

                stringReverse(STRING_1);

                printf("\nOriginal string\t: %s\n", STRING_1);
                printf("Reversed string\t: %s\n\n", STRING_2);

                /// Empty the STRING_2
                STRING_2[0] = '\0';

                break;

            case 6:

                printf("\nExiting...Thank You.\n\n");
                break;

            default:
                printf("\nInvalid Choice. Try Again.\n\n");
                break;
        }
    } while (choice != 6);
}

void menu()
{
    printf("Menu :\n");
    printf("1 - Find length of a string\n");
    printf("2 - Copy string S2 to S1\n");
    printf("3 - Concatenate string S2 to S1\n");
    printf("4 - Compare strings S1 and S2\n");
    printf("5 - Reverse a string\n");
    printf("6 - Exit\n");
    printf("Enter your choice : ");
}

void inputString()
{
    printf("\nInput string S1 (Press Enter to terminate) : ");
    gets(STRING_1);
    printf("Input string S2 (Press Enter to terminate) : ");
    gets(STRING_2);
}

int stringLength(char *s)
{
    int Len = 0;
    while (s[Len++] != '\0');

    return --Len;
}

void stringCopy(char *to, char *from)
{
    int i;

    Len1 = stringLength(to);
    Len2 = stringLength(from);

    i = 0;
    while (i <= Len2) {
        to[i] = from[i];
        i++;
    }

    /// Renew the length of S1
    Len1 = stringLength(to);
}

void stringConcatenate(char *s1, char *s2)
{
    int i, j;

    Len1 = stringLength(s1);
    Len2 = stringLength(s2);

    i = Len1;
    j = 0;

    while ( j <= Len2) {
        s1[i] = s2[j];
        i++;
        j++;
    }

    /// Renew the length of S1
    Len1 = stringLength(s1);
}

int stringCompare(char *s1, char *s2)
{
    int i, maxLen, comp;

    Len1 = stringLength(s1);
    Len2 = stringLength(s2);

    maxLen = Len1 >= Len2 ? Len1 : Len2;

    comp = 0;
    for (i = 0; i < maxLen; i++) {
        if (s1[i] == s2[i]) {
            continue;
        }
        else {
            if (s1[i] > s2[i]) {
                comp = 1;
            }
            else {
                comp = -1;
            }
            break;
        }
    }

    return comp;
}

void stringReverse(char *s)
{
    int i, j;

    Len1 = stringLength(s);

    i = 0;
    j = Len1 - 1;

    while (i < Len1) {
        STRING_2[i] = s[j];
        i++;
        j--;
    }
    STRING_2[i] = '\0';
}
