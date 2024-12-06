#ifndef LEFTIST_TREE_H
#define LEFTIST_TREE_H

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define SWAP(type, a, b) { type temp = a; a = b; b = temp; }

typedef struct {
    int key;
    void* data;
} Element;

typedef struct TreeNode {
    Element* data;
    int npl; // Null Path Length
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(Element* item);

TreeNode* merge(TreeNode* ta, TreeNode* tb);

TreeNode* insert(TreeNode* ta, Element* item);

TreeNode* deleteMin(TreeNode* root);

int shortest(TreeNode* root);

int* inorderTraversal_recur(TreeNode* root, int* returnSize);

#endif