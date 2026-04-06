#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

int dfs(int v, int parent) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1) {
            if(!visited[i]) {
                if(dfs(i, v))
                    return 1;
            }
            else if(i != parent) {
                return 1;  // cycle found
            }
        }
    }
    return 0;
}

int main() {
    // number of vertices
    scanf("%d", &n);

    // adjacency matrix input
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    // initialize visited
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int hasCycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
