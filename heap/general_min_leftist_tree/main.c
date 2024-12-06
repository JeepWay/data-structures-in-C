#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "general_min_leftist_tree.h"

void testMerge() {
    /* case in textbook */
    Element e1 = {2, "2"}; TreeNode* rootA = createNode(&e1);
    Element e2 = {7, "7"}; rootA->left = createNode(&e2);
    Element e3 = {11, "11"}; rootA->left->left = createNode(&e3);
    Element e4 = {13, "13"}; rootA->left->left->left = createNode(&e4);
    Element e5 = {50, "50"}; rootA->right = createNode(&e5);
    Element e6 = {80, "80"}; rootA->right->left = createNode(&e6);

    Element e7 = {5, "5"}; TreeNode* rootB = createNode(&e7);
    Element e8 = {9, "9"}; rootB->left = createNode(&e8);
    Element e9 = {12, "12"}; rootB->left->left = createNode(&e9);
    Element e10 = {20, "20"}; rootB->left->left->left = createNode(&e10);
    Element e11 = {18, "18"}; rootB->left->left->right = createNode(&e11);
    Element e12 = {8, "8"}; rootB->right = createNode(&e12);
    Element e13 = {10, "10"}; rootB->right->left = createNode(&e13);
    Element e14 = {15, "15"}; rootB->right->left->left = createNode(&e14);

    TreeNode* root = merge(rootA, rootB);
    int correct[] = {15, 10, 8, 80, 50, 5, 20, 12, 18, 9, 2, 13, 11, 7};
    int returnSize;
    int* ans = inorderTraversal_recur(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        assert(ans[i] == correct[i]);
    }
    assert(shortest(root) == 2);
    assert(root->npl == 2);
    free(ans);
    printf("Merge test passed\n");
}

void testInsert() {
    Element e1 = {2, "2"};  TreeNode* rootA = createNode(&e1);
    Element e2 = {7, "7"}; rootA->left = createNode(&e2);
    Element e3 = {11, "11"}; rootA->left->left = createNode(&e3);
    Element e4 = {13, "13"}; rootA->left->left->left = createNode(&e4);
    Element e5 = {50, "50"}; rootA->right = createNode(&e5);
    Element e6 = {80, "80"}; rootA->right->left = createNode(&e6);
    Element e7 = {8, "8"};  

    TreeNode* root = insert(rootA, &e7);
    int correct[] = {13, 11, 7, 2, 80, 50, 8};
    int returnSize;
    int* ans = inorderTraversal_recur(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        assert(ans[i] == correct[i]);
    }
    assert(shortest(root) == 2);
    assert(root->npl == 2);
    free(ans);
    printf("Insert test passed\n");
}

void testDeleteMin() {
    Element e1 = {2, "2"}; TreeNode* rootA = createNode(&e1);
    Element e2 = {7, "7"}; rootA->left = createNode(&e2);
    Element e3 = {11, "11"}; rootA->left->left = createNode(&e3);
    Element e4 = {13, "13"}; rootA->left->left->left = createNode(&e4);
    Element e5 = {50, "50"}; rootA->right = createNode(&e5);
    Element e6 = {80, "80"}; rootA->right->left = createNode(&e6);

    TreeNode* root = deleteMin(rootA);
    int correct[] = {13, 11, 7, 80, 50, 8};
    int returnSize;
    int* ans = inorderTraversal_recur(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        assert(ans[i] == correct[i]);
    }
    assert(shortest(root) == 2);
    assert(root->npl == 2);
    free(ans);
    printf("DeleteMin test passed\n");
}


int main() {
    testMerge();
    testInsert();
    testDeleteMin();
    return 0;
}