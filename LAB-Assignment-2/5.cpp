#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
int STACK[MAX];
int TOS = 0;
int POP;

void push(int x);
int pop();
void show();

int main()
{
    int choice, value;

    do {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Push Value : ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                break;

            case 3:
                show();
                break;

            case 4:
                printf("Exiting...Thank You.\n");
                break;

            default:
                printf("Invalid choice. Try Again.\n");
        }
    } while (choice != 4);
}

void push(int x)
{
    if (TOS == MAX - 1) {
        printf("Overflow.\n");
        return;
    }

    STACK[++TOS] = x;
    printf("Value push successful.\n");
}

int pop()
{
    if (TOS == 0) {
        printf("Underflow.\n");
        POP = -1;
        return -1;
    }

    POP = 0;
    printf("Value pop successful.\n");
    return STACK[TOS--];
}

void show()
{
    if (TOS == 0) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Current Stack : ");
    for (int i = 1; i <= TOS; i++) {
        printf("%d ", STACK[i]);
    }
    printf("\n");
}
