/*
 * Linear search modified to count number of comparisons
 */

// 1. Modify linear search to count number of comparisons.
#include <stdio.h>
int main()
{
int n, i, key, found = 0, comp = 0;
int arr[100];
printf("Enter number of elements: ");
scanf("%d", &n);
if (n <= 0)
{
printf("Invalid input");
return 0;
}
printf("Enter elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("Enter element to search: ");
scanf("%d", &key);
for (i = 0; i < n; i++)
{
comp++;
if (arr[i] == key)
{
printf("Element found at position %d\n", i + 1);
found = 1;
break;
}
}
if (found == 0)
printf("Element not found\n");
printf("Total comparisons = %d", comp);
return 0;
}
