//
//  NetCollection.c
//  D_week4
//
//  Created by runny on 2020/6/24.
//  Copyright © 2020 runny. All rights reserved.
//

#include "NetCollection.h"

#include "stdlib.h"
//数组元素的Parent存储关联父结点的位置 根结点的父结点小于0
//int Find(Collection C[],ElementType X){
//    int i ;
//    for (i=0; (i<MAX_SIZE) && (C[i].Data!=X);i++) ;
//    if(i>MAX_SIZE){
//        return -1;
//    }
//    for (; C[i].Parent>0; i=C[i].Parent);
//    return i;
//}
//简单实现查找根结点
int TSSNFind(ElementType C[],ElementType X){
//    PrintfArray(C);
    for (; C[X]>=0; X=C[X]);
    return X;
}

//简单查询每次都要向上寻找根结点 可以在查找的同时进行路径压缩 通过X查询其父结点并在返回的过程中 修改当前结点的父结点为根结点 这样下次查询此结点的父结点时就可以直接找到

int CompressionFind(ElementType C[],ElementType X){
    if(C[X]<0){//找到根结点
        return X;
    }else{//递归查询父结点的根结点坐标 并在查询到之后递归修改经过结点的父结点的值 使路径上的结点都指向根结点
        return C[X]=CompressionFind(C, C[X]);
    }
}
/*简单实现连接 此处简单的将root2挂载到root1上 假设需要连接的是
 2 1
 3 1
 4 1
 ...
 n 1
 这样会形成一个长度为n的畸形树 每次查找1所属集合的根结点都要平均进行n次
 */
void TSSNUnion(ElementType C[],CollectionName root1,CollectionName root2){
    C[root2]=root1;
//    PrintfArray(C);
}

//使用按秩归并进行优化 合并的时候可以选择按树的高度进行归并 高度低的归并到高度高的。或者按结点的个数进行归并 结点数少的归并到结点数多的
void RankUnion(ElementType C[],CollectionName root1,CollectionName root2){
    if(C[root1]>C[root2]){//根结点存放的是集合元素的个数的负数 -3代表有3个元素
        C[root2]+=C[root1];
        C[root1]=root2;
    }else{//roo1结点多
        C[root1]+=C[root2]; //更新集合的元素个数
        C[root2]=root1;
    }
}

//校验两台电脑是否连接
void Check_Connection(ElementType C[]){

    printf("请输入需要操作的两台电脑编号!\n");
    ElementType u,v;
    CollectionName root1,root2;
    scanf("%d %d",&u,&v);
    root1 = TSSNFind(C, u);
    root2 = TSSNFind(C, v);
    if(root1!=root2){
        printf("电脑编号%d,%d is not connected!\n",u,v);
    }else{
        printf("电脑编号%d,%d is connected!\n",u,v);
    }
}



//连接两台电脑
void Input_Connection(ElementType C[]){
    printf("请输入需要操作的两台电脑编号!\n");
    ElementType u,v;
    CollectionName root1,root2;
    
    scanf("%d %d",&u,&v);
    root1 = TSSNFind(C, u);
    root2 = TSSNFind(C, v);
    if(root1!=root2){
        TSSNUnion(C, root1, root2);
    }
    
}

//校验所有电脑是否全部联通
void Check_NetWork(ElementType C[],int n){
    int counter = 0;
    for (int i =0; i<n; i++) {
        if(C[i]<0){
            counter++;
        }
    }
    if(counter==1){
        printf("this network is connected!\n");
    }else{
        printf("this network is not connected!\n");

    }
}

//输入电脑台数N 通过录入的命令符和电脑编号进行操作 直到所有的电脑都连接完毕 输出网络联通 I 连接两台电脑 C 检查输入的两台电脑是否联通 S 检查整个网路是否连接完毕
void ConnectNet(){
    CollectionType C ;
    for (int i = 0; i<100; i++) {
        C[i]=-1;
    }
    int n;
    char in;
    printf("请输入需要连接电脑的台数!\n");
    scanf("%d",&n);
    
    do {
        printf("请输出所要进行的操作!\nI 连接两台电脑\nC 检查输入的两台电脑是否联通 \nS 检查整个网路是否连接完毕,结束程序\n");
        
            
        scanf("%c",&in);

            switch (in) {
            case 'I':
                Input_Connection(C);
                break;
            case 'C':
                Check_Connection(C);
                break;
            case 'S':
                Check_NetWork(C, n);
                break;
        }
    } while (in!='S');
}

void PrintfArray(ElementType C[]){
    for (int i=0; i<100; i++) {
        printf("%d ",C[i]);
    }
    printf("\n");
}

