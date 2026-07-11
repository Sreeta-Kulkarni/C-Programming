#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Find LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // Both nodes in left subtree
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // Both nodes in right subtree
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // Split point → LCA
    return root;
}

int main() {
    int n, x, n1, n2;
    struct Node* root = NULL;

    scanf("%d", &n);

    // Build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Nodes to find LCA
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}