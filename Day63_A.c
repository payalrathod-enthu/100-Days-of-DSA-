#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int s;

    // number of vertices
    scanf("%d", &n);

    // adjacency matrix input
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // starting vertex
    scanf("%d", &s);

    // initialize visited
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}
