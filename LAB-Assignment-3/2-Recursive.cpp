#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL FIBONACCI[94];

ULL findFibonacci(int n);

int main()
{
    int n;

    FIBONACCI[0] = 0;
    FIBONACCI[1] = 1;

    printf("This calculator will give correct n-th Fibonacci Number where n < 94\n");
    printf("n = ");
    scanf("%d", &n);
    printf("Fibonacci-%d = %llu\n", n, findFibonacci(n));

    return 0;
}

ULL findFibonacci(int n)
{
    if (n <= 1) {
        return FIBONACCI[n];
    }
    else if (FIBONACCI[n] != 0) {
        return FIBONACCI[n];
    }
    else {
        FIBONACCI[n] = findFibonacci(n - 1) + findFibonacci(n - 2);
        return FIBONACCI[n];
    }
}
