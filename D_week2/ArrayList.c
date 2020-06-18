//
//  ArrayList.c
//  D_week2
//
//  Created by runny on 2020/6/17.
//  Copyright © 2020 runny. All rights reserved.
//

#include "ArrayList.h"

const int MAXZIZE=100;


List makeEmpty(){
    List L;
    L = (List)malloc(sizeof(struct ALNode));
    L->Data = (int*)malloc(sizeof(int)*MAXZIZE);
    L->last=-1;
    return L;
}

//查找元素位置
Position findElement(List L,int x){
    Position i = 0;
    while (i<=L->last&&L->Data[i]!=x) {
        i++;
    }
    
    if(i>L->last){
        return -1;
    }else{
        return i;
    }
}
//在L的位置p插入元素x
int insertElement(List L,int x,Position p){
    Position i;
    //判断是否已经满了
    if(L->last==MAXZIZE-1){
        printf("链表已满!\n");
        return -1;
    }
    if(p<0&&p>L->last+1){//校验插入位置的合法性
        printf("链表插入位置非法!\n");
        return -1;
    }
    
    //将p点及之后的元素后移一位
    for (i=L->last; i>=p; i--) {
        L->Data[i+1]=L->Data[i];
    }
    //在p点插入元素x
    L->Data[p]=x;
    L->last++;
    return 0;
    
}
//删除链表L指定位置p的元素
int deleteElement(List L,Position p){
    Position i;
    int x ;
    if(L->last<0){
        printf("链表已空!\n");
        return -1;
    }
    if(p<0||p>L->last+1){//校验插入位置的合法性
        printf("链表删除位置非法!\n");
        return -1;
    }
    x=L->Data[p];
    for (i=p; i<L->last; i++) {
        L->Data[i]=L->Data[i+1];
    }
    L->last--;
    return x;
    
}

void printList(List L){
    int i = 0;
    while(i<=L->last){
        printf("%d ",L->Data[i]);
        i++;
    }
    printf("\n");
}
