//
//  MinimumSpanningTree.c
//  D_week4
//
//  Created by runny on 2020/7/1.
//  Copyright © 2020 runny. All rights reserved.
//  从一个给定的图中构建一棵最小生成树

#include "MinimumSpanningTree.h"
#include "stdlib.h"
#include "MatrixGraph.h"
#include "LinkGraph.h"
#define ERROR -1
Vertex FindMinDistVFromMST(MGraph Graph,WeightType dist[]){
    Vertex MinV=0,V;
    int MinDist = INFINITY;
    for (V=0; V<Graph->Nv; V++) {
        if(dist[V]!=0&&dist[V]<MinDist){//未被收录(dist[V]=0说明顶点已在最小生成树上)切距离最小生成树MST最近的顶点
            MinDist=dist[V];
            MinV=V;
        }
    }
    if(MinDist<INFINITY){
        return MinV;
    }else{
        return ERROR;
    }
}

//Prim算法从一个顶点出发让一个小树长大
int Prim(MGraph Graph,LGraph MST){
    //将最小生成树保存为邻接表存储的图 返回最小权重和
    int dist[MAX_VERTEX_NUM],TotalWeight;
    Vertex Parent[MAX_VERTEX_NUM],V,W;
    int VCount;//收录的顶点数
    LEdge E;//顶点收录进MST时使用
    
    //初始化 默认源顶点的下标为0
    for (V=0; V<Graph->Nv; V++) {
        //这里假设邻接矩阵构成的图不相邻的顶点G[V][W]记录为INFINITY
        dist[V]=Graph->G[0][V];
        Parent[V]=0;
    }
    VCount=0;
    TotalWeight=0;
    
    MST = CreateLGraph(Graph->Nv);//初始化MST
    //将源顶点0收录
    dist[0]=0;
    VCount++;
    Parent[0]=-1;
    
    while (1) {
        //找到距离最小生成树最近的顶点V
        V = FindMinDistVFromMST(Graph, dist);
        if(V==ERROR){
           break;
        }
        E = (PtrToLENode)malloc(sizeof(struct LENode));
        E->V1=Parent[V];
        E->V2=V;
        E->Weight=dist[V];
        VCount++;
        TotalWeight+=dist[V];
        dist[V]=0;
        InsertEdge(MST, E);
        for (W=0; W<Graph->Nv; W++) {
            //如果W未被收录到最小生成树中且为V的邻接顶点
            if(dist[W]!=0&&Graph->G[V][W]<INFINITY){
                if(Graph->G[V][W]<dist[W]){
                    dist[W]=Graph->G[V][W];
                    Parent[W]=V;
                }
                
            }
        }
    }
    
    if(VCount<Graph->Nv){//MST最小生成树的顶点不到Nv个 说明图不连通
        return ERROR;
    }
    return TotalWeight;
    
}
