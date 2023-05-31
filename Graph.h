#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "PriorityQ.h"

typedef struct {
    int arr[MAX_SIZE][MAX_SIZE];
} GraphData;

typedef GraphData* Graph;

Graph spanningTree(Graph g1, int n) {
    Graph g2 = (Graph)malloc(sizeof(GraphData));
    memset(g2->arr, -1, sizeof(g2->arr));

    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->size = 0;
    h->maxSize = n * n;

    int* vis = (int*)malloc(n * sizeof(int));
    memset(vis, 0, n * sizeof(int));

    insertMin(h, 0, 0, -1);

    while (!empty(h)) {
        int* t = top(h);
        int wt = t[0];
        int node = t[1];
        int parent = t[2];
        deleteMin(h);

        if (vis[node] == 1) {
            continue;
        }

        vis[node] = 1;

        if (parent >= 0) {
            g2->arr[node][parent] = wt;
            g2->arr[parent][node] = wt;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] != 1 && g1->arr[node][i] != -1) {
                insertMin(h, g1->arr[node][i], i, node);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                g2->arr[i][j] = 0;
            }
        }
    }

    free(vis);
    free(h);
    return g2;
}
int sumgraph(Graph g,int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j<n;j++)
        {
            if(i>j && g->arr[i][j]>0)
            {
                sum=sum+g->arr[i][j];
            }
        }
        
    }
    return sum;

}
void printMatrix(int arr[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}