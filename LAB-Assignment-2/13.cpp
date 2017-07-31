#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

vector<char>convertedNumber;

bool numberValidator(char *s, int b);
ULL anyToDecimal(char *any, int b);
void decimalToAny(ULL dec, int b);

int main()
{
    int fromBase, toBase, i;
    char originalNumber[1000];
    ULL decimal;

    printf("Enter a number to be converted : ");
    gets(originalNumber);
    printf("Enter Base of the given number : ");
    scanf("%d", &fromBase);

    if (numberValidator(originalNumber, fromBase)) {
        do {
            printf("To which base do you want to convert ? : ");
            scanf("%d", &toBase);

            if (toBase < 2 || toBase > 16) {
                printf("\nInvalid base selection. Try Again.\n\n");
            }
        } while (toBase < 2 || toBase > 16);

        if (fromBase == toBase) {
            printf("\nOriginal Number  : %s (Base-%d)\n", originalNumber, fromBase);
            printf("Converted Number : %s (Base-%d)\n\n", originalNumber, toBase);
        }

        if (fromBase == 10) {
            /// Converting Decimal String to Decimal Integer
            decimal = strtoull(originalNumber, NULL, 10);
        }
        else {
            /// Converting given number (String) to Decimal Integer
            decimal = anyToDecimal(originalNumber, fromBase);
        }

        if (toBase == 10) {
            printf("\nOriginal Number  : %s (Base-%d)\n", originalNumber, fromBase);
            printf("Converted Number : %llu (Base-%d)\n\n", decimal, toBase);
        }
        else {
            decimalToAny(decimal, toBase);

            printf("\nOriginal Number  : %s (Base-%d)\n", originalNumber, fromBase);
            printf("Converted Number : ");

            for (i = convertedNumber.size() - 1; i >= 0; i--) {
                printf("%c", convertedNumber[i]);
            }

            printf(" (Base-%d)\n\n", toBase);
        }
    }
    else {
        /// Not valid for the given base
        printf("%s is not a valid number for the given Base-%d.\n", originalNumber, fromBase);
    }

    return 0;
}

bool numberValidator(char *s, int b)
{
    int Len, i, maxDigit, temp;
    bool valid;

    Len = strlen(s);

    maxDigit = 0;
    valid = true;

    for (i = 0; i < Len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp = s[i] - '0';
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            temp = s[i] - 'A' + 10;
        }
        else {
            valid = false;
            break;
        }

        if (temp > maxDigit) {
            maxDigit = temp;
        }

        if (maxDigit >= b) {
            valid = false;
            break;
        }
    }

    return valid;
}

ULL anyToDecimal(char *any, int b)
{
    int i, j , Len;
    ULL digit, dec = 0;

    Len = strlen(any);

    for (i = 0, j = Len - 1; i < Len; i++, j--) {
        if (any[i] >= '0' && any[i] <= '9') {
            digit = any[i] - '0';
        }
        else if (any[i] >= 'A' && any[i] <= 'F') {
            digit = any[i] - 'A' + 10;
        }

        digit *= pow(b, j);
        dec += digit;
    }

    return dec;
}

void decimalToAny(ULL dec, int b)
{
    int temp;
    char digit;

    do {
        temp = dec % b;

        if (temp >= 0 && temp <= 9) {
            digit = temp + '0';
        }
        else if (temp >= 10 && temp <= 15) {
            digit = temp - 10 + 'A';
        }

        convertedNumber.push_back(digit);
        dec /= b;
    } while (dec != 0);
}
