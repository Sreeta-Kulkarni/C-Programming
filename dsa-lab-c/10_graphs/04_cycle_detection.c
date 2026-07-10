/*
 * Detect a cycle in a graph
 */

#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX];
int hasCycle(int v, int parent, int n)
{
int i;
visited[v] = 1;
for (i = 0; i < n; i++)
{
if (adj[v][i])
{
if (!visited[i])
{
if (hasCycle(i, v, n))
return 1;
}
else if (i != parent)
{
return 1;
}

}
}
return 0;
}
int main()
{
int n, i, j;
printf("Enter vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
scanf("%d", &adj[i][j]);
if (hasCycle(0, -1, n))
printf("Cycle detected\n");
else
printf("No cycle\n");
return 0;
}
