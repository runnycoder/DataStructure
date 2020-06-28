//
//  LinkGraph.c
//  D_week4
//
//  Created by runny on 2020/6/28.
//  Copyright © 2020 runny. All rights reserved.
//

#include "LinkGraph.h"
#include "stdlib.h"
LGraph CreateLGraph(int VertexNum){
    LGraph Graph;
    Vertex V;
    
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    
    for (V=0; V<Graph->Nv; V++) {
        Graph->G[V].FirstEdge=NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVNode NewAdjNode;
    
    NewAdjNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewAdjNode->Weight=E->Weight;
    NewAdjNode->AdjV=E->V2;
    NewAdjNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewAdjNode;
    
    //如果是无限图还要插入<V2,V1>
    NewAdjNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewAdjNode->Weight=E->Weight;
    NewAdjNode->AdjV=E->V1;
    NewAdjNode->Next=Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge=NewAdjNode;
}
