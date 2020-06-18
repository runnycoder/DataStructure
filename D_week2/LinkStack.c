//
//  LinkStack.c
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//

#include "LinkStack.h"
#include "stdlib.h"
LStack createLStack(){
    LStack s;
    s = (struct SNode *)malloc(sizeof(struct SNode));
    s->next = NULL;
    return s;
}

int LStackIsEmpty(LStack s){
    return s->next==NULL;
}

int LStackPush(LStack s,int x){
    PtrToSNode tempCell;
    tempCell =(PtrToSNode)malloc(sizeof(struct SNode));
    tempCell->Data=x;
    tempCell->next=s->next;
    s->next=tempCell;
    return 1;
}

int LStackPop(LStack s){
    PtrToSNode tempCell;
    if(LStackIsEmpty(s)){
        printf("堆栈已空!\n");
        return -1;
    }else{
        tempCell = s->next;
        int x = tempCell->Data;
        s->next=tempCell->next;
        free(tempCell);
        return x;
    }
}
