#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>    
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct avl_node_t {
    int key;       
    void *data;            
    int height;
    struct avl_node_t *left; 
    struct avl_node_t *right;
} avl_node_t;

avl_node_t* createNode(int key, void *data) {
    avl_node_t* node = malloc(sizeof(avl_node_t));
    node->key = key;
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(avl_node_t *node) {
    return node ? node->height : 0;
}

int getBalance(avl_node_t *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

avl_node_t* rotateRight(avl_node_t *y) {
    avl_node_t *x = y->left;
    avl_node_t *T2 = x->right;

    // 旋轉操作
    x->right = y;
    y->left = T2;

    // 更新高度
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

avl_node_t* rotateLeft(avl_node_t *x) {
    avl_node_t *y = x->right;
    avl_node_t *T2 = y->left;

    // 旋轉操作
    y->left = x;
    x->right = T2;

    // 更新高度
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

avl_node_t* minValueNode(avl_node_t *node) {
    avl_node_t *current = node;
    while (current->left)
        current = current->left;
    return current;
}

avl_node_t* insertNode(avl_node_t *node, int key) {
    if (!node)
        return createNode(key, NULL);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node; // 不允許重複鍵

    // 更新高度
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // 計算平衡因子
    int balance = getBalance(node);

    // 平衡樹
    // 左左情況
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // 右右情況
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // 左右情況
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // 右左情況
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

avl_node_t* deleteNode(avl_node_t *root, int key) {
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // 單子節點或無子節點
        if (!root->left || !root->right) {
            avl_node_t *temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            // 兩個子節點
            avl_node_t *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return root;

    // 更新高度
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // 平衡樹
    int balance = getBalance(root);

    // 左左情況
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // 左右情況
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // 右右情況
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // 右左情況
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inOrder(avl_node_t *root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(avl_node_t *root) {
    if (root) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

#endif // AVL_TREE_H



int main() {
    avl_node_t *root = NULL;

    root = insertNode(root, 2);
    root = insertNode(root, 5);
    root = insertNode(root, 8);
    root = insertNode(root, 4);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 9);
    root = insertNode(root, 10);
    root = insertNode(root, 7);
    root = insertNode(root, 6);
    printf("preorder traversal of the AVL tree is:\n");
    preOrder(root);
    /*
    preorder traversal of the AVL tree is:
    5 3 2 1 4 8 7 6 9 10 
    */

    root = deleteNode(root, 5);
    printf("\nAfter deletion of 5:\n");
    preOrder(root);

    root = deleteNode(root, 7);
    printf("\nAfter deletion of 7:\n");
    preOrder(root);

    root = deleteNode(root, 8);
    printf("\nAfter deletion of 8:\n");
    preOrder(root);

    root = deleteNode(root, 10);
    printf("\nAfter deletion of 10:\n");
    preOrder(root);
}