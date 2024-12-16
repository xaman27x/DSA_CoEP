#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Binary Tree structure
typedef struct {
    struct TreeNode *root;
} BinaryTree;

void initTree(BinaryTree *tree) {
    tree->root = NULL;
}

// Create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the binary tree
struct TreeNode* insertNode(struct TreeNode *root, int data) {
    if (!root) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// In-order traversal (Left, Root, Right)
void inOrderTraversal(struct TreeNode *root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preOrderTraversal(struct TreeNode *root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postOrderTraversal(struct TreeNode *root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Search for a value in the binary tree
struct TreeNode* searchNode(struct TreeNode *root, int key) {
    if (!root || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}

// Delete a node from the binary tree
struct TreeNode* deleteNode(struct TreeNode *root, int key) {
    if (!root) {
        return root;
    }

    // Traverse to the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found, handle three cases:
        // Case 1: No child or one child
        if (!root->left) {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        struct TreeNode *temp = root->right;
        while (temp && temp->left) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Free the memory of the tree
void freeTree(struct TreeNode *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    BinaryTree tree;
    initTree(&tree);

    tree.root = insertNode(tree.root, 50);
    insertNode(tree.root, 30);
    insertNode(tree.root, 70);
    insertNode(tree.root, 20);
    insertNode(tree.root, 40);
    insertNode(tree.root, 60);
    insertNode(tree.root, 80);

    printf("In-order Traversal: ");
    inOrderTraversal(tree.root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrderTraversal(tree.root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(tree.root);
    printf("\n");

    printf("Search for 40: %s\n", searchNode(tree.root, 40) ? "Found" : "Not Found");

    printf("Deleting 50\n");
    tree.root = deleteNode(tree.root, 50);

    printf("In-order Traversal after deletion: ");
    inOrderTraversal(tree.root);
    printf("\n");

    freeTree(tree.root);
    return 0;
}
