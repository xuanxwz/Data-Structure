//
// Created by xuan on 19-2-24.
//

#ifndef CDS_ADJACENCY_MATRIX_H
#define CDS_ADJACENCY_MATRIX_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int T;

typedef struct graph{
    T NoEdge;
    int Vertices;
    T ** A;
}Graph;

void create_graph(Graph *g, int n, T noEdge){
    int j;
    g->NoEdge = noEdge;
    g->Vertices = n;
    g->A = (T**)malloc(n* sizeof(T*));
    for (int i = 0; i < n; ++i) {
        g->A[i] = (T*)malloc(n* sizeof(T*));
        for (j = 0; j < n; ++j) {
            g->A[i][j] = noEdge;
        }
        g->A[i][i] = 0;
    }
}

bool edge_exist(Graph g, int u, int v){
    if( u< 0 || v < 0 || u> g.Vertices-1 || v > g.Vertices-1 || g[u][])
}

#endif //CDS_ADJACENCY_MATRIX_H
