//
//  LinkQueue.c
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//

#include "LinkQueue.h"
#include "stdlib.h"

int LQueueIsEmpty(LQueue q){
    return q->front==NULL;
}
//入队操作就是正常的链表追加 q->rear = *PtrToNode;

//出队操作
int deleteLQueue(LQueue q){
    Position tempCell;
    int x;
    if(LQueueIsEmpty(q)){
        printf("队列为空!\n");
        return -1;
    }else{
        tempCell=q->front;
        if(q->front==q->rear){//队列只有一个元素
            q->front=q->rear=NULL;
        }else{
            q->front=tempCell->next;
        }
        x = tempCell->Data;
        free(tempCell);
        return x;
    }
}

