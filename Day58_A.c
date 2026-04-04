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

// search in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // pick root from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = createNode(rootVal);

    // if leaf node
    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, rootVal);

    // build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// postorder traversal
void postorder(struct Node* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n-1, &preIndex);

    postorder(root);

    return 0;
}
