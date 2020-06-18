//
//  ArrayQueue.c
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//

#include "ArrayQueue.h"

AQueue createQueue(int maxSize){
    AQueue q = (AQueue)malloc(sizeof(struct QNode));
    int *data=(int*)malloc(maxSize*sizeof(int));
    q->Data=data;
    q->maxSize=maxSize;
    q->front=q->rear=0;
    return q;
}

//这种判定方式 对列的最大容纳数n=maxSize-1 留下一个空位
int isFull(AQueue q){
    return ((q->rear+1)%q->maxSize==q->front);
}

int isEmpty(AQueue q){
    return (q->front==q->rear);
}

int addQueue(AQueue q,int x){
    if(isFull(q)){
        printf("队列已满!\n");
        return 0;
    }else{
        q->rear = (q->rear+1)%q->maxSize;
        q->Data[q->rear]=x;
        return 1;
    }
}

int deleteQueue(AQueue q){
    if(isEmpty(q)){
        printf("队列已空!\n");
        return -1;
    }else{
        int x= q->Data[q->front];
        q->front=(q->front+1)%q->maxSize;
        return x;
    }
}

