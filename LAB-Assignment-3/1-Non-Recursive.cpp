#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL n, i, factorial = 1;

    printf("This calculator will give correct answer for n! where n < 21\n");
    printf("You want to find factorial of __ ? : ");
    scanf("%llu", &n);

    for (i = 2; i <= n; i++) {
        factorial *= i;
    }

    printf("%llu! = %llu\n", n, factorial);

    return 0;
}
