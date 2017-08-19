#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL FIBONACCI[94];

int main()
{
    int n, i;

    FIBONACCI[0] = 0;
    FIBONACCI[1] = 1;

    for (i = 2; i <= 93; i++) {
        FIBONACCI[i] = FIBONACCI[i - 1] + FIBONACCI[i - 2];
    }

    printf("This calculator will give correct n-th Fibonacci Number where n < 94\n");
    printf("n = ");
    scanf("%d", &n);
    printf("Fibonacci-%d = %llu\n", n, FIBONACCI[n]);

    return 0;
}
