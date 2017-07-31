#include <bits/stdc++.h>

using namespace std;

char OP = '(';
char POSTFIX[50][20];
vector<int>VALUE;

bool isOperator(char *op);
int EVAL(int a, int b);

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int Len, v, i, a, b;

    printf("Instructions :\n");
    printf("1. Use single space to separate two adjacent operators/operands\n");
    printf("2. Put a right parenthesis to the last\n");
    printf("Enter the postfix expression :\n");

    Len = 0;
    do {
        scanf("%s", POSTFIX[Len]);
    } while (strcmp(")", POSTFIX[Len++]) != 0);

    for (i = 0; i < Len - 1; i++) {

        if (isOperator(POSTFIX[i])) {

            a = VALUE[VALUE.size() - 1];
            VALUE.pop_back();
            b = VALUE[VALUE.size() - 1];
            VALUE.pop_back();

            v = EVAL(a, b);
            VALUE.push_back(v);
        }
        else {
            v = (int) strtol(POSTFIX[i], NULL, 10);
            VALUE.push_back(v);
        }
    }

    printf("Answer is %d\n", VALUE[0]);
    return 0;
}

int EVAL(int a, int b)
{
    int c;

    switch (OP) {
        case '+':
            c = b + a;
            break;

        case '-':
            c = b - a;
            break;

        case '*':
            c = b * a;
            break;

        case '/':
            c = b / a;
            break;
    }

    return c;
}

bool isOperator(char *op)
{
    bool v = false;

    if (strcmp("+", op) == 0) {
        v = true;
    }
    else if (strcmp("-", op) == 0) {
            v = true;
    }
    else if (strcmp("*", op) == 0) {
            v = true;
    }
    else if (strcmp("/", op) == 0) {
            v = true;
    }

    if (v == true) {
        OP = op[0];
    }

    return v;
}
