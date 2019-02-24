//
// Created by xuan on 19-2-24.
//

#ifndef CDS_COMPONENTS_H
#define CDS_COMPONENTS_H

#include <iostream>
#include <cassert>

using namespace std;

// 求无权图的连通分量
template<typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int ccount; // 连通分量
    int *id;

    void dfs(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i])
                dfs(i);
        }
    }

public:
    Component(Graph &graph) : G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
            id[i] = -1;
        }

        // 求图的联通分量
        for (int j = 0; j < G.V(); ++j) {
            if (!visited[j]) {
                dfs(j);
                ccount++;
            }
        }
    }

    ~Component() {
        delete[] id;
        delete[] visited;
    }

    int count() {
        return ccount;
    }

    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[v] == id[w];
    }
};


#endif //CDS_COMPONENTS_H
