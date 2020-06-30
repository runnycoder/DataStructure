//
//  HuffmanTree.c
//  D_week3
//
//  Created by runny on 2020/6/24.
//  Copyright © 2020 runny. All rights reserved.
//

#include "HuffmanTree.h"
#include "HeapOperation.h"
#include "stdlib.h"
HuffmanTree MakeHuffmanTree(MinHeap H){
    HuffmanTree T;
    BuildMinHeap(H);
    for (int i = 1; i<H->Size; i++) {//取堆中两个最小值构造新结点 然后插入堆中 由于每次合并都会让结点总数减去1,最终剩下一个结点,因此共需要合并 h->size-1次
        T = (HuffmanTree)malloc(sizeof(struct TreeNode));
        T->Left = MinHeapDelete(H);
        T->Right = MinHeapDelete(H);
        T->Weight = T->Left->Weight+T->Right->Weight;
        MinHeapInsert(H, T);
    }
    T = MinHeapDelete(H);
    return T;
}

//计算霍夫曼树的最优化加权路径长度 Depth当前结点的深度
int CalculateWPL(HuffmanTree T,int Depth){
    if(!T->Left&&!T->Right){//如果当前结点为叶子结点则返回 Weight*Depth
        return T->Weight*Depth;
    }else{//如果不是叶子结点 则递归求左右子树的最优路径 左右子树最优路径之和即为当前霍夫曼树的最优路径
        return CalculateWPL(T->Left,Depth+1)+CalculateWPL(T->Right,Depth+1);
    }
}
