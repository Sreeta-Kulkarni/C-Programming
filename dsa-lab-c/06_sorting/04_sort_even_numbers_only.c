/*
 * Sort only even numbers in an array, keeping odd numbers in place
 */

#include <stdio.h>
int main()
{
int arr[100], n, i, j, temp;
printf("Enter size: ");
scanf("%d", &n);
printf("Enter elements:\n");
for (i = 0; i < n; i++)
scanf("%d", &arr[i]);
for (i = 0; i < n - 1; i++)
{
if (arr[i] % 2 == 0)
{
for (j = i + 1; j < n; j++)
{

if (arr[j] % 2 == 0 && arr[i] > arr[j])
{
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
}
}
printf("Array after sorting even numbers: ");
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
return 0;
}
