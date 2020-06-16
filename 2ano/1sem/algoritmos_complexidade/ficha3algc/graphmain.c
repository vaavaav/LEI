#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

int graphs(){
    int GT, controlo, o, d, i, w, *weights, *pais;
    int *color = NULL;
    Graph g; GraphH h;
    printf("-Graphs-\n\n");
    do{
        printf("Graphs:\n(1) - Standard \n(2) - Heavy(NOT AVAILABLE)\n(0) - Return\n");
        printf("\n>type:");
        scanf("%d",&GT);
        if(GT == 1){ 
            g = InitializeGraph();                         
            printf("Commands:\n(1) - Print Graph on Screen\n(2) - Insert Edge In Graph\n(3) - Delete Edge from Graph\n(4) - Valid Coloration\n(5) - Number of Vertices at a maximum distance\n(6) - Checks if graph is split\n(0) - Clear Graph and Return\n");
            do{ 
                printf("\n>command:");
                scanf("%d",&controlo);  
                printf("\n");
                switch(controlo){
                    case 1:
                        printG(g);
                        break;
                    case 2:
                        printf("Insert Origin as Destination to stop!\n");
                        printf("Origin:");
                        scanf("%d",&o);
                        do{
                            printf("Destination:");
                            scanf("%d",&d);
                            if (o != d) insertEdge(g,o,d);
                        }while(o != d);
                        break;
                    case 3:
                        printf("Origin:");
                        scanf("%d",&o);
                        printf("Destination:");
                        scanf("%d",&d);
                        deleteEdge(g,o,d);
                        break;
                    case 4: 
                        printf("\nColor Vertices: 0 - Red; 1 - Orange; 2 - Yellow; 3 - Green; 4 - Cyan; 5 - Blue; 6 - Purple\n\n");
                        color = malloc(sizeof(int)*g->max);
                        for(i = 0; i < g->max; i++){
                            printf("Color of %d:", i);
                            scanf("%d",color + i);
                        }
                        printf("This coloration is %s!", colorOK(g,color) ? "VALID" : "INVALID");
                        free(color);
                        break;
                    case 5:
                        printf("Origin:");
                        scanf("%d",&o);
                        printf("Maximum distance:");
                        scanf("%d",&d);
                        printf("There are %d at %d of distance from %d\n", succN(g,o,d), d, o);
                        break;
                    case 6:
                        printf("The Graph %s split!\n", isSplitGraph(g) ? "is" : "is NOT");
                        break;
                    case 0:
                        clearGraph(g);
                        break;
                    default:
                        break;
                }
            }while(controlo);
        }
        else if(GT == 2){  
            h = InitializeGraphH();             
             printf("Commands:\n(1) - Print Graph on Screen\n(2) - Insert Edge In Graph\n(3) - Delete Edge from Graph\n(4) - Shortest Path(Not negative weights)\n(0) - Clear Graph and Return\n");
            do{ 
                printf("\n>command:");
                scanf("%d",&controlo);
                printf("\n");
                switch(controlo){
                    case 1:
                        printGH(h);
                        break;
                    case 2:
                        printf("Insert Origin as Destination to stop!\n");
                        printf("Origin:");
                        scanf("%d",&o);
                        do{
                            printf("Destination:");
                            scanf("%d",&d);
                            if (o != d){
                                printf("Cost:");
                                scanf("%d",&w); 
                                insertEdgeH(h,o,d,w);
                            }
                        }while(o != d);
                        break;
                    case 3:
                        printf("Origin:");
                        scanf("%d",&o);
                        printf("Destination:");
                        scanf("%d",&d);
                        deleteEdgeH(h,o,d);
                        break;
                    case 4:
                        weights = malloc(sizeof(int)*h->max);
                        pais = malloc(sizeof(int)*h->max);
                        printf("Origin:");
                        scanf("%d",&o);
                        printf("Shortest path costs: %d\n", dijkstra(h->LAdj, h->max, o, pais, weights));
                        printf("Shortest path: ");
                        for(i = h ->max - 1; pais[i] != -1; i--);
                        for(; pais[i] != i; i = pais[i])
                            printf("%d <- ", i);
                        if(pais[i] == i)
                            printf("%d",i);
                        printf("\n");
                        free(weights); free(pais);
                        break;
                    case 0:
                        clearGraphH(h);
                        break;
                    default:
                        break;
                }
            }while(controlo);
        }
    }while(GT);
    return 0;
}
