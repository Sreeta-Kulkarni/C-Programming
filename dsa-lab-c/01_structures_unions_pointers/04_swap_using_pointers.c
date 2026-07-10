/*
 * Swap two numbers using pointers
 */

// 4. Write a program to swap two numbers using pointers.
#include <stdio.h>
void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;

*b = temp;
}
int main()
{
int x, y;
printf("Enter x and y: ");
scanf("%d %d", &x, &y);
swap(&x, &y);
printf("After swap: %d %d", x, y);
return 0;
}
