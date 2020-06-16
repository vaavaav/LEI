#ifndef GRAPHS_H
#define GRAPHS_H


 typedef struct edge{
     int dest;
     struct edge* next;
 }Edge;

typedef struct graph{
    int max;
    struct edge **LAdj;
} *Graph;


void printG(Graph g);
void insertVertice(Graph g, int x);
void insertEdge(Graph g, int o, int d);
void deleteEdge(Graph g, int o, int d);
Graph InitializeGraph();
void clearGraph(Graph g);
int colorOK(Graph g, int *color);
int colorOK_Sol(Edge *LAdj[], int N, int *color);
int succN(Graph g, int o, int N);
int succN_Sol(Edge *LAdj[], int o, int N,int vis[]);
int isSplitGraph(Graph g);
int isSplitGraph_Sol(Edge *LAdj[], int V, int vis[], int queue[], int splitG[]);

//Heavy Graphs


typedef struct edgeH{
    int dest;
    int weight;
    struct edgeH *next;
}EdgeH;

typedef struct graphH{
    int max;
    struct edgeH **LAdj;
} *GraphH;

void printGH(GraphH g);
void insertVerticeH(GraphH g, int x);
void insertEdgeH(GraphH g, int o, int w, int d);
void deleteEdgeH(GraphH g, int o, int d);
GraphH InitializeGraphH();
void clearGraphH(GraphH g);
int dijkstra(struct edgeH *h[], int N, int o, int p[], int w[]);
void insertQ(int q[], int w[], int l, int x);
void updateQ(int q[], int w[], int x);

#endif 