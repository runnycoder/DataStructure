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
#include "stdlib.h"
#define INFINITY 10000
#define ERROR -1
#define OK 1


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
/// @param dist 记录下标对应顶点距离源顶点S的最短路径长度 初始化为INFINITY
/// @param path 记录下标对应顶点距离源顶点S最短路径上的前一个顶点编号 初始化为-1
/// @param S 源顶点
int Dijkstra(MGraph Graph,int dist[],int path[],Vertex S){
    int collected[MAX_VERTEX_NUM];//记录订单是否被收录 贪心算法 每次只找下一个距离自己最近的结点
    Vertex V,W;
     /* 初始化：S的邻接顶点,此处默认邻接矩阵中不存在的边用INFINITY表示 */
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
    
    
    
    while(1){
        //返回未被收录到集合中且dist[V]为最小值顶点V
        V = FindMinDist(Graph, dist, collected);
        if(V==ERROR){
            break;
        }
        //收录最小值V到集合中
        collected[V]=1;
        for (W=0; W<Graph->Nv; W++) {//对于图中的每个顶点W
            //如果W未被收录到集合中且为V的邻接顶点
            if(collected[W]==-1&&Graph->G[V][W]<INFINITY){
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
    return OK;
}

void printfMatix(WeightType G[][MAX_VERTEX_NUM],int N){
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
}

/// 邻接矩阵存储的图 多源最短路径计算
/// @param Graph 邻接矩阵构建的图 i->j顶点之间不存在路径应记为+∞
/// @param dist  矩阵dist[i][j]记录从i->j的最短路径
/// @param path  矩阵path[i][j]记录从i->j最短路径中前一个顶点k

int Floyd(MGraph Graph,WeightType dist[][MAX_VERTEX_NUM],Vertex path[][MAX_VERTEX_NUM]){
    Vertex i,j,k;
    
    //初始化
    for (i=0; i<Graph->Nv; i++) {
        for (j=0; j<Graph->Nv; j++) {
            dist[i][j]=Graph->G[i][j];
            path[i][j]=-1;
        }
    }
    printfMatix(dist,Graph->Nv);
    
    //相当于在每次i->j中插入顶点k 看是否会让i-j的路径缩短 如果能缩短则更新dist[i][j] 记录path[i][j]=k
    for (k=0; k<Graph->Nv; k++) {
        for (i=0; i<Graph->Nv; i++) {
            for (j=0; j<Graph->Nv; j++) {
                if(i==j){
                    continue;
                }
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    if(i==j&&dist[i][j]<0){//发现i->j的负圈 不能正确解决 返回错误标记
                        return ERROR;
                    }
                    path[i][j]=k;
                }
            }
        }
    }
    return OK;
}

/**
 现在哈利·波特的手里有一本教材，里面列出了所有的变形魔咒和能变的动物。老师允许他自己带一只动物去考场，要考察他把这只动物变成任意一只指定动物的本事。于是他来问你：带什么动物去可以让最难变的那种动物（即该动物变为哈利·波特自己带去的动物所需要的魔咒最长）需要的魔咒最短？例如：如果只有猫、鼠、鱼，则显然哈利·波特应该带鼠去，因为鼠变成另外两种动物都只需要念4个字符；而如果带猫去，则至少需要念6个字符才能把猫变成鱼；同理，带鱼去也不是最好的选择。

 输入格式:
 输入说明：输入第1行给出两个正整数N (≤100)和M，其中N是考试涉及的动物总数（顶点数），M是用于直接变形的魔咒条数（边）。为简单起见，我们将动物按1~N编号。随后M行，每行给出了3个正整数，分别是两种动物（V1,V2）的编号、以及它们之间变形需要的魔咒的长度(权重)(≤100)，数字之间用空格分隔。

 输出格式:
 输出哈利·波特应该带去考场的动物的编号、以及最长的变形魔咒的长度，中间以空格分隔。如果只带1只动物是不可能完成所有变形要求的，则输出0。如果有若干只动物都可以备选，则输出编号最小的那只。
 ——————
 输入
 6 11
 3 4 70
 1 2 1
 5 4 50
 2 6 50
 5 6 60
 1 3 70
 4 6 60
 3 6 80
 5 1 100
 2 4 60
 5 2 80
 */



//根据输入数值构造邻接矩阵类型的图
MGraph BuildMatrixGraphOrderByInput(){
    int N,E;
    Vertex V1,V2;
    WeightType W;
    printf("请输入顶点的个数N,和边的数目E!");
    scanf("%d %d",&N,&E);
    MGraph Graph =  CreateGraph(N);
    for (int i = 0 ; i<E; i++) {
        printf("请输入邻接的顶点V1,V2和边的权重Weight!");
        scanf("%d %d %d",&V1,&V2,&W);
        //由于输入顶点编号从1开始所以输入V1--,V2--
        V1--;V2--;
        PtrToENode E = (PtrToENode)malloc(sizeof(struct ENode));
        E->V1=V1;
        E->V2=V2;
        E->Weight=W;
        MInsertEdge(Graph, E);
    }
    
    printfMatix(Graph->G,Graph->Nv);
    
    return Graph;
}

//寻找源顶点为V到其他顶点最短路径中 最大的一条MaxDist
WeightType FindMaxDist(WeightType Dist[][MAX_VERTEX_NUM],Vertex V,int N){
    WeightType MaxDist = 0;
    for (int i=0; i<N; i++) {
        if(V!=i&&Dist[V][i]>MaxDist){
            MaxDist=Dist[V][i];
        }
    }
    return MaxDist;
}


//寻找图中到其他顶点路径最优的顶点
void FindTheBestVertexToOtherVertices(MGraph Graph){
    WeightType Dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM],Path[MAX_VERTEX_NUM][MAX_VERTEX_NUM],MaxDist,MinDist;
    
    Vertex Animal;
    Floyd(Graph, Dist, Path);
    printfMatix(Dist,Graph->Nv);
    MinDist = INFINITY;
    for (int i=0; i<Graph->Nv; i++) {
        MaxDist = FindMaxDist(Dist,i,Graph->Nv);
        if(MaxDist==INFINITY){//说明顶点i与其他结点都不联通
            printf("图中存在孤立顶点，无法计算，已退出!\n");
            return;
        }
        if(MaxDist<MinDist){
            MinDist=MaxDist;
            Animal=i+1;//更新最优顶点 由于顶点下标是从0开始的 所以要+1
        }
    }
    printf("最优顶点V=%d,最优顶点V到其他顶点最优路径中最大的长度为BestMinDist=%d",Animal,MinDist);
}
