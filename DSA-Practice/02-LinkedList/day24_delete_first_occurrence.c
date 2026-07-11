#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: key is at head
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Traverse to find key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 2: key not found
    if (temp == NULL)
        return head;

    // Case 3: key found in middle/end
    prev->next = temp->next;
    free(temp);

    return head;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x, key;
    struct Node* head = NULL;

    // Input list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    // Input key
    scanf("%d", &key);

    // Delete
    head = deleteKey(head, key);

    // Output
    display(head);

    return 0;
}