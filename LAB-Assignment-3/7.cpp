#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next;
};

int main()
{
    int n, i;
    node *start, *ptr;

    start = (node *) malloc(sizeof(node));
    ptr = start;

    printf("How many elements : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Input number : ");
        scanf("%d", &ptr->value);

        if (i != n) {
            ptr->next = (node *) malloc(sizeof(node));
            ptr = ptr->next;
        }
    }
    ptr->next = NULL;

    ptr = start;
    while (ptr != NULL) {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }

    return 0;
}
