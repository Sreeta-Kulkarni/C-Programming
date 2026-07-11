#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure (stack)
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {

        // If operand (number)
        if (isdigit(token[0])) {
            push(atoi(token));
        }
        else {
            int b = pop();
            int a = pop();

            switch (token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expr[100];

    // Read full line input
    fgets(expr, sizeof(expr), stdin);

    int result = evaluatePostfix(expr);

    printf("%d\n", result);

    return 0;
}