#include <stdlib.h>
#include <stdio.h>
#include "general_min_leftist_tree.h"

TreeNode* createNode(Element* item) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = item;
    node->npl = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* merge(TreeNode* ta, TreeNode* tb) {
    if (ta == NULL) return tb;
    if (tb == NULL) return ta;

    if (ta->data->key > tb->data->key) {
        SWAP(TreeNode*, ta, tb);
    }
    ta->right = merge(ta->right, tb);

    if (ta->left == NULL) {
        ta->left = ta->right;
        ta->right = NULL;
        ta->npl = 1;
    } else {
        if (ta->left->npl < ta->right->npl) {
            TreeNode* temp = ta->left;
            ta->left = ta->right;
            ta->right = temp;
        }
        ta->npl = 1 + ta->right->npl;
    }
    return ta;
}

TreeNode* insert(TreeNode* ta, Element* item) {
    TreeNode* tb = createNode(item);
    return merge(ta, tb);
}

TreeNode* deleteMin(TreeNode* root) {
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    free(root);
    return merge(left, right);
}

int shortest(TreeNode* root) {
    if (root == NULL) 
        return 0;
    else    
        return 1 + min(shortest(root->left), shortest(root->right));
}

void inorder(TreeNode* root, int* ans, int* returnSize) {
    if (root == NULL) return;

    inorder(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->data->key;
    inorder(root->right, ans, returnSize);
}
int* inorderTraversal_recur(TreeNode* root, int* returnSize) { 
    *returnSize = 0;
    int *ans = (int*)malloc(200 * sizeof(int));

    inorder(root, ans, returnSize);
    ans = (int*)realloc(ans, (*returnSize) * sizeof(int));
    return ans;
}