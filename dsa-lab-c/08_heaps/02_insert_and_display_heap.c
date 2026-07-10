/*
 * Insert 5 elements into a heap and display it
 */

#include <stdio.h>
void Insert(int A[], int n)
{
int i = n;
int temp = A[i];
while(i > 1 && temp > A[i/2])
{
A[i] = A[i/2];
i = i/2;
}
A[i] = temp;
}
int main()
{
int H[10] = {0};
int i;
H[1] = 10;
H[2] = 20;
H[3] = 5;
H[4] = 30;
H[5] = 25;
for(i=2; i<=5; i++)
Insert(H, i);
for(i=1; i<=5; i++)
printf("%d ", H[i]);

return 0;
}
