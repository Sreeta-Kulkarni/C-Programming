#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for tree construction
struct Node* queue[100];
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

// Build tree from level order
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

// LCA function
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If one of the nodes is found
    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    // If both sides return non-NULL → LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-NULL child
    return (left != NULL) ? left : right;
}

int main() {
    int n, n1, n2;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}