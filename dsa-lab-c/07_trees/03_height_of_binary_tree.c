/*
 * Find the height of a binary tree
 */

// 3. Write a function to find the height of a binary tree.
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
int height(struct node *root)
{
int l, r;
if (root == NULL)
return 0;
l = height(root->left);
r = height(root->right);
if (l > r)
return l + 1;
else
return r + 1;
}
int main()
{
struct node *root;
int h;
printf("Enter nodes (-1 for no node): ");
root = create();
h = height(root);
printf("Height: %d", h);
return 0;
}
