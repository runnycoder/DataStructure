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
#include "AVLTree.h"
//#include "BinaryTree.h"
//typedef int Position;
typedef int Element;
typedef int APosition;
//typedef BinaryTree Element;
// typedef  AVLTree Element;
struct QNode{
    Element *Data;
    APosition front,rear;
    int maxSize;
};
typedef struct QNode* AQueue;

AQueue createQueue(int maxSize);
int isFull(AQueue q);
int isEmpty(AQueue q);
int addQueue(AQueue q,Element x);
Element deleteQueue(AQueue q);
#endif /* ArrayQueue_h */
