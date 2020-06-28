//
//  NetCollection.h
//  D_week4
//
//  Created by runny on 2020/6/24.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef NetCollection_h
#define NetCollection_h

#include <stdio.h>
typedef int ElementType;

typedef int CollectionName;//集合名称 假如数组下标表示元素的值 数组存储元素的父结点位置
typedef ElementType *CollectionType;
typedef struct {
    ElementType Data;
    int Parent;
} Collection;

int TSSNFind(ElementType C[],ElementType X);
int CompressionFind(ElementType C[],ElementType X);
void TSSNUnion(ElementType C[],CollectionName root1,CollectionName root2);
void RankUnion(ElementType C[],CollectionName root1,CollectionName root2);
void Check_Connection(ElementType C[]);
void Input_Connection(ElementType C[]);
void Check_NetWork(ElementType C[],int n);
void ConnectNet(void);
void PrintfArray(ElementType C[]);
#endif /* NetCollection_h */
