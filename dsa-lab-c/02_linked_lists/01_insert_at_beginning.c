/*
 * Insert a node at the beginning of a singly linked list
 */

// 1. Write a C program to insert a node at the beginning of a singly linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
int main()
{
struct node *head = NULL, *newnode;
int val, i, n;
printf("Enter n: ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
printf("Enter value: ");
scanf("%d", &val);
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = val;
newnode->next = head; // insert at beginning
head = newnode;
}
printf("List:\n");
while (head != NULL)
{
printf("%d ", head->data);
head = head->next;
}
return 0;
}
