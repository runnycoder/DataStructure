//
//  ArrayQueue.h
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//  利用数字实现队列

#ifndef ArrayQueue_h
#define ArrayQueue_h

#include <stdio.h>
typedef int Position;
struct QNode{
    int *Data;
    Position front,rear;
    int maxSize;
};
typedef struct QNode* AQueue;

AQueue createQueue(int maxSize);
int isFull(AQueue q);
int isEmpty(AQueue q);
int addQueue(AQueue q,int x);
int deleteQueue(AQueue q);
#endif /* ArrayQueue_h */
