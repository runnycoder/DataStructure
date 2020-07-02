//
//  TopologicalSorting.c
//  D_week4
//
//  Created by runny on 2020/7/2.
//  Copyright © 2020 runny. All rights reserved.
//  拓扑序 如果从图中V到W有一条路径 则V一定排在W前。满足此条件的顶点序列称为一个拓扑序
//  获得拓扑序的过程就是拓扑排序
//  AOV(Active ON Vertex)如果有合理的拓扑序 则必定是有向无环图(Directed Acyclic Graph DAG)

#include "TopologicalSorting.h"
#include "LinkGraph.h"
#include "ArrayQueue.h"
/**     邻接表存储-拓扑排序算法
    核心思想 从图中找出没有前驱的顶点说明是需要输出的
    输出该顶点 并将该顶点的邻接顶点入度减去1
 */
int TopSort(LGraph Graph,Vertex TopOrder[]){
    //对Graph进行拓扑排序 TopOrder中存储已经排好序的顶点的下标
    int Indegree[MaxVertexNum],cnt;
    Vertex V;
    PtrToAdjVNode W;
    AQueue Q = createQueue(Graph->Nv);
    
    //初始化各个顶点的Indegree
    for (V=0; V<Graph->Nv; V++) {
        Indegree[V]=0;
    }
    
    //遍历图得到Indegree
    for (V=0; V<Graph->Nv; V++) {
        for (W=Graph->G[V].FirstEdge; W; W=W->Next) {//V的邻接顶点W出现一次 W的入度++
            Indegree[W->AdjV]++;
        }
    }
    //将入度为0的顶点入队
    for (V=0; V<Graph->Nv; V++) {
        if(Indegree[V]==0){
            addQueue(Q, V);
        }
    }
    //开始拓扑排序
    cnt=0;
    while (!isEmpty(Q)) {
        V=	deleteQueue(Q);
        TopOrder[cnt++]=V;//将V存入排序数组中 然后cnt+1
        for (V=0; V<Graph->Nv; V++) {
            for (W=Graph->G[V].FirstEdge; W; W=W->Next) {
                if(--Indegree[W->AdjV]==0){//如果w的入度减去1之后等于0 则将W入队
                    addQueue(Q, W->AdjV);
                };
            }
        }
    }
    if(cnt<Graph->Nv){//如果入队的顶点少于图中的顶点 说明图中一定存在回路 造成顶点入度不能为0
        return -1;
    }
    return cnt;
}
