#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mst.h"

void test_simple(void) {
    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    int** G = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        G[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    /*
    7
    0 28 0 0 0 10 0
    28 0 16 0 0 0 14
    0 16 0 12 0 0 0
    0 0 12 0 22 0 18
    0 0 0 22 0 25 24
    10 0 0 0 25 0 0
    0 14 0 18 24 0 0
    */
    int costs = 0;
    Edge** MST = findKruskalMST(G, n, &costs);
    printf("Cost: %d ", costs);     // Cost: 99 (1, 6) (3, 4) (2, 7) (2, 3) (4, 5) (5, 6)
    for (int i = 0; i < (n - 1); i++) {
        printf("(%d, %d) ", MST[i]->u, MST[i]->v);
    }
    printf("\n");
}


int main(void) {
    test_simple();
    return 0;
}