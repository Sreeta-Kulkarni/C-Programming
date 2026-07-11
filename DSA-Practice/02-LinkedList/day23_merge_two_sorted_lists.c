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

// Merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    // Initialize result
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data < l2->data) {
        result = l1;
        l1 = l1->next;
    } else {
        result = l2;
        l2 = l2->next;
    }

    tail = result;

    // Merge process
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return result;
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
    int n, m, x;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    // Merge
    struct Node* merged = mergeLists(list1, list2);

    // Output
    display(merged);

    return 0;
}