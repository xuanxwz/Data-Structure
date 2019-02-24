//
// Created by xuan on 19-2-24.
//

#ifndef CDS_GRAPH_H
#define CDS_GRAPH_H

typedef enum {
    GRAPH_UNDIRECTED = 0,
    GRAPH_DIRECTED = 1
} GraphType;
typedef struct _Graph Graph;	//定义图的结构，用邻接表结构
typedef struct _Vertex Vertex;	//定义顶点
typedef struct _Edge Edge;	//定义边
typedef struct _DijkstraPath DijkstraPath;
typedef struct _MinSpanningTree MinSpanningTree;
typedef void * EdgeValue;	//定义边界数值
typedef void * VertexValue;	//定义顶点数值
typedef void (*traverse_callback)(Vertex * v, int subGraphNo);
struct _Edge {
    Vertex * vertices[2];	//边连接的顶点
    EdgeValue value;
    float weight;	//权重
};
struct _Vertex {
    int id;		//节点序号
    ListEntry * edges;	//访问与顶点相连的边入口指针
    VertexValue value;	//节点数据
};
struct _DijkstraPath {
    float * pathCosts;
    int * vertexIds;
};
//图的最小生成树结构
struct _MinSpanningTree {
    float spanningTreeCost;	//最小生成树的代价
    ListEntry * edges;
};
//图的结构
struct _Graph {
    GraphType  graphType;	//图的类型（有向图、无向图）
    //顶点和边的数量
    unsigned int vertexNum;
    unsigned int edgeNum;
    //顶点列表
    ListEntry * vertices;
    ListEntry * edges;
};
Graph * graph_new(GraphType type);
void graph_initial(Graph * g);	//初始化一个图
Vertex * (*add_new_vertex)(Graph * g, VertexValue value);	//加入一个新的结点
Edge * (*add_new_edge)(Graph * g, Vertex * sourceVertex, Vertex * targetVertex, EdgeValue value);	//加入一条新边
void (*traverse_bfs)(Graph * g, Vertex * firstVertex, traverse_callback callBack);	//广度优先遍历
void (*traverse_dfs)(Graph * g, Vertex * firstVertex, traverse_callback callBack);	//深度优先遍历
MinSpanningTree * (*prim_spanning_tree)(Graph * g);		//Prim算法
MinSpanningTree * (*kruskal_spanning_tree)(Graph * g);	//Kruskal算法
void (*dijkstra)(Graph * g, Vertex * start, DijkstraPath * path);	//迪杰斯特拉算法
float ** (*floyd)(Graph * g);	//弗洛伊德算法
void (*graph_free)(Graph * g);	//销毁一个图
int critical_path_method(Graph * g, Vertex * start, float * earlyTime, float * lateTime);	//关键路径算法

#endif //CDS_GRAPH_H
