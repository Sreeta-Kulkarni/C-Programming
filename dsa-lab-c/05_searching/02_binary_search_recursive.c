/*
 * Binary search implemented using recursion
 */

// 2. Implement binary search using recursion.
#include <stdio.h>
int search(int arr[], int low, int high, int key)
{
if (low > high)
return -1;
int mid = (low + high) / 2;
if (arr[mid] == key)
return mid;
if (arr[mid] > key)
return search(arr, low, mid - 1, key);
return search(arr, mid + 1, high, key);
}
int main()
{
int n, i, key;
int arr[100];
printf("Enter size: ");
scanf("%d", &n);
if (n <= 0)
{
printf("Invalid input");
return 0;
}
printf("Enter sorted elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("Enter element: ");
scanf("%d", &key);
int result = search(arr, 0, n - 1, key);
if (result == -1)
printf("Not found");
else
printf("Found at index %d", result);
return 0;

}
