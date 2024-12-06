#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"
#include "../../stack/general_stack/general_stack.h"

TreeNode* createTreeNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int data) {
    if(!root) {
        return createTreeNode(data);
    }

    if (!root->left) {
        root->left = insert(root->left, data);
    } else if (!root->right) {
        root->right = insert(root->right, data);
    } else {
        root->left = insert(root->left, data);
    }
    return root;
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

int countLeafNodes(TreeNode* root) {
    if (!root) return 0;
    
    if (!root->left && !root->right) {
        return 1;
    } else {
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

int* preorderTraversal_iter(TreeNode* root, int* returnSize) {
    Stack *s = createStack();
    *returnSize = 0;
    int* ans = (int*)malloc(200*sizeof(int));

    while (root || !isEmptyStack(s)) {
        if (root) {
            ans[(*returnSize)++] = root->val;
            if (root->right) {
                pushStack(s, root->right);
            }
            root = root->left;
        } else {
            root = (TreeNode*)topStack(s);
            popStack(s);
        }
    }
    
    freeStack(s);
    ans = (int*)realloc(ans, *returnSize * sizeof(int));
    return ans;
}

void preorder(TreeNode* root, int* ans, int* returnSize) {
    if (root == NULL) return;

    ans[(*returnSize)++] = root->val;
    preorder(root->left, ans, returnSize);
    preorder(root->right, ans, returnSize);
}
int* preorderTraversal_recur(TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *ans = (int*)malloc(200 * sizeof(int));
    preorder(root, ans, returnSize);
    ans = (int*)realloc(ans, (*returnSize) * sizeof(int));
    return ans;
}

int* inorderTraversal_iter(TreeNode* root, int* returnSize) {
    Stack *s = createStack();
    *returnSize = 0;
    int* ans = (int*)malloc(200*sizeof(int));

    while (root || !isEmptyStack(s)) {
        if (root) {
            pushStack(s, root);
            root = root->left;
        } else {
            root = (TreeNode*)topStack(s);
            popStack(s);
            ans[(*returnSize)++] = root->val;
            root = root->right;
        }
    }
    
    freeStack(s);
    ans = (int*)realloc(ans, *returnSize * sizeof(int));
    return ans;
}

void inorder(TreeNode* root, int* ans, int* returnSize) {
    if (root == NULL) return;

    inorder(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->val;
    inorder(root->right, ans, returnSize);
}
int* inorderTraversal_recur(TreeNode* root, int* returnSize) { 
    *returnSize = 0;
    int *ans = (int*)malloc(200 * sizeof(int));

    inorder(root, ans, returnSize);
    ans = (int*)realloc(ans, (*returnSize) * sizeof(int));
    return ans;
}

int* postorderTraversal_iter(TreeNode* root, int* returnSize) {
    Stack *s = createStack();
    *returnSize = 0;
    int* reverse_ans = (int*)malloc(200*sizeof(int));
    if (!root)  return NULL;

    pushStack(s, root); 
    while (!isEmptyStack(s)) {
        root = (TreeNode*)topStack(s);
        popStack(s);
        reverse_ans[(*returnSize)++] = root->val;
		if (root->left) {
            pushStack(s, root->left);
		}
		if (root->right) {
            pushStack(s, root->right);
		}  
    }
    
    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0, j = (*returnSize-1); i < *returnSize; i++, j--) {
        ans[i] = reverse_ans[j];
    }
    freeStack(s);
    free(reverse_ans);
    return ans;
}

void postorder(TreeNode* root, int* ans, int* returnSize) {
    if(root == NULL)  return;

    postorder(root->left, ans, returnSize);
    postorder(root->right, ans, returnSize);
    ans[(*returnSize)++] = root->val;
}
int* postorderTraversal_recur(TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *ans = (int*)malloc(200 * sizeof(int));
    postorder(root, ans, returnSize);
    ans = (int*)realloc(ans, (*returnSize) * sizeof(int));
    return ans;
}

TreeNode* invertTree(TreeNode* root) {
    if (!root)  return NULL;

    invertTree(root->left);
    invertTree(root->right);
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    return root;
}

