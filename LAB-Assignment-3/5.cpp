#include <bits/stdc++.h>

using namespace std;

#define SIZE 6

int QUEUE[SIZE];
int FRONT = 0;
int REAR = 0;

void insertQ();
void deleteQ();
void showQ();

int main()
{
    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertQ();
                break;

            case 2:
                deleteQ();
                break;

            case 3:
                showQ();
                break;

            case 4:
                printf("Exiting...Thank You!\n");
                break;

            default:
                printf("Invalid Choice. Try Again.\n");
                break;
        }
    } while (choice != 4);
}

void insertQ()
{
    int ITEM;

    if (FRONT == 1 && REAR == SIZE - 1 || FRONT == REAR + 1) {
        printf("\nOverflow.\n");
        return;
    }

    printf("\nITEM to be inserted : ");
    scanf("%d", &ITEM);

    if (FRONT == 0) {
        FRONT = REAR = 1;
    }
    else if (REAR == SIZE - 1) {
        REAR = 1;
    }
    else {
        REAR++;
    }

    QUEUE[REAR] = ITEM;
    printf("\n%d was inserted successfully.\n", ITEM);
}

void deleteQ()
{
    int ITEM;

    if (FRONT == 0) {
        printf("\nUnderflow.\n");
        return;
    }

    ITEM = QUEUE[FRONT];

    if (FRONT == REAR) {
        FRONT = REAR = 0;
    }
    else if (FRONT == SIZE - 1) {
        FRONT = 1;
    }
    else {
        FRONT++;
    }

    printf("\n%d was deleted successfully.\n", ITEM);
}

void showQ()
{
    int i;

    if (FRONT == 0 && REAR == 0) {
        printf("\nQueue is Empty.\n");
        return;
    }

    if (FRONT <= REAR) {
        for (i = FRONT; i <= REAR; i++) {
            printf("%d\t", QUEUE[i]);
        }
        printf("\n");
    }
    else {
        for (i = FRONT; i <= SIZE - 1; i++) {
            printf("%d\t", QUEUE[i]);
        }

        for (i = 1; i <= REAR; i++) {
            printf("%d\t", QUEUE[i]);
        }
        printf("\n");
    }
}
