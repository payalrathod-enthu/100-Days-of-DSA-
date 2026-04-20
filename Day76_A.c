#include <stdio.h>

int adj[100][100];   // adjacency matrix
int visited[100];
int n, m;

// DFS function
void dfs(int node)
{
    visited[node] = 1;

    for(int i = 1; i <= n; i++)
    {
        if(adj[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int u, v;
    int components = 0;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        for(int j = 1; j <= n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges:\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // count components
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
            components++;
        }
    }

    printf("Number of connected components: %d\n", components);

    return 0;
}
