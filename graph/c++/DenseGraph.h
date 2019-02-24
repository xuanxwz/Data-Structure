//
// Created by xuan on 19-2-24.
//

#ifndef CDS_DENSEGRAPH_H
#define CDS_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph {
private:
    int n, m;
    bool directed;
    vector<vector<bool> > g;

public:
    DenseGraph(int n, bool directed) {
        assert(n >= 0);
        this->n = n;
        this->directed = directed;
        this->m = 0;
        // g 为 n*n的bool矩阵 均为false
        g = vector<vector<bool >>(n, vector<bool>(n, false));
    }

    ~DenseGraph() {}

    int V() {
        return n;
    }

    int E() {
        return m;
    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        if (hasEdge(v, w))
            return;
        g[v][w] = true;
        if (!directed)
            g[w][v] = true;

        m++;

    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

    void show(){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }

    class adjIterator {
    private:
        DenseGraph &G;
        int v, index;

    public:
        adjIterator(DenseGraph &graph, int v):G(graph){
            assert(v >=0 && v<G.n);
            this->v = v;
            this->index = -1;
        }
        ~adjIterator(){}

        int begin(){
            index = -1;
            return next();
        }

        int next(){
            for (index += 1; index < G.V(); ++index) {
                if (G.g[v][index])
                    return index;
            }

            return -1;
        }

        bool end(){
            return index >= G.V();
        }
    };
};


#endif //CDS_DENSEGRAPH_H
