#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for building tree
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
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Check mirror
int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Check symmetric
int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}