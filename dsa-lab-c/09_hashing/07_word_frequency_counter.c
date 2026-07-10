/*
 * Hash table application: word frequency counter
 */

#include <stdio.h>
#include <string.h>
int main()
{
char words[5][20] = {"apple", "banana", "apple", "orange", "banana"};
int count[5] = {0};
int i, j;
for (i = 0; i < 5; i++)
{
if (count[i] == -1)
continue;
count[i] = 1;
for (j = i + 1; j < 5; j++)
{
if (strcmp(words[i], words[j]) == 0)
{
count[i]++;
count[j] = -1;

}
}
}
for (i = 0; i < 5; i++)
{
if (count[i] != -1)
{
printf("%s -> %d\n", words[i], count[i]);
}
}
}
