/*
 * Employee structure with nested Address structure
 */

// 2. Create a structure Employee with name, ID and a nested structure Address (city, pin code).
#include <stdio.h>
struct Address
{
char city[50];
int pin;
};
struct Employee
{
char name[50];
int id;
struct Address add;
};
int main()
{
struct Employee e;
printf("Enter name: ");
scanf("%s", e.name);
printf("Enter id: ");
scanf("%d", &e.id);
printf("Enter city: ");
scanf("%s", e.add.city);
printf("Enter pin: ");
scanf("%d", &e.add.pin);
printf("\nDetails:\n");
printf("%s %d %s %d", e.name, e.id, e.add.city, e.add.pin);
return 0;
}
