#include <stdio.h>
#include <limits.h>

int main()
{
    int n, m;
    int u, v, w;

    int graph[100][100];
    int visited[100] = {0};

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph with large value (infinity)
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
        graph[v][u] = w;  // undirected graph
    }

    visited[1] = 1;  // start from node 1
    int edges = 0;
    int totalWeight = 0;

    while(edges < n - 1)
    {
        int min = INT_MAX;
        int x = 0, y = 0;

        for(int i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                for(int j = 1; j <= n; j++)
                {
                    if(!visited[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if(min != INT_MAX)
        {
            printf("Edge selected: %d - %d (Weight %d)\n", x, y, min);
            totalWeight += min;
            visited[y] = 1;
            edges++;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}
