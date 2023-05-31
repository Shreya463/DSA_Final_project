#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include<string.h>
#include"Stack.h"
#define MAX_SIZE 30
int* dfs(int graph[MAX_SIZE][MAX_SIZE], int vertices, int start) {
    int visited[MAX_SIZE] = {0}; // Array to track visited vertices

    struct Stack stack;
    create(&stack);

    push(&stack, start); // Push the starting vertex onto the stack

    int* traversedNodes = (int*)malloc(vertices * sizeof(int));
    int index = 0;

    while (!isEmpty(stack)) {
        int vertex = pop(&stack); // Pop a vertex from the stack

        if (!visited[vertex]) {
            visited[vertex] = 1; // Mark the vertex as visited
            traversedNodes[index++] = vertex; // Store the traversed vertex in the array

            // Traverse the neighbors of the current vertex
            for (int i = 0; i < vertices; i++) {
                if (graph[vertex][i] != 0 && !visited[i]) {
                    push(&stack, i); // Push unvisited neighbor onto the stack
                }
            }
        }
    }

    return traversedNodes;
}

void printarray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}