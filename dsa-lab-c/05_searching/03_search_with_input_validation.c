/*
 * Search program with input validation
 */

// 3. Add input validation in all programs.
#include <stdio.h>
int main()
{
int arr[100], n, i, key, choice;
printf("Enter number of elements: ");
scanf("%d", &n);
if (n <= 0 || n > 100)
{
printf("Invalid size");
return 0;
}
printf("Enter elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("Choose search type:\n1. Linear Search\n2. Binary Search\nEnter choice: ");
scanf("%d", &choice);
printf("Enter element to search: ");
scanf("%d", &key);
if (choice == 1)
{
int found = 0;
for (i = 0; i < n; i++)
{
if (arr[i] == key)
{
printf("Found at position %d\n", i + 1);
found = 1;
break;
}
}
if (found == 0)

printf("Not found\n");
}
else if (choice == 2)
{
for (i = 0; i < n - 1; i++)
{
if (arr[i] > arr[i + 1])
{
printf("Array must be sorted for binary search");
return 0;
}
}
int low = 0, high = n - 1, mid, found = 0;
while (low <= high)
{
mid = (low + high) / 2;
if (arr[mid] == key)
{
printf("Found at index %d\n", mid);
found = 1;
break;
}
else if (arr[mid] < key)
low = mid + 1;
else
high = mid - 1;
}
if (found == 0)
printf("Not found\n");
}
else
{
printf("Invalid choice");
}
return 0;
}
