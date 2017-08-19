#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next;
};

int main()
{
    int n, i, item;
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

    printf("Which item to search ? : ");
    scanf("%d", &item);

    ptr = start;
    while (ptr != NULL) {
        if (ptr->value == item) {
            printf("%d was found.\n", item);
            break;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("%d was not found.\n", item);
    }

    return 0;
}

