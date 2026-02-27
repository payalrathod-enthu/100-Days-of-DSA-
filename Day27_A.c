#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to calculate length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection (based on values as per problem statement)
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse together
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            return head1->data;   // Intersection found
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;  // No intersection
}

int main() {
    int n, m;

    // Input first list
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    // Input second list
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
