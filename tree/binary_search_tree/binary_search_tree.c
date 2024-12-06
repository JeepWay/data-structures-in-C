#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_search_tree.h"

TreeNode* createTreeNode(int key, void* value) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int key, void* value) {
    if(!root) {
        return createTreeNode(key, value);
    }

    if (key < root->key) {
        root->left = insert(root->left, key, value);
    } else if (key > root->key) {
        root->right = insert(root->right, key, value);
    } else {
        printf("Key %d already exists in the BST\n", key);
    }
    return root;
}

TreeNode* search(TreeNode* root, int key) {
    if (!root)  return NULL;

    if (root->key == key) {
        return root;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

TreeNode* delete(TreeNode* root, int key) {
    if (!root) {
        printf("Key %d not found in the BST\n", key);
        return NULL;
    }

    if (root->key < key) {
        root->right = delete(root->right, key);
        return root;
    } else if (root->key > key) {
        root->left = delete(root->left, key);
        return root;
    } else {
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        } else if (!root->left || !root->right) {
            TreeNode* new_root = (root->left != NULL) ? root->left : root->right;
            free(root);
            return new_root;
        } else {
            TreeNode* max_left = root->left;
            while (max_left->right) {
                max_left = max_left->right;
            }
            root->key = max_left->key;
            root->value = max_left->value;
            root->left = delete(root->left, max_left->key);
            return root;
        }
    }
}

bool isEmpty(TreeNode* root) {
    return root == NULL;
}

int maxHeight(TreeNode* root){    
    if (!root)   
        return 0;
    else
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(TreeNode* root, int* ans, int* returnSize) {
    if (root == NULL) return;

    inorder(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->key;
    inorder(root->right, ans, returnSize);
}
int* inorderTraversal_recur(TreeNode* root, int* returnSize) { 
    *returnSize = 0;
    int *ans = (int*)malloc(200 * sizeof(int));

    inorder(root, ans, returnSize);
    ans = (int*)realloc(ans, (*returnSize) * sizeof(int));
    return ans;
}