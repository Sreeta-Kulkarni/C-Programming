/*
 * Depth First Search (DFS) traversal, recursive
 */

#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX];
void DFS(int v, int n)
{
int i;
printf("%d ", v);

visited[v] = 1;
for (i = 0; i < n; i++)
{
if (adj[v][i] == 1 && visited[i] == 0)
{
DFS(i, n);
}
}
}
int main()
{
int n, i, j, start;
printf("Enter vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
scanf("%d", &adj[i][j]);
printf("Enter start vertex: ");
scanf("%d", &start);
DFS(start, n);
return 0;
}
