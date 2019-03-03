//
// Created by xuan on 19-3-3.
//

#ifndef CDS_ADJLIST_H
#define CDS_ADJLIST_H

#include <iostream>
#include "graph.h"

class adjList : public graph {
private:
    struct edgeNode {
        int to; // 定点表中的下标
        int weight;
        edgeNode *next;

        edgeNode() {}

        edgeNode(int t, int w, edgeNode *n = NULL) {
            to = t;
            weight = w;
            next = n;
        }
    };

    struct verNode {
        int vertex;
        edgeNode *firstEdge;

        verNode(edgeNode *h = NULL) {
            firstEdge = h;
        }
    };

    verNode *verList;
    int *topOrder;

    void dfs(int start) const {

    }

public:
    adjList(int size) {
        verNum = size;
        edgeNum = 0;
        verList = new verNode[size];
        visited = new bool[verNum];
        TE = new mstEdge[verNum - 1];
        topOrder = new int[verNum];
    }

    ~adjList() {
        edgeNode *p;
        int i;
        for (i = 0; i < verNum; ++i) {
            while ((p = verList[i].firstEdge) != NULL) {
                verList[i].firstEdge = p->next;
                delete p;
            }
        }
        delete[] verList;
        delete[] visited;
        delete TE;
        delete[] topOrder;
    }

    bool searchEdge(int from, int to) const {
        if (from < 0 || from > verNum - 1 || to < 0 || to > verNum - 1)
            return false;
        edgeNode *p = verList[from].firstEdge;
        while (p != NULL && p->to != to) {
            p = p->next;
        }
        return p != NULL;
    }

    bool insertEdge(int from, int to, int w) {
        if (from < 0 || from > verNum - 1 || to < 0 || to > verNum - 1)
            return false;
        edgeNode *p = verList[from].firstEdge, *per, *s;
        while (p != NULL && p->to < to) {
            per = p;
            p = p->next;

        }
        if (p != NULL && p->to == to) {
            if (p->weight != w)
                p->weight = w;
            else
                return false;

        } else {
            s = new edgeNode{to, w, p};
            if (p == verList[from].firstEdge)
                verList[from].firstEdge = s;
            else
                per->next = s;
            edgeNum++;
        }

        return true;
    }

    bool removeEdge(int from, int to) {
        if (from < 0 || from > verNum - 1 || to < 0 || to > verNum - 1)
            return false;
        edgeNode *p = verList[from].firstEdge, *pre = NULL;
        while (p != NULL && p->to < to) {
            pre = p;
            p = p->next;
        }
        if (p == NULL || p->to > to)
            return false;
        if( p->to == to){
            if(p == verList[from].firstEdge)
                verList[from].firstEdge = p->next;
            else
                pre->next = p->next;
            delete p;
            --edgeNum;
            return true;
        }
    }

    void printGraph()const {
        int i;
        for (i = 0; i < verNum; ++i) {
            std::cout << verList[i].vertex << ":";
            edgeNode *p = verList[i].firstEdge;
            while (p != NULL){
                std::cout << verList[p->to].vertex << " ";
                p = p->next;
            }
            std::cout << std::endl;
        }
    }
};



#endif //CDS_ADJLIST_H
