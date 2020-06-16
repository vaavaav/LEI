#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"


void printG(Graph g){
    int i; 
    Edge *aux;
    printf("<ORIGIN: DESTINATION1 -> ... -> DESTINATIONN -> X (NULL)> \n\n");
    for(i = 0; i < g->max; i++){
        printf("%d: ",i);
        for(aux = g->LAdj[i]; aux; aux = aux -> next)
            printf("%d -> ",aux->dest);
        printf("X\n");
    }
}

void insertVertice(Graph g, int x){
    int i = g->max; 
    while(x >= g->max) g->max++; 
    g->LAdj = realloc(g->LAdj, sizeof(struct edge*)*g->max);
    for(; i < g->max; i++)
        g->LAdj[i] = NULL;  
}

void insertEdge(Graph g, int o, int d){
    Edge *aux, *ant = NULL;
    if(o >= g->max) insertVertice(g,o);
    if(d >= g->max) insertVertice(g,d);
    for(aux = g->LAdj[o]; aux != NULL; aux = aux -> next) 
        ant = aux;
    aux = malloc(sizeof(struct edge*));
    aux -> dest = d;
    aux -> next = NULL;
    if(ant != NULL) 
        ant -> next = aux;
    else
        g->LAdj[o] = aux;
}

void deleteEdge(Graph g, int o, int d){
    Edge **aux, **ant; 
    *ant = NULL;
    aux = &(g->LAdj[o]);
    while((*aux) != NULL && (*aux)->dest != d){
        ant = aux;
        aux = &((*aux) -> next);
    }
    if((*aux) != NULL){
        if((*ant) != NULL){ 
            (*ant) -> next = (*aux) -> next;
            free(*aux);
        }
        else{
            g->LAdj[o] = (*aux)->next;
            free(*aux);
        }
    }
}


Graph InitializeGraph(){
    Graph g; int i;
    g = malloc(sizeof(struct graph));
    g->max = 2;
    g->LAdj = malloc(sizeof(struct edge*)*g->max);
    for(i = 0; i < g-> max; i++)
        g->LAdj[i] = NULL;
    return g;
}

void clearGraph(Graph g){
    Edge *aux, *ant = NULL;
    int i;
    for(i = 0; i < g->max; i++){
        aux = g->LAdj[i];
        while(aux != NULL){
            ant = aux->next;
            free(aux);
            aux = ant;
        }
    }
    free(g->LAdj);
    free(g);
}

int colorOK(Graph g, int color[]){
    return colorOK_Sol(g->LAdj, g->max, color);
}

int colorOK_Sol(Edge *LAdj[], int V, int color[]){
    int i, r = 1; Edge * aux;
    for(i = 0; i < V && r; i++){
        aux = LAdj[i];
        while(aux != NULL && r){
            if(color[aux->dest] == color[i])
                r = 0;
            aux = aux->next;
        }
    }
    return r;
}

int succN(Graph g, int o, int N){
    int *vis, i;
    vis = malloc(sizeof(int)*g->max);
    for(i = 0; i < g->max; i++) vis[i] = 0;
    return succN_Sol(g->LAdj,o,N,vis);
}

int succN_Sol(Edge *LAdj[], int o, int N,int vis[]){
    int r = 0; Edge *aux = LAdj[o];
    vis[o] = 1;
    if(N > 0){
        r++;
        while(aux!= NULL){
            if(vis[aux -> dest] == 0)
                r += succN_Sol(LAdj,aux->dest,N-1,vis);
            aux = aux->next;
        }
    }
    return r;
}

int isSplitGraph(Graph g){
    int *vis, *queue, *splitG, i;
    vis = malloc(sizeof(int)*g->max);
    queue = malloc(sizeof(int)*g->max);
    splitG = malloc(sizeof(int)*g->max);
    for(i = 0; i < g->max; i++){ 
        vis[i] = 0;
        splitG[i] = -1;
    }
    return isSplitGraph_Sol(g->LAdj, g->max, vis, queue, splitG);
}

int isSplitGraph_Sol(Edge *LAdj[], int V, int vis[], int queue[], int splitG[]){
    int r = 1, i, now = 0, last = 0, flag = 0;
    Edge *aux;
    for(i = 0; i < V && r; i++)
        if(vis[i] == 0){
        splitG[i] = 0;
        queue[last++] = i;
        while(last != now && r){
            for(aux = LAdj[queue[now]]; aux != NULL && r; aux = aux ->next){
                flag = splitG[queue[now]];
                if(vis[aux -> dest] == 0){
                    queue[last++] = aux->dest;
                    splitG[aux->dest] = 1 - flag;
                    vis[aux -> dest] = 1;
                }
                else 
                    if(splitG[aux->dest] == flag)
                        r = 0;
            }
            vis[queue[now]] = 2;
            now++;
        }
    }
    return r;
}


//Heavy Graphs
//
//
void printGH(GraphH g){
    int i; 
    EdgeH *aux;
    printf("<ORIGIN: COST1|DESTINATION1 -> ... -> COSTN|DESTINATIONN -> X (NULL)> \n\n");
    for(i = 0; i < g->max; i++){
        printf("%d: ",i);
        for(aux = g->LAdj[i]; aux; aux = aux -> next)
            printf("%d|%d -> ", aux->weight, aux->dest);
        printf("X\n");
    }
}

void insertVerticeH(GraphH g, int x){
    int i = g->max; 
    while(x >= g->max) g->max++; 
    g->LAdj = realloc(g->LAdj, sizeof(struct edgeH*)*g->max);
    for(; i < g->max; i++)
        g->LAdj[i] = NULL;  
}

void insertEdgeH(GraphH g, int o, int d, int w){
    EdgeH *aux, *ant = NULL;
    if(o >= g->max) insertVerticeH(g,o);
    if(d >= g->max) insertVerticeH(g,d);
    for(aux = g->LAdj[o]; aux != NULL; aux = aux -> next) 
        ant = aux;
    aux = malloc(sizeof(struct edgeH*));
    aux -> dest = d;
    aux -> weight = w;
    aux -> next = NULL;
    if(ant != NULL) 
        ant -> next = aux;
    else
        g->LAdj[o] = aux;
}

void deleteEdgeH(GraphH g, int o, int d){
    EdgeH **aux, **ant; 
    *ant = NULL;
    aux = &(g->LAdj[o]);
    while((*aux) != NULL && (*aux)->dest != d){
        ant = aux;
        aux = &((*aux) -> next);
    }
    if((*aux) != NULL){
        if((*ant) != NULL){ 
            (*ant) -> next = (*aux) -> next;
            free(*aux);
        }
        else{
            g->LAdj[o] = (*aux)->next;
            free(*aux);
        }
    }
}

GraphH InitializeGraphH(){
    GraphH g; int i;
    g = malloc(sizeof(struct graphH));
    g->max = 2;
    g->LAdj = malloc(sizeof(struct edgeH*)*g->max);
    for(i = 0; i < g-> max; i++)
        g->LAdj[i] = NULL;
    return g;
}

void clearGraphH(GraphH g){
    EdgeH *aux, *ant = NULL;
    int i;
    for(i = 0; i < g->max; i++){
        aux = g->LAdj[i];
        while(aux != NULL){
            ant = aux->next;
            free(aux);
            aux = ant;
        }
    }
    free(g->LAdj);
    free(g);
}

int dijkstra(struct edgeH *h[], int N, int o, int p[], int w[]){
    int queue[N], vis[N], last = 0, now = 0, i; struct edgeH * aux; 
    for(i = 0; i < N; i++){ vis[i] = 0; p[i] = -1;}
    w[o] = 0; queue[last++] = o; vis[o] = 1; p[o] = o;
    while(now != last){
        for(o = queue[now], aux = h[o] ; aux != NULL; aux = aux ->next){
            if(vis[aux->dest] == 0){
                vis[aux->dest] = 1; p[aux->dest] = o;
                w[aux->dest] = w[o] + aux->weight;
                insertQ(queue + now, w, (last++) - now, aux->dest);
            }
            else if(vis[aux -> dest] == 1)
                if(w[aux->dest] > aux -> weight + w[o]){
                    w[aux -> dest] = aux -> weight +  w[o];
                    updateQ(queue + now, w, aux->dest);
                    p[aux->dest] = o;
                }
        }
        vis[queue[now++]] = 2;
    }

    return queue[now - 1];  
}

void insertQ(int q[], int w[], int l, int x){
    for(; l > 1 && w[x] < w[l - 1]; l--)q[l] = q[l - 1];
    q[l] = x;
}

void updateQ(int q[], int w[], int x){
    int i;
    for(i = 1; q[i] != x; i++);
    for(; i > 1 && w[x] < w[i - 1]; i--)q[i] = q[i - 1];
    q[i] = x;
}