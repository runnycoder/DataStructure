//
//  ArrayStack.h
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//  利用数组实现堆栈

#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>
#include "BinaryTree.h"

//typedef BinaryTree Element;
typedef int  Element;
struct SNode{
    Element *Data;
    int Top;
    int MaxSize;
};
typedef struct SNode *AStack;

AStack CreateAStack(int MaxSize);
int AStackIsFull(AStack s);
int AStackIsEmpty(AStack s);
void AStackPush(AStack s,Element x);
Element AStackPop(AStack s);

#endif /* ArrayStack_h */
