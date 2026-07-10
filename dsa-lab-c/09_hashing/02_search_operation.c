/*
 * Implement the search operation on a hash table
 */

#include <stdio.h>
#define SIZE 10
int table[SIZE] = {10, 22, 31, 4, 15, 28, 17, 88, 59, 63};
void search(int key)
{
int index = key % SIZE;
int start = index;
while (table[index] != -1)
{
if (table[index] == key)
{
printf("Element found at index %d\n", index);
return;
}
index = (index + 1) % SIZE;
if (index == start)
break;
}
printf("Element not found\n");
}
int main()
{
search(15);
}
