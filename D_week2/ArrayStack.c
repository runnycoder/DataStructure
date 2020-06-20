//
//  ArrayStack.c
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//

#include "ArrayStack.h"
AStack CreateAStack(int MaxSize){
    AStack s = (AStack)malloc(sizeof(struct SNode));
    s->Data = (int *)malloc(MaxSize*sizeof(int));
    s->Top=-1;
    s->MaxSize=MaxSize;
    return s;
}

int AStackIsFull(AStack s){
    if(s->Top==s->MaxSize-1){
        return 1;
    }else{
        return 0;
    }
}
int AStackIsEmpty(AStack s){
    if(s->Top==-1){
        return 1;
    }else{
        return 0;
    }
}


void AStackPush(AStack s,Element x){
    if(AStackIsFull(s)){
        printf("堆栈已满!\n");
    }else{
        s->Data[++s->Top]=x;
    }
}

Element AStackPop(AStack s){
    Element x ;
    if(AStackIsEmpty(s)){
        printf("堆栈已空!\n");
    }else{
        x = s->Data[s->Top--];
    }
    return x;
}
