#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <assert.h>
#include "binary_search_tree.h"

int main() {
    TreeNode* root = createTreeNode(5, "10");
    root = insert(root, 6, "5");
    root = insert(root, 7, "15");
    root = insert(root, 1, "20");
    root = insert(root, 2, "25");

    assert(countNodes(root) == 5);
    assert(maxHeight(root) == 3);

    int correct[] = {1, 2, 5, 6, 7};
    int count;
    int *ans = inorderTraversal_recur(root, &count);
    for (int i = 0; i < count; i++) {
        assert(ans[i] == correct[i]);
    }
    printf("Inorder traversal is correct\n");

    // Test search node
    TreeNode* target1 = search(root, 7);
    assert(target1 != NULL);
    assert(target1->key == 7);
    assert(strcmp(target1->value, "15") == 0);

    TreeNode* target2 = search(root, 3);
    assert(target2 == NULL);

    // Test delete node
    root = delete(root, 5);
    assert(countNodes(root) == 4);
    assert(maxHeight(root) == 3);
    ans = inorderTraversal_recur(root, &count);
    int correct2[] = {1, 2, 6, 7};
    for (int i = 0; i < count; i++) {
        assert(ans[i] == correct2[i]);
    }
    printf("Inorder traversal is correct\n");
    return 0;
}
