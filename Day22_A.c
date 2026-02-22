#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Insert at End
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    // Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Traverse and Count Nodes
int displayAndCount(struct Node* head) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    int count = displayAndCount(head);
    printf("\nTotal Nodes: %d", count);

    return 0;
}
