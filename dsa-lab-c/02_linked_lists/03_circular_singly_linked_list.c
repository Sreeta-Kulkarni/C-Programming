/*
 * Implement a circular singly linked list
 */

// 3. Implement a circular singly linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
int main()
{
struct node *head = NULL, *newnode, *temp;
int n, i, val;
printf("Enter n: ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
scanf("%d", &val);
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = val;

if (head == NULL)
{
head = newnode;
newnode->next = head;
}
else
{
temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = newnode;
newnode->next = head;
}
}
printf("Circular list:\n");
temp = head;
do
{
printf("%d ", temp->data);
temp = temp->next;
} while (temp != head);
return 0;
}
