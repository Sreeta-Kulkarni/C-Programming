/*
 * Check for balanced parentheses using stack
 */

// 3. Check balanced parentheses
#include <stdio.h>
#define MAX 50
int main()
{
char exp[MAX], stack[MAX];
int top = -1, i = 0;
printf("Enter exp: ");
scanf("%s", exp);
while (exp[i] != '\0')
{
if (exp[i] == '(')
stack[++top] = '(';
else if (exp[i] == ')')
{
if (top == -1)
{
printf("Not balanced");
return 0;
}
top--;
}
i++;

}
if (top == -1)
printf("Balanced");
else
printf("Not balanced");
return 0;
}
