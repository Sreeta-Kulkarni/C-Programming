/*
 * Menu-driven program: insertion, deletion, traversal
 */

// 4. Write a menu-driven program to perform:
// • Insertion
// • Deletion
// • Traversal
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
int ch, val;
while (1)
{
printf("\n1.Insert 2.Delete 3.Traverse 4.Exit\n");
scanf("%d", &ch);
if (ch == 1)
{
printf("Enter val: ");
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
else if (ch == 2)
{
if (head == NULL)
{
printf("Empty\n");
}
else
{
temp = head;
while (temp->next != NULL)
{
prev = temp;
temp = temp->next;
}
if (temp == head)
head = NULL;
else
prev->next = NULL;
free(temp);

}
}
else if (ch == 3)
{
temp = head;
while (temp != NULL)
{
printf("%d ", temp->data);
temp = temp->next;
}
}
else
break;
}
return 0;
}
