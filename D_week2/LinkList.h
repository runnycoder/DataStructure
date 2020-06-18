//
//  LinkList.h
//  D_week2
//
//  Created by runny on 2020/6/17.
//  Copyright © 2020 runny. All rights reserved.
//  利用链表实现线性表

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
typedef struct LinkNode * PtrToLNode;

struct LinkNode{
    int Data;
    PtrToLNode next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position findNode(List L,int x);
int AddNode(List L,int x);
int InsertNode(List L,int x,Position p);
void DeleteNode(List L,Position p);
void printLinkList(List L);
#endif /* LinkList_h */
