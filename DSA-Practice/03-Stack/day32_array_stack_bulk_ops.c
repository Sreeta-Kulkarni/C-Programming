#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int value) {
    if (top == MAX - 1)
        return; // ignore overflow for this problem

    stack[++top] = value;
}

// Pop
void pop() {
    if (top == -1)
        return; // ignore underflow for this problem

    top--;
}

// Display stack (top to bottom)
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}