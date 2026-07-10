/*
 * Create and display a graph using an adjacency matrix
 */

#include <stdio.h>
#define MAX 10
int main()
{
int adj[MAX][MAX], n, i, j;
printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
scanf("%d", &adj[i][j]);
}
}
printf("Adjacency Matrix:\n");
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
printf("%d ", adj[i][j]);
}
printf("\n");
}
return 0;
}
