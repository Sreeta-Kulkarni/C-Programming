#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Check precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    scanf("%s", infix);

    while (infix[i] != '\0') {
        char ch = infix[i];

        // If operand → add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // If '(' → push
        else if (ch == '(') {
            push(ch);
        }

        // If ')' → pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s\n", postfix);

    return 0;
}