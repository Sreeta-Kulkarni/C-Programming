/*
 * Hash table using quadratic probing
 */

#include <stdio.h>
#define SIZE 10
int table[SIZE];
void insert(int key)
{
int index = key % SIZE;
int i = 1;
while (table[index] != -1)
{
index = (key + i * i) % SIZE;
i++;
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
insert(20);
insert(30);
insert(40);
display();
}
