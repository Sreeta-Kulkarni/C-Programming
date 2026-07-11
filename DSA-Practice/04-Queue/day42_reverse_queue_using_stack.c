#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Stack push
void push(int x) {
    stack[++top] = x;
}

// Stack pop
int pop() {
    return stack[top--];
}

int main() {
    int N, x;

    scanf("%d", &N);

    // Input queue
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Dequeue all → push into stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Pop from stack → enqueue back
    while (top != -1) {
        enqueue(pop());
    }

    // Output reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}