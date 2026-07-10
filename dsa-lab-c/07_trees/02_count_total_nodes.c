/*
 * Count the total number of nodes in a binary tree
 */

// 2. Modify the program to count total number of nodes in a tree.
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *left, *right;
};
struct node *create()
{
int val;
struct node *newnode;
scanf("%d", &val);
if (val == -1)

return NULL;
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = val;
newnode->left = create();
newnode->right = create();
return newnode;
}
int count(struct node *root)
{
if (root == NULL)
return 0;
return 1 + count(root->left) + count(root->right);
}
int main()
{
struct node *root;
int total;
printf("Enter nodes (-1 for no node): ");
root = create();
total = count(root);
printf("Total nodes: %d", total);
return 0;
}
