/*
 * Selection sort, displaying the array after every pass
 */

#include <stdio.h>
int main()
{
int arr[100], n, i, j, min, temp;
printf("Enter size: ");
scanf("%d", &n);
printf("Enter elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
for (i = 0; i < n - 1; i++)
{
min = i;
for (j = i + 1; j < n; j++)
{

if (arr[j] < arr[min])
{
min = j;
}
}
temp = arr[i];
arr[i] = arr[min];
arr[min] = temp;
printf("After pass %d: ", i + 1);
for (j = 0; j < n; j++)
{
printf("%d ", arr[j]);
}
printf("\n");
}
return 0;
}
