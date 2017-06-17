#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
int DATA[MAX];
int ELEMENT = 0;
int FOUND_LOC = -1;

void create(void);
void sortData(void);
void insertData(void);
void deleteData(void);
void searchData(void);
int searchData(int value);
void displayData(void);

int main()
{
    srand(time(NULL));
    
    int choice;

    create();
    sortData();
    displayData();

    do {
        printf("\n####################################\n");
        printf("#               MENU               #\n");
        printf("#         1. Insert  Data          #\n");
        printf("#         2. Delete  Data          #\n");
        printf("#         3. Search  Data          #\n");
        printf("#         4. Display Data          #\n");
        printf("#         5. Exit                  #\n");
        printf("####################################\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertData();
                break;
            case 2:
                deleteData();
                break;
            case 3:
                searchData();
                break;
            case 4:
                displayData();
                break;
            case 5:
                printf("\nExiting...Thank You!\n");
                break;
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    } while (choice != 5);

    return 0;
}

void create(void)
{
    int n;

    printf("How many values do you want to store ? : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        DATA[i] = rand() % 10000;
    }

    ELEMENT += n;
}

void sortData(void)
{
    int i, j, temp;

    /// Bubble Sort
    for (i = 1; i < ELEMENT; i++) {
        for (j = 1; j <= ELEMENT - i; j++) {
            if (DATA[j] > DATA[j + 1]) {
                temp = DATA[j];
                DATA[j] = DATA[j + 1];
                DATA[j + 1] = temp;
            }
        }
    }
}

void insertData(void)
{
    int value, i, loc;

    if (ELEMENT == MAX) {
        printf("\nThe list is full. Value can't be inserted.\n");
    }
    else {
        printf("\nEnter the value to be inserted : ");
        scanf("%d", &value);

        /// If there is no value, insert it to the first position
        if (ELEMENT == 0) {
            DATA[++ELEMENT] = value;
        }
        /// If there are some values, first search for location to insert the value
        else {
            i = ELEMENT;

            /// Searching for the location and Shifting the values downwards
            while (DATA[i] > value) {
                DATA[i + 1] = DATA[i];
                i--;
            }

            DATA[i + 1] = value;
            ELEMENT++;
        }
        printf("\nData insertion successful.\n");
    }
}

void deleteData(void)
{
    int value, found, i;

    if (ELEMENT != 0) {
        printf("\nEnter the value to be deleted : ");
        scanf("%d", &value);

        /// Searching for the location of the value to be deleted
        found = searchData(value);

        if (found == 1) {
            /// Shifting the values upward
            for (i = FOUND_LOC; i < ELEMENT; i++) {
                DATA[i] = DATA[i + 1];
            }
            ELEMENT--;

            printf("\nData deletion successful.\n");
        }
        else {
            printf("\n%d was not found.\n", value);
        }
    }
    else {
        printf("\nSorry! There are no data.\n");
    }
}

void searchData(void)
{
    int value, found;

    printf("\nEnter the value to be searched : ");
    scanf("%d", &value);

    found = searchData(value);

    if (found == 1) {
        printf("\n%d was found at position %d.\n", value, FOUND_LOC);
    }
    else {
        printf("\n%d was not found.\n", value);
    }
}

int searchData(int value)
{
    int i, _begin, _end, _mid, found = 0;

    _begin = 1;
    _end = ELEMENT;
    _mid = (_begin + _end) / 2;

    /// Binary search
    while (DATA[_mid] != value && _begin <= _end) {
        if (value > DATA[_mid]) {
            _begin = _mid + 1;
        }
        else {
            _end = _mid - 1;
        }

        _mid = (_begin + _end) / 2;
    }

    /// Searching for the first occurrence if there are multiple occurrences
    if (DATA[_mid] == value) {

        i = _mid;

        /// Backtracking till the multiple occurrences are found
        while (DATA[--i] == value);

        found = 1;
        /// Assigning the first occurrence of the searched value to the FOUND_LOC
        FOUND_LOC = i + 1;
    }

    return found;
}

void displayData(void)
{
    int i;

    printf("\n ----------------------------------\n");
    printf("|             DATA SET             |\n");
    printf(" ----------------------------------\n");
    for (i = 1; i <= ELEMENT; i++) {
        printf("|    DATA[%3d]    | %10d     |\n", i, DATA[i]);
    }
    printf(" ----------------------------------\n");
}
