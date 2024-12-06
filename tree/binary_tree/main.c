#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <assert.h>
#include "binary_tree.h"

void simple_test() {
    TreeNode* root = createTreeNode(1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    assert(countNodes(root) == 4);
    assert(countLeafNodes(root) == 2);
    assert(maxHeight(root) == 3);
    printf("Simple test passed\n");
}

void test_preorder_traversal() {
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->left->right->left = createTreeNode(6);
    root->left->right->right = createTreeNode(7);
    root->right = createTreeNode(3);
    root->right->right = createTreeNode(8);
    root->right->right->left = createTreeNode(9);

    int correct[] = {1, 2, 4, 5, 6, 7, 3, 8, 9};
    int size;
    int* ans = preorderTraversal_recur(root, &size);
    assert(size == 9);
    for (int i = 0; i < size; i++) {
        assert(ans[i] == correct[i]);
    }

    ans = preorderTraversal_iter(root, &size);
    assert(size == 9);
    for (int i = 0; i < size; i++) {
        assert(ans[i] == correct[i]);
    }
    printf("Preorder traversal test passed\n");
}

void test_inorder_traversal() {
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->left->right->left = createTreeNode(6);
    root->left->right->right = createTreeNode(7);
    root->right = createTreeNode(3);
    root->right->right = createTreeNode(8);
    root->right->right->left = createTreeNode(9);

    int correct[] = {4, 2, 6, 5, 7, 1, 3, 9, 8};
    int size;
    int* ans = inorderTraversal_recur(root, &size);
    assert(size == 9);
    for (int i = 0; i < size; i++) {
        assert(ans[i] == correct[i]);
    }

    ans = inorderTraversal_iter(root, &size);
    assert(size == 9);
    for (int i = 0; i < size; i++) {
        assert(ans[i] == correct[i]);
    }
    printf("Inorder traversal test passed\n");
}

void test_postorder_traversal() {
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->left->right->left = createTreeNode(6);
    root->left->right->right = createTreeNode(7);
    root->right = createTreeNode(3);
    root->right->right = createTreeNode(8);
    root->right->right->left = createTreeNode(9);

    int correct[] = {4, 6, 7, 5, 2, 9, 8, 3, 1};
    int size;
    int* ans = postorderTraversal_recur(root, &size);
    assert(size == 9);
    for (int i = 0; i < size; i++) {
        assert(ans[i] == correct[i]);
    }

    ans = postorderTraversal_iter(root, &size);
    assert(size == 9);
    for (int i = 0; i < size; i++) {
        assert(ans[i] == correct[i]);
    }
    printf("Postorder traversal test passed\n");
}

int main() {
    simple_test();
    test_preorder_traversal();
    test_inorder_traversal();
    test_postorder_traversal();
    return 0;
}
