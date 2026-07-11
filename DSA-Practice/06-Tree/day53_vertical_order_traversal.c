#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node (stores node + horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

// Queue
struct QNode queue[MAX];
int front = 0, rear = -1;

// Result storage
int result[2*MAX][MAX];  // columns
int count[2*MAX];        // count per column

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
void enqueue(struct Node* node, int hd) {
    queue[++rear].node = node;
    queue[rear].hd = hd;
}

// Dequeue
struct QNode dequeue() {
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

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    int offset = MAX; // shift for negative index

    enqueue(root, 0);

    while (front <= rear) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int idx = hd + offset;

        result[idx][count[idx]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, hd - 1);

        if (curr->right)
            enqueue(curr->right, hd + 1);
    }

    // Print result
    for (int i = 0; i < 2 * MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
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

    verticalOrder(root);

    return 0;
}