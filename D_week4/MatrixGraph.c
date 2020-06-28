//
//  MatrixGraph.c
//  D_week4
//
//  Created by runny on 2020/6/28.
//  Copyright © 2020 runny. All rights reserved.
//

#include "MatrixGraph.h"
#include "stdlib.h"
//邻接矩阵图初始化
MGraph CreateGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph;
    Graph = (PtrToGNode)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for (V=0; V<Graph->Nv; V++) {
        for (W=0; W<Graph->Nv; W++) {
            Graph->G[V][W]=0;
        }
    }
    return Graph;
}
//在图中顶点插入边
void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->V1][E->V2]=E->Weight;
    //无向图还需要构造V2->V1的连接
    Graph->G[E->V2][E->V1]=E->Weight;
}

//完整的图构建
MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    
    int Nv;
    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);
    scanf("%d",&Graph->Ne);
    if(Graph->Ne!=0){
        E = (PtrToENode)malloc(sizeof(struct ENode));
        for (int i = 0; i<Graph->Ne; i++) {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph, E);
        }
    }
    //如果顶点有数据的话初始化顶点 Data
    return Graph;
}
