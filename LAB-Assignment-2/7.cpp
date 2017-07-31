#include <bits/stdc++.h>

using namespace std;

char INFIX[50][20]; /// To hold Infix expression
vector<char *>POSTFIX; /// To hold Postfix expression
vector<char>STACK; /// To hold operators

void pushOperator(char c);
void popOperator(char c);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int Len, i;

    printf("Instructions :\n");
    printf("1. Use single space to separate two adjacent operators/operands\n");
    printf("Enter the postfix expression :\n");

    Len = 0;
    do {
        scanf("%s", INFIX[Len]);
    } while (strcmp("\0", INFIX[Len++]) != 0);

    /// Putting a ')' to the last of Infix expression
    /// This will work as the sentinel
    strcpy(INFIX[Len - 1], ")");

    /// Pushing '(' to the STACK
    STACK.push_back('(');

    /// Scanning symbols in Infix expression from left to right
    for (i = 0; i < Len; i++) {

        /// If symbol is '(', pushing it into the STACK
        if (!strcmp("(", INFIX[i])) {
            STACK.push_back('(');
        }

        /// If symbol is ')', repeatedly popping symbols from STACK and
        /// Push into POSTFIX until a '(' in encountered
        else if (!strcmp(")", INFIX[i])) {
            while (STACK[STACK.size() - 1] != '(') {
                pushOperator(STACK[STACK.size() - 1]);
                STACK.pop_back();
            }
            /// Removing '('
            STACK.pop_back();
        }

        /// If an operator is scanned from INFIX,
        /// Pop out operators with same or higher precedence in STACK and
        /// Push into POSTFIX until a '(' in encountered
        else if (!strcmp("+", INFIX[i])) {
            popOperator('+');
        }
        else if (!strcmp("-", INFIX[i])) {
            popOperator('-');
        }
        else if (!strcmp("*", INFIX[i])) {
            popOperator('*');
        }
        else if (!strcmp("/", INFIX[i])) {
            popOperator('/');
        }
        /// Scanned symbol is Operand otherwise
        /// So, Push it into POSTFIX
        else {
            POSTFIX.push_back(INFIX[i]);
        }
    }

    /// Printing out equivalent Postfix expression
    for (i = 0; i < POSTFIX.size(); i++) {
        printf("%s ", POSTFIX[i]);
    }
    printf("\n");

    return 0;
}

/// This function will receive scanned operator from STACK as a single CHAR
/// Then, this function will push the respective operator into POSTFIX as a STRING
void pushOperator(char c)
{
    switch (c) {
        case '+':
            POSTFIX.push_back("+\0");
            break;

        case '-':
            POSTFIX.push_back("-\0");
            break;

        case '*':
            POSTFIX.push_back("*\0");
            break;

        case '/':
            POSTFIX.push_back("/\0");
            break;
    }
}

/// This function will pop operators with same or higher precedence from STACK
/// And will push them into POSTFIX
void popOperator(char c)
{
    switch (c) {
        case '+':
        case '-':

            /// If the operator is either '+' or '-',
            /// That means, all operators till a '(' should be popped from STACK and
            /// pushed into POSTFIX

            while (STACK[STACK.size() - 1] != '(') {
                pushOperator(STACK[STACK.size() - 1]);
                STACK.pop_back();
            }
            break;

        case '*':

            /// If the operator is '*',
            /// Then, '/', '*' <- these operators should be popped from STACK
            /// and pushed into POSTFIX until a '(' is encountered
            /// If any operators with lower precedence (i.e. '+', '-') is encountered,
            /// Popping and Pushing must be stopped

            while ((STACK[STACK.size() - 1] == '/' || STACK[STACK.size() - 1] == '*') && STACK[STACK.size() - 1] != '(') {
                pushOperator(STACK[STACK.size() - 1]);
                STACK.pop_back();
            }
            break;

        case '/':

            /// If the operator is '/',
            /// Then, '/' <- only this operator should be popped from STACK
            /// and pushed into POSTFIX until a '(' is encountered
            /// If any operators with lower precedence (i.e. '+', '-', '*') is encountered,
            /// Popping and Pushing must be stopped

            while (STACK[STACK.size() - 1] == '/' && STACK[STACK.size() - 1] != '(') {
                pushOperator(STACK[STACK.size() - 1]);
                STACK.pop_back();
            }
            break;
    }

    /// After popping and pushing,
    /// Pushing the scanned symbol into POSTFIX
    STACK.push_back(c);
}
