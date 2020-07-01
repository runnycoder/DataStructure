//
//  MatrixGraph.c
//  D_week4
//
//  Created by runny on 2020/6/28.
//  Copyright © 2020 runny. All rights reserved.
//

#include "MatrixGraph.h"
#include "stdlib.h"
#include "ArrayQueue.h"


//邻接矩阵图初始化
MGraph CreateGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph;
    Graph = (PtrToGNode)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for (V=0; V<Graph->Nv; V++) {
        for (W=0; W<Graph->Nv; W++) {
            if(V==W){
                 Graph->G[V][W]=INFINITY;//初始化矩阵的对角线为一个极大的数值
            }else{
                 Graph->G[V][W]=0;
            }
           
        }
    }
    return Graph;
}
//在图中顶点插入边
void MInsertEdge(MGraph Graph,Edge E){
//    printf("%d %d %d",E->V1,E->V2,E->Weight);
    Graph->G[E->V1][E->V2]=E->Weight;
    //无向图还需要构造V2->V1的连接
    Graph->G[E->V2][E->V1]=E->Weight;
    Graph->Ne++;
    
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
            MInsertEdge(Graph, E);
        }
    }
    //如果顶点有数据的话初始化顶点 Data
    return Graph;
}
//邻接矩阵表示图的遍历(DFS)  VertexArray记录下标对应的顶点是否被访问过
void DFSTraversalOfMGragh(MGraph Graph,Vertex V,Vertex* VertexArray){
//    Vertex* VertexArray = (Vertex*)malloc(sizeof(Vertex)*Graph->Nv);
    printf("当前顶点%d已被访问!\n",V);
    VertexArray[V]=1;//标记当前顶点已经被访问过
    for (int V2 = 0; V2<Graph->Nv; V2++) {
        if(Graph->G[V][V2]>0&&VertexArray[V2]==0){
            DFSTraversalOfMGragh(Graph,V2,VertexArray);
        }
    }
}

//邻接矩阵表示图的遍历(BFS) 需要用到队列 VertexArray记录下标对应的顶点是否被访问过
void BFSTraversalOfMGragh(MGraph Graph,Vertex V,Vertex* VertexArray){
    AQueue Q = createQueue(Graph->Nv);//队列前面已经有定义此处不再实现
    printf("当前顶点%d已被访问!\n",V);
    VertexArray[V]=1;//标记当前顶点已经被访问过
    addQueue(Q,V);
    while(!isEmpty(Q)){
         V = deleteQueue(Q);
        for (int W=0; W<Graph->Nv; W++) {
            if(VertexArray[W]==0&&Graph->G[V][W]==1){//如果结点未被访问且为V的邻接顶点
                printf("当前顶点%d已被访问!\n",W);
                VertexArray[W]=1;
                addQueue(Q, W);
            }
        }
            
    }
}
