/*
 * Evaluate a postfix expression using stack
 */

// 5. Evaluate postfix expression
#include <stdio.h>
#include <ctype.h>
int stack[50], top = -1;
int main()
{
char exp[50];
int i = 0;
printf("Enter postfix: ");
scanf("%s", exp);
while (exp[i])
{
if (isdigit(exp[i]))
stack[++top] = exp[i] - '0';
else
{

int b = stack[top--];
int a = stack[top--];
if (exp[i] == '+')
stack[++top] = a + b;
else if (exp[i] == '-')
stack[++top] = a - b;
else if (exp[i] == '*')
stack[++top] = a * b;
else if (exp[i] == '/')
stack[++top] = a / b;
}
i++;
}
printf("Result: %d", stack[top]);
return 0;
}
