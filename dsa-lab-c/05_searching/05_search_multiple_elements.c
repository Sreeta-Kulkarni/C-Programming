/*
 * Search for multiple elements in a single run
 */

// 5. Write a program to search multiple elements in one run.
#include <stdio.h>
int main()
{
int arr[100], n, i, key, found;
printf("Enter size: ");
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
while (1)
{
printf("\nEnter element to search (-1 to stop): ");
scanf("%d", &key);
if (key == -1)
break;
found = 0;
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
return 0;
}
