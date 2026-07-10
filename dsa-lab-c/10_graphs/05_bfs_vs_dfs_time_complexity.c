/*
 * Compare BFS and DFS time complexity experimentally
 */

#include <stdio.h>
#include <time.h>
#define MAX 100
int adj[MAX][MAX], visited[MAX];
// DFS
void DFS(int v, int n)
{
int i;
visited[v] = 1;
for (i = 0; i < n; i++)
{
if (adj[v][i] == 1 && visited[i] == 0)
{
DFS(i, n);

}
}
}
// BFS
void BFS(int start, int n)
{
int queue[MAX], front = 0, rear = 0;
int visited[MAX] = {0};
queue[rear++] = start;
visited[start] = 1;
while (front < rear)
{
int u = queue[front++];
for (int i = 0; i < n; i++)
{
if (adj[u][i] == 1 && visited[i] == 0)
{
queue[rear++] = i;
visited[i] = 1;
}
}
}
}
int main()
{
int n = 50, i, j;
clock_t t1, t2;
// Create a dense graph
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
if (i != j)
adj[i][j] = 1;
else
adj[i][j] = 0;
}
}
// Measure DFS
t1 = clock();
for (int k = 0; k < 1000; k++)
{
for (i = 0; i < n; i++)
visited[i] = 0;
DFS(0, n);
}
t2 = clock();
printf("DFS Time: %lf sec\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
// Measure BFS
t1 = clock();
for (int k = 0; k < 1000; k++)
{
BFS(0, n);
}
t2 = clock();
printf("BFS Time: %lf sec\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
return 0;
}
