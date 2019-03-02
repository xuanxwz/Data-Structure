//
// Created by xuan on 19-1-24.
//


template <class Vertex, class Edge>
class graph {
protected:
    int data;
};


//template <typename Vertex, typename Edge>
//class graph {
//protected:


//    struct mstEdge{
//        int vex1, vex2;
//        Edge weight;
//        bool operator<(const mstEdge &e) const {
//            return weight < e.weight;
//        }
//    }*TE;
//    int edgeNum;
//    bool *visited;
//    int verNum;
//public:
//    virtual int numOfVertex(){ return verNum;}
//
//    virtual int numOfEdge(){ return edgeNum;}
//    virtual void createGraph(const Vertex V[], const Edge E[]) = 0;
//    virtual void dfsTraverse()const =0;
//    virtual void bfsTraverse()const =0;
//    virtual bool topSort()const =0;
//    virtual void prim(Edge noEgde) const=0;
//    virtual void kruskal()const =0;
//    virtual void printMst()const =0;
//    virtual bool searchEdge(int from, int to)const =0;
//    virtual bool insertEdge(int from, int to, Edge w)=0;
//    virtual bool removeEdge(int from, int to)=0;
//    virtual void printGraph()const =0;
//};
