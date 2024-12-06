#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#define max(x, y) (((x) > (y)) ? (x) : (y))

typedef struct TreeNode {
    int key;
    void* value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createTreeNode(int key, void* value);

TreeNode* insert(TreeNode* root, int key, void* value);

TreeNode* search(TreeNode* root, int key);

TreeNode* delete(TreeNode* root, int key);

bool isEmpty(TreeNode* root);

int maxHeight(TreeNode* root); 

int countNodes(TreeNode* root);

int* inorderTraversal_recur(TreeNode* root, int* returnSize);  // 94. Binary Tree Inorder Traversal

#endif // BINARY_SEARCH_TREE_H