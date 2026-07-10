/*
 * Insertion sort, printing intermediate steps
 */

#include <stdio.h>
int main()
{
int arr[100], n, i, j, key;
printf("Enter size: ");
scanf("%d", &n);
printf("Enter elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)

{
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
printf("After inserting %d: ", key);
for (j = 0; j < n; j++)
{
printf("%d ", arr[j]);
}
printf("\n");
}
return 0;
}
