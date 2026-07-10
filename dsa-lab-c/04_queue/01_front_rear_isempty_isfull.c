/*
 * Queue with Front, Rear, IsEmpty and IsFull operations
 */

// 1. Implement Front (to fetch front element), Rear (to fetch rear element), IsEmpty, and
// IsFull functions wherever applicable.
#include <stdio.h>
#define MAX 5
int q[MAX];
int front = -1, rear = -1;
int main()
{
int ch, val, i;
while (1)
{
printf("\n1.Insert 2.Delete 3.Front 4.Rear 5.Exit\n");
scanf("%d", &ch);
if (ch == 1)
{
if (rear == MAX - 1)
printf("Full\n");
else
{
printf("Enter val: ");
scanf("%d", &val);
if (front == -1)
front = 0;
q[++rear] = val;
}
}
else if (ch == 2)
{
if (front == -1 || front > rear)
printf("Empty\n");
else
{
printf("Deleted: %d\n", q[front]);
front++;
}
}
else if (ch == 3)
{
if (front == -1 || front > rear)
printf("Empty\n");

else
printf("Front: %d\n", q[front]);
}
else if (ch == 4)
{
if (front == -1 || front > rear)
printf("Empty\n");
else
printf("Rear: %d\n", q[rear]);
}
else
break;
}
return 0;
}
