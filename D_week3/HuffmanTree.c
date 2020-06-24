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
