/*
 * Implement multiple queues in a single array
 */

// 4. Write a program to implement multiple queues in a single array.
#include <stdio.h>
#define MAX 10
int arr[MAX];
int f1 = -1, r1 = -1;
int f2 = MAX, r2 = MAX;
int main()
{
int ch, val;
while (1)
{
printf("\n1.Insert Q1 2.Insert Q2 3.Delete Q1 4.Delete Q2 5.Exit\n");
scanf("%d", &ch);
if (ch == 1)
{
scanf("%d", &val);
if (r1 + 1 == r2)
printf("Full\n");
else

{
if (f1 == -1)
f1 = 0;
arr[++r1] = val;
}
}
else if (ch == 2)
{
scanf("%d", &val);
if (r1 + 1 == r2)
printf("Full\n");
else
{
if (f2 == MAX)
f2 = MAX - 1;
arr[--f2] = val;
r2 = f2;
}
}
else if (ch == 3)
{
if (f1 == -1 || f1 > r1)
printf("Empty\n");
else
printf("%d\n", arr[f1++]);
}
else if (ch == 4)
{
if (f2 == MAX)
printf("Empty\n");
else
printf("%d\n", arr[f2++]);
}
else
break;
}
return 0;
}
