/*
 * Calculate the load factor of the hash table
 */

#include <stdio.h>
int main()
{
int elements = 7;
int size = 10;
float load_factor = (float)elements / size;
printf("Load Factor = %.2f\n", load_factor);
}
