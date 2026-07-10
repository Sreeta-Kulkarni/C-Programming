/*
 * Implement two stacks in a single array
 */

// 6. Implement two stacks in one array
#include <stdio.h>
#define MAX 10
int arr[MAX];
int top1 = -1, top2 = MAX;
int main()
{
int ch, val;
while (1)
{
printf("\n1.Push1 2.Push2 3.Pop1 4.Pop2 5.Exit\n");
scanf("%d", &ch);
if (ch == 1)
{
scanf("%d", &val);

if (top1 + 1 == top2)
printf("Full\n");
else
arr[++top1] = val;
}
else if (ch == 2)
{
scanf("%d", &val);
if (top1 + 1 == top2)
printf("Full\n");
else
arr[--top2] = val;
}
else if (ch == 3)
{
if (top1 == -1)
printf("Empty\n");
else
printf("%d\n", arr[top1--]);
}
else if (ch == 4)
{
if (top2 == MAX)
printf("Empty\n");
else
printf("%d\n", arr[top2++]);
}
else
break;
}
return 0;
}
