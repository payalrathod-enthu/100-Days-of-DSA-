#include <stdio.h>

int main() {
    int n, m;

    // number of vertices and edges
    scanf("%d %d", &n, &m);

    int adj[n][n];

    // initialize matrix with 0
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    int u, v;

    // read edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; // remove this line for directed graph
    }

    // print adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
