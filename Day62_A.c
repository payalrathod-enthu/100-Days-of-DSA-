#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // array of adjacency lists
    struct Node* adj[n];

    // initialize lists
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // read edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // add v to u's list
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // add u to v's list (for undirected graph)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // print adjacency list
    for(int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while(temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
