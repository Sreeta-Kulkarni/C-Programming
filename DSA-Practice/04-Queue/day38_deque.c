#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;
int count = 0;

// Check empty
int empty() {
    return (count == 0);
}

// Size
int size() {
    return count;
}

// push_front
void push_front(int x) {
    if (count == MAX)
        return;

    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    dq[front] = x;
    count++;
}

// push_back
void push_back(int x) {
    if (count == MAX)
        return;

    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    dq[rear] = x;
    count++;
}

// pop_front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    count--;
}

// pop_back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }

    count--;
}

// get front
void getFront() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front]);
}

// get back
void getBack() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear]);
}

// display deque
void display() {
    if (empty())
        return;

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, val;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { // push_front
            scanf("%d", &val);
            push_front(val);
        }
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            scanf("%d", &val);
            push_back(val);
        }
        else if (op[0] == 'p' && op[3] == 'f') { // pop_front
            pop_front();
        }
        else if (op[0] == 'p' && op[3] == 'b') { // pop_back
            pop_back();
        }
        else if (op[0] == 'f') { // front
            getFront();
        }
        else if (op[0] == 'b') { // back
            getBack();
        }
        else if (op[0] == 'e') { // empty
            printf("%d\n", empty());
        }
        else if (op[0] == 's' && op[1] == 'i') { // size
            printf("%d\n", size());
        }
    }

    // Final state (optional)
    display();

    return 0;
}