
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* createTree() {
    int data;

    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* root = createNode(data);

    printf("Enter left child of %d:\n", data);
    root->left = createTree();

    printf("Enter right child of %d:\n", data);
    root->right = createTree();

    return root;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL) {
        printf("Leaf node: %d\n", root->data);
        return 1;
    }

    return countLeafNodes(root->left)
         + countLeafNodes(root->right);
}

int main() {
    struct Node* root;

    printf("Create the binary tree:\n");
    root = createTree();

    int count = countLeafNodes(root);

    printf("Total leaf nodes = %d\n", count);

    return 0;
}
