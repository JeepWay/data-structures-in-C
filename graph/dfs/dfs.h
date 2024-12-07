#ifndef DFS_H
#define DFS_H

int* undirected_DFS_stack(int** graph, int vertices, int start);

int* undirected_DFS_recursive(int** graph, int vertices, int start);

void undirected_DFS_helper(int** graph, int vertices, int start, int *result, bool* visited, int* index);

#endif