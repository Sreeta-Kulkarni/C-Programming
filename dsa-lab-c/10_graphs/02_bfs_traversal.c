/*
 * Breadth First Search (BFS) traversal, queue based
 */

#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = -1, rear = -1;
void enqueue(int v)
{
if (front == -1)
front = 0;

queue[++rear] = v;
}
int dequeue()
{
return queue[front++];
}
void BFS(int start, int n)
{
int i;
enqueue(start);
visited[start] = 1;
while (front <= rear)
{
int u = dequeue();
printf("%d ", u);
for (i = 0; i < n; i++)
{
if (adj[u][i] == 1 && visited[i] == 0)
{
enqueue(i);
visited[i] = 1;
}
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
BFS(start, n);
return 0;
}
