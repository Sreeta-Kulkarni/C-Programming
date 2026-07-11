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
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Enqueue
void enqueue(struct Node* node) {
    queue[++rear] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Build tree (level order, complete tree assumed)
struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue();

        if (i < n) {
            curr->left = createNode(arr[i++]);
            enqueue(curr->left);
        }

        if (i < n) {
            curr->right = createNode(arr[i++]);
            enqueue(curr->right);
        }
    }

    return root;
}

// Check Min Heap property
int isMinHeap(struct Node* root) {
    if (root == NULL)
        return 1;

    // Check left child
    if (root->left) {
        if (root->data > root->left->data)
            return 0;
    }

    // Check right child
    if (root->right) {
        if (root->data > root->right->data)
            return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}