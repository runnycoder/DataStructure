//
//  GrapShortestPath.c
//  D_week4
//
//  Created by runny on 2020/6/30.
//  Copyright © 2020 runny. All rights reserved.
//  图最短路径计算

#include "GrapShortestPath.h"
#include "LinkGraph.h"
#include "MatrixGraph.h"
#include "ArrayQueue.h"
#define INFINITY 10000
#define ERROR -1



/// 单源无权最短路径计算 根据BFS算法演变而来
/// @param Graph  邻接表构造的图
/// @param dist 数组记录对应下标顶点距离源顶点(S)的最短路径 初始化元素均为-1
/// @param path 数组记录对应下标顶点最短路径上前一个顶点W的值 S->....->W->D 初始化元素均为-1
/// @param S 源顶点
void Unweighted(LGraph Graph,int dist[],int path[],Vertex S){
    Vertex V;
    PtrToAdjVNode W;
    AQueue Q = createQueue(Graph->Nv);
    dist[S]=0;
    addQueue(Q, S);
    while (!isEmpty(Q)) {
        V = deleteQueue(Q);
        for (W=Graph->G[S].FirstEdge; W; W=W->Next) {//遍历S的邻接顶点
            if(dist[W->AdjV]==-1){//如果邻接顶点未被访问过
                dist[W->AdjV]=dist[V]+1; //更新顶点W->V的距离
                path[W->AdjV]=V;//将V记录在S->W的路径上
                addQueue(Q, W->AdjV);
            }
        }
    }
}

//返回未被收录结点dist的最小值
Vertex FindMinDist(MGraph Graph,int dist[],int collected[]){
    Vertex MinV,V;
    int MinDist = INFINITY;//初始化为一个极大的整数
    for (V=0; V<Graph->Nv; V++) {
        if(collected[V]==-1&&dist[V]<MinDist){
            MinDist=dist[V];
            MinV=V;
        }
    }
    if(MinDist<INFINITY){//如果有这样的最小值
        return MinV;
    }else{
        return ERROR;
    }
}


/// 单源有权最短路径计算
/// @param Graph 邻接矩阵构造的图
/// @param dist 记录下标对应顶点距离源顶点S的最短路径长度
/// @param path 记录下标对应顶点距离源顶点S最短路径上的前一个顶点编号
/// @param S 源顶点
int Dijkstra(MGraph Graph,int dist[],int path[],Vertex S){
    int collected[MAX_VERTEX_NUM];//记录订单是否被收录 贪心算法 每次只找下一个距离自己最近的结点
    Vertex V,W;
     /* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
    for (V=0; V<Graph->Nv; V++) {
        dist[V]=Graph->G[S][V];
        if(dist[V]<INFINITY){//一个不可能为正常顶点的极大数值
            path[V]=S;
        }else{
            path[V]=-1;
        }
        collected[V]=-1;//标记当前结点未收录
    }
    
    //收录源顶点S到集合中
    collected[S]=1;
    //源顶点的距离设置为0
    dist[S]=0;
    
    for (V=0; V<Graph->Nv; V++) {
        if(Graph->G[S][V]!=INFINITY){//初始化源顶点的邻接顶点
            dist[V]=dist[S]+Graph->G[S][V];
            path[V]=S;
        }
    }
    
    while(1){
        //返回未被收录到集合中且dist[V]为最小值顶点V
        V = FindMinDist(Graph, dist, collected);
        if(V==ERROR){
            break;
        }
        for (W=0; W<Graph->Nv; W++) {//对于图中的每个顶点W
            //如果W未被收录到集合中且为V的邻接顶点
            if(collected[V]==-1&&Graph->G[V][W]<INFINITY){
                if(Graph->G[V][W]<0){//V->W之间存在负的边 不能正确处理返回错误
                    return ERROR;
                }
                
                //如果收录V能使得dist[W]变小 则更新dist[W]的值
                if(dist[V]+Graph->G[V][W]<dist[W]){
                    dist[W]=dist[V]+Graph->G[V][W];
                    path[W]=V;
                }
            }
        }
    }
    return 1;
}
