# Trees

## 📖 Theory

Experiment 7: Trees
Aim: To demonstrate the creation of a binary tree and perform different tree traversals.
Introduction
A Tree is a hierarchical data structure consisting of nodes connected by edges.
- The top node is called the Root

- Nodes with no children are Leaf nodes

- Each node may have left and right child in a Binary Tree

Representation in C
Each node contains:
- Data

- Pointer to left child

- Pointer to right child

struct Node {
char data;
struct Node* left;
struct Node* right;
};

Tree Traversal
Tree traversal is the process of systematically visiting every node in a tree data structure exactly
once, starting from the root. It is used to access, update, or delete data within hierarchical
structures.
Types of Binary Tree Traversals:
1. Inorder Traversal (Left → Root → Right)
Rule:
- Visit left subtree

- Visit root

- Visit right subtree

Step-by-Step:
1. Go to left of A → B
2. Go to left of B → D
3. Visit D
4. Back to B → Visit B
5. Visit E
6. Back to A → Visit A
7. Visit C

Output:
DBEAC

2. Preorder Traversal (Root → Left → Right)
Rule:
- Visit root first

- Then left subtree

- Then right subtree

Step-by-Step:
1. Visit A
2. Go to B → Visit B
3. Go to D → Visit D
4. Visit E
5. Visit C

Output:
ABDEC

3. Postorder Traversal (Left → Right → Root)
Rule:
- Visit left subtree

- Visit right subtree

- Visit root last

Step-by-Step:
1. Go to D → Visit D
2. Visit E
3. Visit B
4. Visit C
5. Visit A
Output:
D EB CA

Quick Summary:
Traversal

Order

Output

Inorder

L → Root → R

D B EAC

Preorder

Root → L → R

ABDEC

Postorder

L → R → Root

D EB CA

Inorder Traversal
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%c ", root->data);
inorder(root->right);
}
}

Preorder Traversal
void preorder(struct Node* root) {
if (root != NULL) {
printf("%c ", root->data);
preorder(root->left);
preorder(root->right);
}
}

Postorder Traversal
void postorder(struct Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%c ", root->data);
}
}

Example Program:
```c
#include <stdio.h>
#include <stdlib.h>
struct Node {
char data;
struct Node* left;
struct Node* right;
};
struct Node* createNode(char data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%c ", root->data);
inorder(root->right);
}
}
void preorder(struct Node* root) {
if (root != NULL) {
printf("%c ", root->data);
preorder(root->left);
preorder(root->right);
}

}

void postorder(struct Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%c ", root->data);
}
}

int main() {
struct Node* root = createNode('A');
root->left = createNode('B');
root->right = createNode('C');
root->left->left = createNode('D');
root->left->right = createNode('E');

printf("Inorder: ");
inorder(root);

printf("\nPreorder: ");
preorder(root);

printf("\nPostorder: ");
postorder(root);

return 0;
}
```
Tasks:
1. Write a program to create a binary tree using integers instead of characters.
2. Modify the program to count total number of nodes in a tree.
3. Write a function to find the height of a binary tree.

---

## 💻 Programs

1. [`01_binary_tree_integers.c`](./01_binary_tree_integers.c) — Build a binary tree using integers (instead of characters)
2. [`02_count_total_nodes.c`](./02_count_total_nodes.c) — Count the total number of nodes in a binary tree
3. [`03_height_of_binary_tree.c`](./03_height_of_binary_tree.c) — Find the height of a binary tree

## 🛠️ How to compile & run

```bash
gcc 01_binary_tree_integers.c -o output
./output
```

Run the same way for any of the other 2 files in this folder — just swap the filename.
