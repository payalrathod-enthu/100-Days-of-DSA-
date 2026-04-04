#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// build tree from level order
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// check heap property
int isMinHeap(struct Node* root) {
    if (!root)
        return 1;

    // leaf node
    if (!root->left && !root->right)
        return 1;

    // only left child
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    // both children
    return (root->data <= root->left->data) &&
           (root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
