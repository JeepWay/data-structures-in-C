#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createTreeNode(int data);

TreeNode* insert(TreeNode* root, int data);

int maxHeight(TreeNode* root); 

int countNodes(TreeNode* root);

int countLeafNodes(TreeNode* root); 

int* preorderTraversal_iter(TreeNode* root, int* returnSize);  // 144. Binary Tree Preorder Traversal

int* preorderTraversal_recur(TreeNode* root, int* returnSize);  // 144. Binary Tree Preorder Traversal

int* inorderTraversal_iter(TreeNode* root, int* returnSize);  // 94. Binary Tree Inorder Traversal

int* inorderTraversal_recur(TreeNode* root, int* returnSize);  // 94. Binary Tree Inorder Traversal

int* postorderTraversal_iter(TreeNode* root, int* returnSize); // 145. Binary Tree Postorder Traversal

int* postorderTraversal_recur(TreeNode* root, int* returnSize); // 145. Binary Tree Postorder Traversal

TreeNode* invertTree(TreeNode* root);   // 226. Invert Binary Tree

#endif // BINARY_TREE_H