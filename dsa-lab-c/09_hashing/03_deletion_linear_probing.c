/*
 * Implement deletion using linear probing
 */

#include <stdio.h>
#define SIZE 10
int table[SIZE] = {10, 22, 31, 4, 15, 28, 17, 88, 59, 63};
void deleteKey(int key)
{
int index = key % SIZE;
int start = index;
while (table[index] != -1)
{
if (table[index] == key)
{
table[index] = -1;
printf("Deleted successfully\n");
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

deleteKey(31);
}
