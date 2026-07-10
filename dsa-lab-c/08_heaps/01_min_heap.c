/*
 * Min heap implementation (instead of max heap)
 */

#include <stdio.h>
void Insert(int A[], int n)
{
int i = n;
int temp = A[i];
while (i > 1 && temp < A[i / 2]) // changed > to <
{
A[i] = A[i / 2];
i = i / 2;
}
A[i] = temp;
}
int main()
{
int H[] = {0, 30, 20, 15, 5, 10, 12, 6};
int i;
for (i = 2; i <= 7; i++)
Insert(H, i);
for (i = 1; i <= 7; i++)
printf("%d ", H[i]);
return 0;
}
