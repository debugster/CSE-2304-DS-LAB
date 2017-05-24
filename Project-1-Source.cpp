#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
int DATA[MAX];
int ELEMENT = 0;
int FOUND_LOC = -1;

void insert_value(void);
void delete_value(void);
void search_value(void);
int search_value(int value);
void display(void);

int main()
{
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_value();
                break;
            case 2:
                delete_value();
                break;
            case 3:
                search_value();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...Thank You!\n");
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    } while (choice != 5);

    return 0;
}

void insert_value(void)
{
    int value, i, loc;

    if (ELEMENT == MAX) {
        printf("The list is full. Value can't be inserted.\n");
    }
    else {
        printf("Enter the value to be inserted : ");
        scanf("%d", &value);

        if (ELEMENT == 0) {
            DATA[ELEMENT] = value;
        }
        else {
            loc = 0;
            while (DATA[loc] < value && loc < ELEMENT) {
                loc++;
            }

            for (i = ELEMENT - 1; i >= loc; i--) {
                DATA[i + 1] = DATA[i];
            }
            DATA[loc] = value;
        }
        ELEMENT++;
    }
}

void delete_value(void)
{
    int value, found, i;

    if (ELEMENT != 0) {
        printf("Enter the value to be deleted : ");
        scanf("%d", &value);

        found = search_value(value);

        if (found == 1) {
            for (i = FOUND_LOC; i < ELEMENT - 1; i++) {
                DATA[i] = DATA[i + 1];
            }
            ELEMENT--;
        }
        else {
            printf("%d was not found.\n", value);
        }
    }
    else {
        printf("Sorry! There are no values.\n");
    }
}

void search_value(void)
{
    int value, found;

    printf("Enter the value to be searched : ");
    scanf("%d", &value);

    found = search_value(value);

    if (found == 1) {
        printf("%d was found at position %d.\n", value, FOUND_LOC + 1);
    }
    else {
        printf("%d was not found.\n", value);
    }
}

int search_value(int value)
{
    int _begin, _end, _mid, found = 0;

    _begin = 0;
    _end = ELEMENT - 1;
    _mid = (_begin + _end) / 2;

    while (DATA[_mid] != value && _begin <= _end) {
        if (value > DATA[_mid]) {
            _begin = _mid + 1;
        }
        else {
            _end = _mid - 1;
        }

        _mid = (_begin + _end) / 2;
    }

    if (DATA[_mid] == value) {
        found = 1;
        FOUND_LOC = _mid;
    }

    return found;
}

void display(void)
{
    int i;

    for (i = 0; i < ELEMENT; i++) {
        printf("DATA[%d] = %d\n", i + 1, DATA[i]);
    }
}
