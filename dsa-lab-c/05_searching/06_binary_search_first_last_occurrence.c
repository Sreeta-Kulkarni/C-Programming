/*
 * Binary search modified to find first and last occurrence
 */

// 6. Modify binary search to find first and last occurrence.
#include <stdio.h>
int first(int arr[], int n, int key)
{
int low = 0, high = n - 1, mid, res = -1;
while (low <= high)
{
mid = (low + high) / 2;
if (arr[mid] == key)
{
res = mid;
high = mid - 1;
}

else if (arr[mid] < key)
low = mid + 1;
else
high = mid - 1;
}
return res;
}
int last(int arr[], int n, int key)
{
int low = 0, high = n - 1, mid, res = -1;
while (low <= high)
{
mid = (low + high) / 2;
if (arr[mid] == key)
{
res = mid;
low = mid + 1;
}
else if (arr[mid] < key)
low = mid + 1;
else
high = mid - 1;
}
return res;
}
int main()
{
int arr[100], n, i, key;
printf("Enter size: ");
scanf("%d", &n);
printf("Enter sorted elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("Enter element: ");
scanf("%d", &key);
int f = first(arr, n, key);
int l = last(arr, n, key);
if (f == -1)
printf("Not found");
else
{
printf("First occurrence = %d\n", f);
printf("Last occurrence = %d", l);
}
return 0;
}
