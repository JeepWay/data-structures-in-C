#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../stack/general_stack/general_stack.h"

int* undirected_DFS_stack(int** graph, int vertices, int start){
    int *result = (int*)malloc(sizeof(int) * vertices);
    int index = 0;

    bool visited[vertices];
    for (int i = 0; i < vertices; i++) {
        result[i] = -1;
        visited[i] = false;
    }

    Stack *s = createStack();
    pushStack(s, &start);

    while (!isEmptyStack(s)) {
        int* ptrU = (int*)topStack(s);
        int u = *ptrU;
        popStack(s);
        free(ptrU);
        if(!visited[u]){
            visited[u] = true;
            result[index++] = u;
            for(int v = vertices - 1; v >= 0; v--){
                if(graph[u][v] == 1 && !visited[v]){
                    int* ptrV = (int*)malloc(sizeof(int));
                    *ptrV = v;
                    pushStack(s, ptrV);
                }
            }
        }
    }
    freeStack(s);
    return result;
}

void undirected_DFS_helper(int** graph, int vertices, int start, int *result, bool* visited, int* index) {
    visited[start] = true;
    result[(*index)++] = start;
    for (int v = 0; v < vertices; v++) {
        if (graph[start][v] == 1 && !visited[v]) {
            undirected_DFS_helper(graph, vertices, v, result, visited, index);
        }
    }
}

int* undirected_DFS_recursive(int** graph, int vertices, int start) {
    int *result = (int*)malloc(sizeof(int) * vertices);
    bool *visited = (bool*)malloc(sizeof(bool) * vertices);
    int index = 0;
    for (int i = 0; i < vertices; i++) {
        result[i] = -1;
        visited[i] = false;
    }
    undirected_DFS_helper(graph, vertices, start, result, visited, &index);
    free(visited);
    return result;
}

