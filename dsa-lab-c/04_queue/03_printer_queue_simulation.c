/*
 * Simulate a printer queue system using queue
 */

// 3. Write a program to simulate a printer queue system.
#include <stdio.h>
#define MAX 5
int q[MAX];
int front = -1, rear = -1;
int main()
{

int ch, job;
while (1)
{
printf("\n1.Add Job 2.Print Job 3.Show Queue 4.Exit\n");
scanf("%d", &ch);
if (ch == 1)
{
if (rear == MAX - 1)
printf("Queue Full\n");
else
{
printf("Enter job id: ");
scanf("%d", &job);
if (front == -1)
front = 0;
q[++rear] = job;
}
}
else if (ch == 2)
{
if (front == -1 || front > rear)
printf("No jobs\n");
else
{
printf("Printing job: %d\n", q[front]);
front++;
}
}
else if (ch == 3)
{
int i;
for (i = front; i <= rear; i++)
printf("%d ", q[i]);
}
else
break;
}
return 0;
}
