/*
 * Bubble sort with swap and comparison counters
 */

#include <stdio.h>
int main()
{
int arr[100], n, i, j, temp;
int comp = 0, swaps = 0;
printf("Enter size: ");
scanf("%d", &n);
printf("Enter elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
for (i = 0; i < n - 1; i++)
{
for (j = 0; j < n - i - 1; j++)
{

comp++;
if (arr[j] > arr[j + 1])
{
temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
swaps++;
}
}
}
printf("Sorted array: ");
for (i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\nComparisons = %d", comp);
printf("\nSwaps = %d", swaps);
return 0;
}
