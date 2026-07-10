/*
 * Build a binary tree using integers (instead of characters)
 */

// 1. Write a program to create a binary tree using integers instead of characters.
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
printf("Enter value (-1 for no node): ");
scanf("%d", &val);
if (val == -1)
return NULL;
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = val;
// create left
printf("Left of %d\n", val);
newnode->left = create();
// create right
printf("Right of %d\n", val);
newnode->right = create();
return newnode;
}
// simple preorder to show tree
void preorder(struct node *root)
{
if (root != NULL)
{
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}
int main()
{

struct node *root;
root = create();
printf("Preorder: ");
preorder(root);
return 0;
}
