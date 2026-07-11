#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adjList;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int directed) {
    // Add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    // If undirected, add u to v's list
    if (!directed) {
        newNode = createNode(u);
        newNode->next = graph->adjList[v];
        graph->adjList[v] = newNode;
    }
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        struct Node* temp = graph->adjList[i];

        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int directed;
    scanf("%d", &directed); // 0 = undirected, 1 = directed

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v, directed);
    }

    printGraph(graph);

    return 0;
}