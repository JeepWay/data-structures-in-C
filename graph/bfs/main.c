#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "bfs.h"

void test_undirected_BFS_queue() {
    int vertices = 8;
    int static_graph[8][8] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 0}
    };
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = static_graph[i];
    }

    int correct_result[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int *bfs_result = undirected_BFS_queue(graph, vertices, 0);
    for (int i = 0; i < vertices; i++) {
        assert(bfs_result[i] == correct_result[i]);
    }
    free(bfs_result);
    printf("undirected_BFS_queue passed\n");
}


int main() {
    test_undirected_BFS_queue();
    return 0;
}