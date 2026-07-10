# Graphs

## 📖 Theory

Experiment 10: Graphs
Aim: To understand graph representation and implement graph traversal algorithms:
- •

DFS (Depth First Search)
BFS (Breadth First Search).

What is a Graph?
A graph is a non-linear data structure consisting of:
- Vertices (nodes)

- Edges (connections between nodes)

Types of Graphs:
- Directed vs Undirected

- Weighted vs Unweighted

- Cyclic vs Acyclic

Graph Representation:
- Adjacency Matrix

- Adjacency List

Graph Traversal Algorithms:
Breadth First Search (BFS)
- Explores level by level.

- Uses a queue.

- Visits all neighbors first before going deeper.

Depth First Search (DFS)
- Explores as deep as possible.

- Uses recursion or stack.

Example Program 1: BFS using Adjacency Matrix
```c
#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
if (rear == MAX - 1) return;
if (front == -1) front = 0;
queue[++rear] = v;
}

int dequeue() {
return queue[front++];
}

void BFS(int v, int n) {
enqueue(v);
visited[v] = 1;

while (front <= rear) {
int u = dequeue();

printf("%d ", u);

for (int i = 0; i < n; i++) {
if (adj[u][i] && !visited[i]) {
enqueue(i);
visited[i] = 1;
}
}
}
}

int main() {
int n, start;
printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix:\n");
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
scanf("%d", &adj[i][j]);

printf("Enter starting vertex: ");
scanf("%d", &start);

BFS(start, n);
return 0;
}
```
Example Program 2: DFS using Recursion
```c
#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], visited[MAX];

void DFS(int v, int n) {
printf("%d ", v);
visited[v] = 1;

for (int i = 0; i < n; i++) {
if (adj[v][i] && !visited[i]) {
DFS(i, n);
}
}
}

int main() {
int n, start;

printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix:\n");
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
scanf("%d", &adj[i][j]);

printf("Enter starting vertex: ");
scanf("%d", &start);

DFS(start, n);
return 0;
}
```
Tasks:
1.
2.
3.
4.
5.

Create a graph using adjacency matrix.
Implement BFS and DFS.
Print traversal order.
Detect cycles in a graph.
Compare BFS and DFS time complexity experimentally.

---

## 💻 Programs

1. [`01_adjacency_matrix.c`](./01_adjacency_matrix.c) — Create and display a graph using an adjacency matrix
2. [`02_bfs_traversal.c`](./02_bfs_traversal.c) — Breadth First Search (BFS) traversal, queue based
3. [`03_dfs_traversal.c`](./03_dfs_traversal.c) — Depth First Search (DFS) traversal, recursive
4. [`04_cycle_detection.c`](./04_cycle_detection.c) — Detect a cycle in a graph
5. [`05_bfs_vs_dfs_time_complexity.c`](./05_bfs_vs_dfs_time_complexity.c) — Compare BFS and DFS time complexity experimentally

## 🛠️ How to compile & run

```bash
gcc 01_adjacency_matrix.c -o output
./output
```

Run the same way for any of the other 4 files in this folder — just swap the filename.
