#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../queue/general_circular_array_n_slot_queue/general_array_queue.h"

int* undirected_BFS_queue(int** graph, int vertices, int start){
    int *result = (int*)malloc(sizeof(int) * vertices);
    int index = 0;
    bool visited[vertices];
    for (int i = 0; i < vertices; i++) {
        result[i] = -1;
        visited[i] = false;
    }
    visited[start] = true;

    Queue *queue = createQueue(vertices + 1);
    enqueue(queue, &start);

    while (!isQueueEmpty(queue)) {
        int* ptrU = (int*)dequeue(queue);
        int u = *ptrU;
        free(ptrU);
        result[index++] = u;
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                int* ptrV = (int*)malloc(sizeof(int));
                *ptrV = v;
                enqueue(queue, ptrV);
            }
        }
    }
    freeQueue(queue);
    return result;
}
