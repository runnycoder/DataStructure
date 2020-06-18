//
//  CrossList.h
//  D_week2
//
//  Created by runny on 2020/6/17.
//  Copyright © 2020 runny. All rights reserved.
//  十字链表结构练习

#ifndef CrossList_h
#define CrossList_h

#include <stdio.h>
typedef struct OLNode{
    int row,col;/*非零元素的行和列下标*/
    int value;
    struct OLNode *right;/*非零元素所在行表、列表的后继链域*/
    struct OLNode *down;
}OLNode,*OLink;

typedef struct {
    OLink *rowHead;/*行、列链表的头指针向量*/
    OLink *colHead;
    int r,c,s;/*稀疏矩阵的行数、列数、非零元素的个数*/
}CrossList;
void createCrossList(CrossList *M);
#endif /* CrossList_h */
