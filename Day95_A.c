#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float val;
    struct Node* next;
};

// insert in sorted order (insertion sort inside bucket)
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->val >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL && curr->next->val < value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void bucketSort(float arr[], int n) {
    // Step 1: create buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Step 2: distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);
        insertSorted(&buckets[index], arr[i]);
    }

    // Step 3: concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->val;
            curr = curr->next;
        }
    }

    // free memory
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
