/*
 * Insert at least 10 elements and display the hash table
 */

#include <stdio.h>
#define SIZE 10
int table[SIZE];
void insert(int key)
{
int index = key % SIZE;
while (table[index] != -1)
{
index = (index + 1) % SIZE;
}
table[index] = key;
}
void display()
{
int i;
for (i = 0; i < SIZE; i++)
{
printf("%d -> %d\n", i, table[i]);
}
}
int main()
{
int i;
for (i = 0; i < SIZE; i++)
{
table[i] = -1;
}
insert(10);
insert(22);
insert(31);
insert(4);
insert(15);
insert(28);
insert(17);
insert(88);
insert(59);
insert(63);
display();
}
