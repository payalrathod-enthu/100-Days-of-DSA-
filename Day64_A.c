#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int v) {
    if(rear == MAX - 1)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if(front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int s) {
    enqueue(s);
    visited[s] = 1;

    while(front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int s;

    // number of vertices
    scanf("%d", &n);

    // adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    // source
    scanf("%d", &s);

    // initialize visited
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    bfs(s);

    return 0;
}
