//
//  TravelPlan.c
//  D_week4
//
//  Created by runny on 2020/7/2.
//  Copyright © 2020 runny. All rights reserved.
//  旅游规划问题 顶点代表城市 边上的权重分为距离L和费用M 求从V1出发
//  到其他城市距离最短且费用最少的路径(如果有多条最短路径 选择费用最低的)

#include "TravelPlan.h"
#include "MatrixGraph.h"

Vertex FindMinDistV(MGraph Graph,int dist[],int collected[]){
    Vertex V,MinV;
    int Mindist = INFINITY;
    for (V=0; V<Graph->Nv; V++) {
        if(collected[V]==-1&&dist[V]<Mindist){
            Mindist=dist[V];
            MinV=V;
        }
    }
    if(Mindist<INFINITY){
        return MinV;
    }else{
        return -1;
    }
 
}

/// 旅游规划
/// @param Graph 城市为顶点 边的权重 为距离和费用 初始化不相邻的结点 length cost为INFINITY
/// @param dist dist[v]记录当前顶点到源顶点S的最短距离
/// @param cost cost[v]记录当前顶点到源顶点S的最少费用
/// @param path path[v]记录当前顶点到源顶点S的最短路径的前一个顶点

void TravelPlan(MGraph Graph,Vertex S,int dist[],int cost[],int path[]){
    Vertex V,W;
    int collected[MAX_VERTEX_NUM];
    //初始化collected
    for (V=0; V<Graph->Nv; V++) {
        collected[V]=-1;
    }
    //初始化dist cost
    for (V=0; V<Graph->Nv; V++) {
        if(Graph->G[S][V]->Length>0&&Graph->G[S][V]->Cost>0){//距离和费用不能存在负的路径
            dist[V]=Graph->G[S][V]->Length;
            cost[V]=Graph->G[S][V]->Cost;
        }else{
            printf("图中存在负的路径!");
            return ;
        }
    }
    //收录源顶点S
    collected[S]=0;
    path[S]=-1;
    while (-1) {
        V = FindMinDistV(Graph,dist,collected);
        collected[V]=0;
        for (W=0; W<Graph->Nv; W++) {
            if (collected[W]==-1&&Graph->G[V][W]->Length<INFINITY) {//如果W顶点未被收录且为V的邻接顶点
                if(dist[V]+Graph->G[V][W]->Length<dist[W]){//如果加入顶点V使得 W的最短路径变短则更新
                    dist[W]=dist[V]+Graph->G[V][V]->Length;
                    path[W]=V;
                    //同时更新w的最低费用
                    cost[W]=cost[V]+Graph->G[V][W]->Cost;
                }else if(dist[V]+Graph->G[V][W]->Length==dist[W]&&
                         cost[V]+Graph->G[V][W]->Cost<cost[W]){//如果相等 就要判断是否能让cost[W]变低 如果可以则更新
                    cost[W]=cost[V]+Graph->G[V][W]->Cost;
                    path[W]=V;
                }
            }
        }
    }
    
}
