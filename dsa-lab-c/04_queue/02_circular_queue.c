/*
 * Circular queue implementation using array
 */

// 2. Implement Circular Queue using arrays.
#include <stdio.h>
#define MAX 5
int q[MAX];
int front = -1, rear = -1;
int main()
{
int ch, val, i;
while (1)
{
printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
scanf("%d", &ch);
if (ch == 1)
{
if ((rear + 1) % MAX == front)
printf("Full\n");
else
{

printf("Enter val: ");
scanf("%d", &val);
if (front == -1)
front = 0;
rear = (rear + 1) % MAX;
q[rear] = val;
}
}
else if (ch == 2)
{
if (front == -1)
{
printf("Empty\n");
}
else
{
printf("Deleted: %d\n", q[front]);
if (front == rear)
front = rear = -1;
else
front = (front + 1) % MAX;
}
}
else if (ch == 3)
{
if (front == -1)
printf("Empty\n");
else
{
i = front;
while (1)
{
printf("%d ", q[i]);
if (i == rear)
break;
i = (i + 1) % MAX;
}
}
}
else
break;
}
return 0;
}
