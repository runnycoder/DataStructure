//
//  HeapOperation.h
//  D_week3
//
//  Created by runny on 2020/6/24.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef HeapOperation_h
#define HeapOperation_h

#include <stdio.h>
#include "HuffmanTree.h"
typedef struct HNode* Heap;
//typedef int HElementType; //此处定义堆中的元素 如果是int可以执行比较大小 如果是其他struct类型 则需要自定义比较大小的方法
typedef HuffmanTree HElementType;
struct HNode{
    HElementType *Data;
    int Size;//堆中当前元素的个数
    int Capacity;//堆的最大容量
};
typedef Heap MaxHeap;
typedef Heap MinHeap;

MaxHeap CreateMaxHeap(int MaxSize);

MinHeap CreateMinHeap(int MaxSize);

int IsFull(MaxHeap H);

int IsEmpty(MaxHeap H);

int MaxHeapInsert(MaxHeap H,HElementType X);

int MinHeapInsert(MinHeap H,HElementType X);

HElementType MaxHeapDelete(MaxHeap H);

HElementType MinHeapDelete(MinHeap H);

void MaxPercDown(MaxHeap H,int p);

void MinPercDown(MinHeap H,int p);

void BuildMaxHeap(MaxHeap H);

void BuildMinHeap(MaxHeap H);


#endif /* HeapOperation_h */
