#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue (insert at rear)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue (remove from front)
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    // If queue becomes empty
    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int N, value;
    char op[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'e') { // enqueue
            scanf("%d", &value);
            enqueue(value);
        } 
        else if (op[0] == 'd') { // dequeue
            dequeue();
        }
    }

    return 0;
}