//
//  BinaryIsomorphismTree.c
//  D_week3
//
//  Created by runny on 2020/6/22.
//  Copyright © 2020 runny. All rights reserved.
//

#include "BinaryIsomorphismTree.h"
#include "stdlib.h"

ITree NewNode(int V){
    ITree T = (ITree)malloc(sizeof(struct ITreeNode));
    T->Data=V;
    T->Left=T->Right=NULL;
    T->flag=0;
    return T;
}
ITree InsertNode(ITree T,IElementType X){
    if(!T){
        T = NewNode(X);
    }else{
        if(X<T->Data){
            T->Left = InsertNode(T->Left,X);
        }else if(X>T->Data){
            T->Right = InsertNode(T->Right,X);
        }
    }
    return T;
}

ITree MakeTree(int N){
    ITree T;
    int V;
    scanf("%d",&V);
    T = NewNode(V);
    for (int i = 1; i<N; i++) {
        scanf("%d",&V);
        T = InsertNode(T, V);
    }
    return T;
}
//判断是否同构 先根据一个序列构造出一颗树 然后用另一组给定序列的元素 一个一个的去这棵树进行校验 即查看此元素在树中经过的路径 如果找到元素所经过的结点(不包括元素本身)都是之前出现过的 说明路径一致 如果遇到没有之前没有访问过的结点则不一致。例如 通过 3 1 4 2 构造一颗树T 判断给定序列 3 2 4 1 是否与树T同构
int Check(ITree T,IElementType X){
    if(T->flag){//如果当前结点访问过
        if(X<T->Data){
            return Check(T->Left,X);
        }else if(X>T->Data){
            return Check(T->Right,X);
        }else{//
            return 0;
        }
    }else{//当前结点没有访问过
        if(X==T->Data){
            T->flag=1;
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}

int Juge(ITree T,int N){
    int V;
    int Flag=0;//Flag:0代表目前为止程序处理还是一致的 Flag:1发现有不一致的元素 如果不加Flag当程序读到不符合要求的元素程序就退出了 比如总共要读 3 2 4 1 四个数字 当读到2的时候 发现已经不同构了 就不会往后读取了 加上Flag是为了 连续读入用户输入序列进行同构的判断
    scanf("%d",&V);
    if(V!=T->Data){//根节点都不一致 一定不同构
        return 0;
    }else{
        for (int i =1; i<N; i++) {
            scanf("%d",&V);
            if((!Flag)&&(!Check(T, V))){//只要有一个元素顺序不对 就说明序列不同构成 当Flag=1时之循环读取 不进行判断
                Flag=1;
            }
            
        }
    }
    if(Flag==1){
        return 0;
    }else{
        return 1;
    }
}

//清除树T中的各个节点的Flag标记
void ResetTree(ITree T){
    if(T){
        if(T->Left){
            ResetTree(T->Left);
        }
        if(T->Right){
            ResetTree(T->Right);
        }
        T->flag = 0;
    }
}

void FreeTree(ITree T){
    if(T){
        if(T->Left){
            FreeTree(T->Left);
        }
        if(T->Right){
            FreeTree(T->Right);
        }
        free(T);
    }
}
