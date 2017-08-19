#include<bits/stdc++.h>

using namespace std;

int findAckerman(int m, int n)
{
    if (m == 0) {
        return (n + 1);
    }
    else if (m != 0 && n == 0) {
        return findAckerman(m - 1, 1);
    }
    else if (m != 0 && n != 0) {
        return findAckerman(m - 1, findAckerman(m, n - 1));
    }
}

int main()
{
    int m, n;

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    printf("\nAckerman(%d, %d) = %d\n", m, n, findAckerman(m, n));

    return 0;

}

