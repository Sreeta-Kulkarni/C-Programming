/*
 * Book structure - input & display 3 books
 */

// 1. Create a structure for Book with title, author, and price. Input and display 3 books.
#include <stdio.h>
struct Book
{
char title[50];
char author[50];
float price;
};
int main()
{
struct Book b[3];
int i;
for (i = 0; i < 3; i++)
{
printf("Enter title: ");
scanf("%s", b[i].title);
printf("Enter author: ");
scanf("%s", b[i].author);
printf("Enter price: ");
scanf("%f", &b[i].price);
}
printf("\nBooks:\n");
for (i = 0; i < 3; i++)
{
printf("%s %s %.2f\n", b[i].title, b[i].author, b[i].price);
}
return 0;
}
