/*
 * Convert infix expression to postfix using stack
 */

// 4. Convert infix to postfix
#include <stdio.h>
#include <ctype.h>
char stack[50];
int top = -1;
int priority(char x)
{
if (x == '+' || x == '-')
return 1;
if (x == '*' || x == '/')
return 2;
return 0;
}
int main()
{
char exp[50], post[50];
int i = 0, j = 0;
printf("Enter infix: ");
scanf("%s", exp);
while (exp[i])
{

if (isalnum(exp[i]))
post[j++] = exp[i];
else
{
while (top != -1 && priority(stack[top]) >= priority(exp[i]))
post[j++] = stack[top--];
stack[++top] = exp[i];
}
i++;
}
while (top != -1)
post[j++] = stack[top--];
post[j] = '\0';
printf("Postfix: %s", post);
return 0;
}
