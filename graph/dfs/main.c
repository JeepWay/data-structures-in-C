#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "dfs.h"

void test_undirected_DFS_stack() {
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

    int correct_result[8] = {0, 1, 3, 7, 4, 5, 2, 6};
    int *dfs_result = undirected_DFS_stack(graph, vertices, 0);
    for (int i = 0; i < vertices; i++) {
        assert(dfs_result[i] == correct_result[i]);
    }
    free(dfs_result);
    printf("undirected_DFS passed\n");
}

void test_undirected_DFS_recursive() {
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

    int correct_result[8] = {0, 1, 3, 7, 4, 5, 2, 6};
    int *dfs_result = undirected_DFS_recursive(graph, vertices, 0);
    for (int i = 0; i < vertices; i++) {
        assert(dfs_result[i] == correct_result[i]);
    }
    free(dfs_result);
    printf("undirected_DFS passed\n");
}


int main() {
    test_undirected_DFS_stack();
    test_undirected_DFS_recursive();
    return 0;
}