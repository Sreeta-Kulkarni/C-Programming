#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
void initGraph(struct Graph* graph, int V) {
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

// Visited array
int visited[MAX];

// DFS function
void DFS(struct Graph* graph, int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph graph;
    initGraph(&graph, n);

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    int start;
    scanf("%d", &start);

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Perform DFS
    DFS(&graph, start);

    return 0;
}