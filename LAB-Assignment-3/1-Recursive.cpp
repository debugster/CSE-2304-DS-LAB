#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL factorial(ULL n);

int main()
{
    ULL n;

    printf("This calculator will give correct answer for n! where n < 21\n");
    printf("You want to find factorial of __ ? : ");
    scanf("%llu", &n);
    printf("%llu! = %llu\n", n, factorial(n));

    return 0;
}

ULL factorial(ULL n)
{
    if (n <= 1) {
        return 1;
    }

    return (n * factorial(n - 1));
}
