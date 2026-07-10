/*
 * Delete a node from the end of a singly linked list
 */

// 2. Write a program to delete a node from the end of a singly linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
int main()
{
struct node *head = NULL, *newnode, *temp, *prev;
int i, n, val;
printf("Enter n: ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
scanf("%d", &val);
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = val;
newnode->next = NULL;
if (head == NULL)
head = newnode;
else
{
temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newnode;
}
}
// delete last node
temp = head;
while (temp->next != NULL)

{
prev = temp;
temp = temp->next;
}
prev->next = NULL;
free(temp);
printf("After deletion:\n");
temp = head;
while (temp != NULL)
{
printf("%d ", temp->data);
temp = temp->next;
}
return 0;
}
