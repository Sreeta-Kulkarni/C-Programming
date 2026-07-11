#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue
struct Node* queue[MAX];
int front = 0, rear = -1;

// Create node
struct Node* createNode(int data) {
    if (data == -1)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Enqueue
void enqueue(struct Node* node) {
    queue[++rear] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* q[MAX];
    int f = 0, r = -1;

    q[++r] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = q[f++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            q[++r] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            q[++r] = curr->right;
        }
        i++;
    }

    return root;
}

// Right View
void rightView(struct Node* root) {
    if (root == NULL)
        return;

    front = 0;
    rear = -1;

    enqueue(root);

    while (front <= rear) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();

            // Last node of this level
            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left)
                enqueue(curr->left);

            if (curr->right)
                enqueue(curr->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}