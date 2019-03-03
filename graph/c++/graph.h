//
// Created by xuan on 19-3-3.
//

#ifndef CDS_GRAPH_H
#define CDS_GRAPH_H

// 顶点类型 int 边 类型 int
class graph {
protected:


    struct mstEdge {
        int vex1, vex2;
        int weight;

        bool operator<(const mstEdge &e) const {
            return weight < e.weight;
        }
    } *TE;

    int edgeNum;
    bool *visited;
    int verNum;
public:
    virtual int numOfVertex() { return verNum; }

    virtual int numOfEdge() { return edgeNum; }

    virtual void createGraph(const int V[], const int E[]) = 0;

    virtual void dfsTraverse() const = 0;

    virtual void bfsTraverse() const = 0;

    virtual bool topSort() const = 0;

    virtual void prim(int noEgde) const = 0;

    virtual void kruskal() const = 0;

    virtual void printMst() const = 0;

    virtual bool searchEdge(int from, int to) const = 0;

    virtual bool insertEdge(int from, int to, int w) = 0;

    virtual bool removeEdge(int from, int to) = 0;

    virtual void printGraph() const = 0;
};

#endif //CDS_GRAPH_H
