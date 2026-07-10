/*
 * Find the K largest elements using a heap
 */

#include <stdio.h>
void Insert(int A[], int n)
{
int i = n, temp = A[i];
while(i > 1 && temp > A[i/2])
{
A[i] = A[i/2];
i = i/2;
}
A[i] = temp;
}
int Delete(int A[], int n)
{
int i = 1, j = 2, temp, val;
val = A[1];
A[1] = A[n];
A[n] = val;
while(j < n-1)
{
if(A[j+1] > A[j])
j++;
if(A[i] < A[j])
{
temp = A[i];
A[i] = A[j];
A[j] = temp;
i = j;
j = 2*j;
}
else break;
}

return val;
}
int main()
{
int H[] = {0, 10, 20, 5, 30, 25};
int i, k = 3;
for(i=2;i<=5;i++)
Insert(H,i);
printf("K largest elements:\n");
for(i=5;i>5-k;i--)
printf("%d ", Delete(H,i));
return 0;
}
