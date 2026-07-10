/*
 * Implement a priority queue using a heap
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
j = j+1;
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
int H[10] = {0};
int i;
H[1]=10; H[2]=40; H[3]=20; H[4]=30;
for(i=2;i<=4;i++)
Insert(H,i);
printf("Deleted: %d\n", Delete(H,4));
printf("Deleted: %d\n", Delete(H,3));
return 0;
}
