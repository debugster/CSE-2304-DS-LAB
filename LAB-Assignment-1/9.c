#include <stdio.h>
#include <math.h>

int main()
{
    char prime[100001] = {[2 ... 100000] = '1'};
    int i, sum, n, limit, x;

    n = 100000;
    limit = sqrt(n);

    for (i = 2; i <= limit; i++) {
        if (prime[i] == '1') {
            sum = 2 * i;
            while (sum <= n) {
                prime[sum] = '0';
                sum += i;
            }
        }
    }

    printf("Enter a number not greater than 100000 : ");
    scanf("%d", &x);

    if (x >= 1 && x <= 100000) {
        prime[x] == '1' ? printf("%d is prime.\n", x) : printf("%d is not prime.\n", x);
    }
    else {
        printf("Input is out of bounds.\n");
    }

    return 0;
}


