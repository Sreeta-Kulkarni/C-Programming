#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int adj[MAX][MAX] = {0};

    scanf("%d %d", &n, &m);

    int directed;
    scanf("%d", &directed); 
    // 0 = undirected, 1 = directed

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if (!directed)
            adj[v][u] = 1;
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}