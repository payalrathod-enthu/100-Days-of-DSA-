#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;
int n;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int main() {
    scanf("%d", &n);

    // adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    // initialize indegree
    for(int i = 0; i < n; i++)
        indegree[i] = 0;

    // calculate indegree
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(adj[i][j] == 1)
                indegree[j]++;

    // enqueue nodes with indegree 0
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            enqueue(i);

    int count = 0;

    printf("Topological Order: ");

    while(front < rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // cycle check
    if(count != n)
        printf("\nCycle detected. Topological sort not possible.");

    return 0;
}
