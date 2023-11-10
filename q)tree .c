#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree from an array
struct TreeNode* buildTreeFromArray(int arr[], int index, int size) {
    if (index < size) {
        struct TreeNode* newNode = createNode(arr[index]);

        // Recursively build left and right subtrees
        newNode->left = buildTreeFromArray(arr, 2 * index + 1, size);
        newNode->right = buildTreeFromArray(arr, 2 * index + 2, size);

        return newNode;
    }
    return NULL;
}

// Function to print the tree in an in-order traversal
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct TreeNode* root = buildTreeFromArray(arr, 0, size);

    printf("In-order traversal of the binary tree: ");
    inorderTraversal(root);

    return 0;
}
