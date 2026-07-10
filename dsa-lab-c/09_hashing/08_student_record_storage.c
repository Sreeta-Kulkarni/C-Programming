/*
 * Hash table application: student record storage
 */

#include <stdio.h>
struct student
{
int id;
char name[20];
};
int main()
{
struct student s[3] = {
{1, "Krishna"},
{2, "Aman"},
{3, "Rahul"}};
int i;
for (i = 0; i < 3; i++)
{
printf("ID: %d Name: %s\n", s[i].id, s[i].name);
}
}
