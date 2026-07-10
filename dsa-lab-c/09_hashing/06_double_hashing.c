/*
 * Implement double hashing
 */

#include <stdio.h>
#define SIZE 10
int table[SIZE];
int hash1(int key)
{
return key % SIZE;
}
int hash2(int key)
{
return 7 - (key % 7);
}
void insert(int key)
{
int index = hash1(key);
int step = hash2(key);
while (table[index] != -1)
{
index = (index + step) % SIZE;
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
display();
}
