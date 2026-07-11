#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    // Check overflow
    if ((rear + 1) % MAX == front) {
        return; // queue full (ignored for this problem)
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
}

// Dequeue
void dequeue() {
    if (front == -1) {
        return; // empty
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (front == -1)
        return;

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Dequeue m times
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}