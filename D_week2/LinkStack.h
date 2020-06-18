//
//  LinkStack.h
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//  利用链表实现堆栈

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>
typedef struct SNode *PtrToSNode;
struct SNode{
    int Data;
    PtrToSNode next;
};
typedef PtrToSNode LStack;

LStack createLStack();
int LStackIsEmpty(LStack s);
int LStackPush(LStack s,int x);
int LStackPop(LStack s);
#endif /* LinkStack_h */
