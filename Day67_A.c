#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int v) {
    stack[++top] = v;
}

void dfs(int v) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    push(v);  // push after visiting neighbors
}

int main() {
    scanf("%d", &n);

    // adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i])
            dfs(i);
    }

    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
