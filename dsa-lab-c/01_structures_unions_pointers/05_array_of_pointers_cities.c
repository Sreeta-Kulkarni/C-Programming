/*
 * Store and print city names using array of pointers
 */

// 5. Store names of 5 cities using array of pointers and print them.
#include <stdio.h>
int main()
{
char *cities[5] = {"Delhi", "Mumbai", "Chennai", "Kolkata", "Pune"};
int i;
printf("Cities:\n");
for (i = 0; i < 5; i++)
{
printf("%s\n", cities[i]);
}
return 0;
}
