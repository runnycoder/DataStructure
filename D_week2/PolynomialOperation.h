//
//  PolynomialOperation.h
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//  多项式操作

#ifndef PolynomialOperation_h
#define PolynomialOperation_h

#include <stdio.h>
struct PolyNode{
    int codef;//系数
    int expon;//指数
    struct PolyNode *link;
};
typedef struct PolyNode * Polynomial;

Polynomial readPoly(void);
void printPoly(Polynomial P);
void Attach(int c,int e,Polynomial *pRear);
int compare(int a,int b);
Polynomial polyAdd(Polynomial P1,Polynomial P2);
Polynomial polyMultiplication_Violence(Polynomial P1,Polynomial P2);
Polynomial polyMutiplication_Insert(Polynomial P1,Polynomial P2);
#endif /* PolynomialOperation_h */
