//
//  LinkGraph.c
//  D_week4
//
//  Created by runny on 2020/6/28.
//  Copyright © 2020 runny. All rights reserved.
//

#include "LinkGraph.h"
#include "stdlib.h"
#include "ArrayQueue.h"
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
//VertexArray记录下标对应的顶点是否被访问过
void DFSTraversalOfGraph(LGraph Graph,Vertex V,Vertex* VertexArray){
    PtrToAdjVNode W;
    printf("当前顶点%d已被访问!\n",V);
    VertexArray[V]=1;
    for (W=Graph->G[V].FirstEdge; W; W=W->Next) {
        if(VertexArray[W->AdjV]==0){//如果V的邻接结点W未被访问过
            DFSTraversalOfGraph(Graph, W->AdjV, VertexArray);
        }
    }
}
//VertexArray记录下标对应的顶点是否被访问过
void BFSTraversalOfGragh(LGraph Graph,Vertex V,Vertex* VertexArray){
    PtrToAdjVNode W;
    AQueue Q = createQueue(Graph->Nv);//队列前面已经有定义此处不再实现
    printf("当前顶点%d已被访问!\n",V);
    VertexArray[V]=1;//标记当前顶点已经被访问过
    addQueue(Q,V);
    while(!isEmpty(Q)){
         V = deleteQueue(Q);
        for (W=Graph->G[V].FirstEdge; W; W=W->Next) {
            if(VertexArray[W->AdjV]==0){//如果V的邻接结点W未被访问过
                printf("当前顶点%d已被访问!\n",W->AdjV);
                   VertexArray[W->AdjV]=1;//标记当前顶点已经被访问过
                   addQueue(Q,W->AdjV);
            }
        }
    }
}
