#include <stdio.h>
#include <limits.h>

int main()
{
    int n, m;
    int u, v, w, source;

    int graph[100][100];
    int dist[100];
    int visited[100] = {0};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // remove if directed graph
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    // Dijkstra Algorithm
    for(int count = 1; count <= n-1; count++)
    {
        int min = INT_MAX, u = -1;

        // Find minimum distance vertex
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        // Update distances
        for(int v = 1; v <= n; v++)
        {
            if(!visited[v] && graph[u][v] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from source:\n");
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }

    return 0;
}
