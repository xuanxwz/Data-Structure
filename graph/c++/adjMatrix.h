//
// Created by xuan on 19-1-24.
//

#include <iostream>

#include "graph.h"

using namespace std;


template<class Vertex, class Edge>
class adjMatrix : public graph<Vertex, Edge> {
public:
    adjMatrix(int size, Edge noEdgeFlag) {
        data = 1;
    }
};

//template<class Vertex, class Edge>
//class adjMatrix : public graph<Vertex, Edge> {
//private:
//    Vertex *vertexs;
//    Edge **edges;
//    Edge noEdge;
//
//    void dfs(int start) const {
//
//    }
//
//public:
//    adjMatrix(int size, Edge noEdgeFlag) {
//        verNum = size;
//        edgeNum = 0;
//        noEdge = noEdgeFlag;
//        vertexs = new Vertex[verNum];
//        edges = new Edge *[verNum];
//        for (int i = 0; i < verNum; ++i) {
//            edges[i] = new Edge[verNum];
//            for (int j = 0; j < verNum; ++j) {
//                edges[i][j] = noEdge;
//            }
//        }
//        visited = new bool[verNum];
//        TE = new mstEdge[verNum - 1];
//    }
//
//    ~adjMatrix() {
//        delete[] vertexs;
//        for (int i = 0; i < verNum; ++i) {
//            delete[] edges[i];
//        }
//        delete[] visited;
//        delete[] edges;
//        delete[] TE;
//    }
//
//    void createGraph(const Vertex *V, const Edge *E) override {
//        for (int i = 0; i < verNum; ++i) {
//            vertexs[i] = V[i];
//        }
//        for (int i = 0; i < verNum; ++i) {
//            for (int j = 0; j < verNum; ++j) {
//                if (E[i * verNum + j] > 0)
//                    insertEdge(i, j, E[i * verNum + j]);
//            }
//        }
//    }
//
//    void dfsTraverse() const override {
//
//    }
//
//    void bfsTraverse() const override {
//
//    }
//
//    bool topSort() const override {
//        return false;
//    }
//
//    void prim(Edge noEgde) const override {
//
//    }
//
//    void kruskal() const override {
//
//    }
//
//    void printMst() const override {
//
//    }
//
//    bool searchEdge(int from, int to) const override {
//        if (from < 0 || from > verNum - 1 || to < 0 || to > verNum - 1)
//            return false;
//        return !(edges[from][to] == noEdge);
//    }
//
//    bool insertEdge(int from, int to, Edge w) override {
//        if (from < 0 || from > verNum - 1 || to < 0 || to > verNum - 1)
//            return false;
//        if (edges[from][to] == w)
//            return false;
//        if (edges[from][to] == noEdge)
//            ++edges;
//        edges[from][to] = w;
//        return true;
//    }
//
//    bool removeEdge(int from, int to) override {
//        if (from < 0 || from > verNum - 1 || to < 0 || to > verNum - 1)
//            return false;
//        if (edges[from][to] == noEdge)
//            return false;
//        edges[from][to] = noEdge;
//        --edges;
//        return true;
//    }
//
//    void printGraph() const override {
//        for (int i = 0; i < verNum; ++i) {
//            cout << vertexs[i] << ":";
//            for (int j = 0; j < verNum; ++j) {
//                cout << edges[i][j] << " ";
//            }
//        }
//        cout << endl;
//    }
//
//};
//
