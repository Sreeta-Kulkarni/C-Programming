/*
 * Menu-driven stack implementation using array
 */

// 1. Implement menu-driven stack using array
#include <stdio.h>
#define MAX 5
int stack[MAX], top = -1;
int main()
{
int ch, val, i;
while (1)
{
printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
scanf("%d", &ch);
if (ch == 1)
{
if (top == MAX - 1)
printf("Overflow\n");
else
{
printf("Enter val: ");
scanf("%d", &val);
top++;
stack[top] = val;
}
}
else if (ch == 2)
{
if (top == -1)
printf("Underflow\n");
else
{
printf("Deleted: %d\n", stack[top]);
top--;
}
}
else if (ch == 3)
{
for (i = top; i >= 0; i--)
printf("%d ", stack[i]);
}
else
break;
}

return 0;
}
