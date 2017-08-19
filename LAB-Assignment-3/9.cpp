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

    printf("Which item to insert ? : ");
    scanf("%d", &item);

    ptr->next = (node *) malloc(sizeof(node));
    ptr = ptr->next;
    ptr->value = item;
    ptr->next = NULL;

    printf("Item insertion successful.\n");

    printf("Displaying:\n");
    ptr = start;
    while (ptr != NULL) {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }

    return 0;
}


