/*
 * Compare execution time of linear search vs binary search
 */

// 4. Compare execution time of linear and binary search.
#include <stdio.h>
#include <time.h>
int main()
{
int arr[1000], i, key = 999;
int n = 1000;
for (i = 0; i < n; i++)
{
arr[i] = i;
}
clock_t start, end;
start = clock();
for (i = 0; i < n; i++)
{
if (arr[i] == key)
break;
}
end = clock();
printf("Linear search time: %lf\n", (double)(end - start));
int low = 0, high = n - 1, mid;
start = clock();
while (low <= high)

{
mid = (low + high) / 2;
if (arr[mid] == key)
break;
else if (arr[mid] < key)
low = mid + 1;
else
high = mid - 1;
}
end = clock();
printf("Binary search time: %lf", (double)(end - start));
return 0;
}
