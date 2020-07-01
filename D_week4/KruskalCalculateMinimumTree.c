//
//  KruskalCalculateMinimumTree.c
//  D_week4
//
//  Created by runny on 2020/7/1.
//  Copyright © 2020 runny. All rights reserved.
//  Kruskal算法求最小生成树
/**
        算法核心思想
        将图中的每一个顶点都看作一棵独立的树 每次从图中
        1 寻找权重最小的边  (将图中的边构造成一个最小堆,每次取树根元素)
        2 顶点未被收录
        3 新加入的结点使得最小生成树不构成回路  (使用并查集 判断新的树和MST是否是同一棵树 如果不是则合并到MST中)
            
 */

#include "KruskalCalculateMinimumTree.h"
#include "stdlib.h"
#include "LinkGraph.h"

/** 并查集定义开始*/
typedef Vertex ElementType;
typedef Vertex SetName;//默认用数组下标表示集合名称
typedef ElementType SetArray[MaxVertexNum];//默认集合下标从0开始

//集合初始化
void InitializeVSet(SetArray S){
    for (int i = 0; i<MaxVertexNum; i++) {
        S[i]=-1;
    }
}

//集合的合并
void SetUnion(SetArray S,SetName Root1,SetName Root2){
    //默认Root1和Root2是不同的根结点 根结点记录的数值为 集合元素的个数的负值 -N
    //-N1>-N2 N1<N2
    if(S[Root1]>S[Root2]){//Root2集合元素多 将Root1合并到Root2中
        S[Root2]+=S[Root1];
        S[Root1]=Root2;
    }else{
        S[Root1]+=S[Root2];
        S[Root2]=Root1;
    }
}
//寻找根结点
Vertex FindRoot(Vertex V, SetArray S ){
    if(S[V]<0){
        return V;
    }else{
        return V=FindRoot(S[V], S);//寻找根结点的同时对元素到根结点的路径进行压缩
    }
}




/// 校验新的顶点归并到最小生成树MST中是否会构成回路
/// @param S S 存放顶点的集合
/// @param MSTRoot 最小生成树MST的根
/// @param V2 新加入最小生成树的根
int CheckIsCircle(SetArray S,SetName MSTRoot,SetName V2){
    
    Vertex Root1,Root2;
    Root1 = FindRoot(MSTRoot, S);
    Root2 = FindRoot(V2, S);
    //顶点集合初始化为-1 如果送进来的顶点Root=-1说明是第一次这条边
    if(Root1==Root2&&Root1!=-1){//说明顶点V2已经在最小生成树MST中了 如果再连接一条边就会构成回路
        return 0;
    }else{
        SetUnion(S, Root1, Root2);
        return 1;
    }
    
}

/** 并查集定义结束*/

/** 图中边的最小堆定义开始*/
/** 将存储边的数组 调整为最小堆
 WeightType EdgeArray[] 存储边的数组
 int P 当前要调整的最小堆根结点P
 int N 数组元素的个数
 
 */
void PercDown(LEdge EdgeArray,int P,int N){
    int Parent,Child;
    struct LENode X;
    X = EdgeArray[P];//取出根结点
    //由于数组下标从0开始 所以根结点下标为P则左孩子的下标为 2*P+1
    for (Parent=P; (2*Parent)+1<N; Parent=Child) {
        Child = 2*Parent+1;
        if(Child!=N-1&&EdgeArray[Child].Weight>EdgeArray[Child+1].Weight){//取左右子结点较小的一个
            Child++;
        }
        if(EdgeArray[Child].Weight<X.Weight){//如果根结点的权重比子结点要大 根结点下浮
            EdgeArray[Parent]=EdgeArray[Child];
        }else{
            break;
        }
    }
    EdgeArray[Parent]=X;
}


void InitializeEdgeArray(LGraph Graph,LEdge EdgeArray){
    Vertex V;
    PtrToAdjVNode W;
    int ECount = 0;
    //初始化EdgeArray
    for (V=0; V<Graph->Nv; V++) {
        for (W=Graph->G[V].FirstEdge; W; W=W->Next) {
            if(V<W->AdjV){//避免重复录入无向图的边 只录入V1<V2的
                EdgeArray[ECount].V1=V;
                EdgeArray[ECount].V2=W->AdjV;
                EdgeArray[ECount++].Weight=W->Weight;
            }
        }
    }
    //初始化EdgeArray为最小堆
    for (ECount=Graph->Ne/2; ECount>0; ECount--) {
        PercDown(EdgeArray, ECount, Graph->Ne);
    }
    
}

//获取最小边的下标
int GetMinEdge(LEdge EdgeArray,int CurrentSize){
    //将堆根结点与最后一个元素交换位置
    struct LENode tempNode;
    tempNode = EdgeArray[0];
    EdgeArray[0]=EdgeArray[CurrentSize-1];
    EdgeArray[CurrentSize-1]=tempNode;
    //在将0-CurrentSize-1的数组调整为最小堆
    PercDown(EdgeArray, 0, CurrentSize-1);
    return CurrentSize-1;//返回最小边所在位置
}
/**最小堆定义结束 */

int Kruskal(LGraph Graph,LGraph MST){
    /**将最小生成树保存为邻接表存储的图MST,并返回最小权重和*/
    WeightType TotalWeight;
    int ECount,NextEdge;
    SetArray VArray;//顶点数组
    LEdge EArray;//边数组
    
    //初始化顶点数组
    InitializeVSet(VArray);
    //初始化边的最小堆
    EArray = (LEdge)malloc(sizeof(struct LENode)*Graph->Ne);
    InitializeEdgeArray(Graph, EArray);
    
    //建立只有顶点的最小生成树MST
    MST=CreateLGraph(Graph->Nv);
    
    TotalWeight=0;//初始化权重和为0
    ECount=0;//初始化收录边数为0
    NextEdge=Graph->Ne;//初始化为边集合的数目
    while(ECount<Graph->Nv-1){//当收集的边数目 不足以构成最小生成树时继续循环
        NextEdge = GetMinEdge(EArray, NextEdge);/** 从边集中获取权重最小的边的位置*/
        if(NextEdge<0){//如果返回的下标小于0 说明所有边已经取完
            break;
        }
        //如果该边加入不构成回路 两结点不属于同一个联通集
        if(CheckIsCircle(VArray, EArray[NextEdge].V1, EArray[NextEdge].V2)==1){
            InsertEdge(MST, EArray+NextEdge);//EArray+NextEdge 得到的是 EArray[0]的地址+NextEdge
            TotalWeight+=EArray[NextEdge].Weight;
            ECount++;
        }
    }
    
    if(ECount<Graph->Nv-1){
        TotalWeight=-1;//图不连通
    }
    
    return TotalWeight;
}
