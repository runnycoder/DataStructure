//
//  ArrayList.h
//  D_week2
//
//  Created by runny on 2020/6/17.
//  Copyright © 2020 runny. All rights reserved.
//  利用数组实现线性表

#ifndef ArrayList_h
#define ArrayList_h

#include <stdio.h>
typedef int Position;
typedef struct ALNode *List;

struct ALNode {
    int  * Data;
    Position last;
};
List makeEmpty(void);
Position findElement(List L,int x);
int insertElement(List L,int x,Position p);
int deleteElement(List L,Position p);
void printList(List L);
#endif /* ArrayList_h */
