//
//  LinkGraph.h
//  D_week4
//
//  Created by runny on 2020/6/28.
//  Copyright © 2020 runny. All rights reserved.
//  邻接表表示法

#ifndef LinkGraph_h
#define LinkGraph_h
#define MaxVertexNum 100
#include <stdio.h>
typedef int Vertex;
typedef int WeightType;
typedef int DataType;
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode{//链表邻接结点定义
    Vertex AdjV;//邻接点的下标
    WeightType Weight;//权重
    PtrToAdjVNode Next;
};
typedef struct Vnode{//头节点定义
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];

typedef struct LGNode* PtrToLGNode;
struct LGNode{//图结点定义
    int Nv;//顶点数
    int Ne;//边数
    AdjList G;
};
typedef PtrToLGNode LGraph;

typedef struct LENode* PtrToLENode ;
struct LENode{//边结点构造
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToLENode LEdge;

LGraph CreateLGraph(int VertexNum);
void InsertEdge(LGraph Graph,LEdge E);
#endif /* LinkGraph_h */
