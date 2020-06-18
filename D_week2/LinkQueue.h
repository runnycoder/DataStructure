//
//  LinkQueue.h
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//  利用链表实现队列

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>
typedef struct Node *PtrToNode;
struct Node{//定义队列节点
    int Data;
    PtrToNode next;
};
typedef PtrToNode Position;

struct QNode{//定义队列结构
    Position front,rear;//头尾指针
    int maxSize;//最大容量
};
typedef struct QNode * LQueue;

int LQueueIsEmpty(LQueue q);
int deleteLQueue(LQueue q);
#endif /* LinkQueue_h */
