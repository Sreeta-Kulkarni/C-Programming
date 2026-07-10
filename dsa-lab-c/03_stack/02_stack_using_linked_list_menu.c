/*
 * Menu-driven stack implementation using linked list
 */

// 2. Implement menu-driven stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top = NULL;
int main()
{
int ch, val;
struct node *temp;
while (1)

{
printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
scanf("%d", &ch);
if (ch == 1)
{
scanf("%d", &val);
temp = (struct node *)malloc(sizeof(struct node));
temp->data = val;
temp->next = top;
top = temp;
}
else if (ch == 2)
{
if (top == NULL)
printf("Empty\n");
else
{
temp = top;
printf("Deleted: %d\n", temp->data);
top = top->next;
free(temp);
}
}
else if (ch == 3)
{
temp = top;
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
