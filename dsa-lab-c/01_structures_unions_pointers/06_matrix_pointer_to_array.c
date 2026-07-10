/*
 * Read and print a 3x3 matrix using pointer to an array
 */

// 6. Take a 3×3 matrix and print it using a pointer to an array.
#include <stdio.h>
int main()
{
int a[3][3], i, j;
int *p;
printf("Enter matrix:\n");
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
scanf("%d", &a[i][j]);
}
}
p = &a[0][0]; // pointing to first element
printf("\nMatrix:\n");
for (i = 0; i < 9; i++)
{
printf("%d ", *(p + i));
if ((i + 1) % 3 == 0)
printf("\n");
}
return 0;
}
