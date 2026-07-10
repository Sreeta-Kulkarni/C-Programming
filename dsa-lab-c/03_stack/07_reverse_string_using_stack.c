/*
 * Reverse a string using stack
 */

// 7. Reverse a string using stack
#include <stdio.h>
#include <string.h>
int main()
{
char str[50], stack[50];
int top = -1, i = 0;
printf("Enter string: ");
scanf("%s", str);
while (str[i])
{
stack[++top] = str[i];

i++;
}
printf("Reversed: ");
while (top != -1)
{
printf("%c", stack[top--]);
}
return 0;
}
