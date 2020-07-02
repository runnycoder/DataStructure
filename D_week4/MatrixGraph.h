//
//  MatrixGraph.h
//  D_week4
//
//  Created by runny on 2020/6/28.
//  Copyright © 2020 runny. All rights reserved.
//  邻接矩阵构造图

#ifndef MatrixGraph_h
#define MatrixGraph_h

#include <stdio.h>
#define MAX_VERTEX_NUM 100
#define INFINITY 1000


//typedef int WeightType;//图中存储类型
typedef int DataType;//顶点存储数据信息类型
typedef int Vertex;//用顶点下标表示顶点

typedef struct WeightNode* MWeightType;
struct WeightNode{
    int Length;
    int Cost;
};
typedef struct GNode *PtrToGNode;
struct GNode{//
    int Nv;//顶点数
    int Ne;//边数
    MWeightType G[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵存储顶点关联信息
    DataType Data[MAX_VERTEX_NUM];//一位数组存储顶点信息
};
typedef PtrToGNode MGraph;//以邻接矩阵存储的图类型

typedef struct ENode* PtrToENode ;
struct ENode{//边结点构造
    Vertex V1,V2;
    MWeightType Weight;
};
typedef PtrToENode Edge;
MGraph CreateGraph(int VertexNum);
void MInsertEdge(MGraph Graph,Edge E);
#endif /* MatrixGraph_h */
