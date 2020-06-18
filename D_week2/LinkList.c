//
//  LinkList.c
//  D_week2
//
//  Created by runny on 2020/6/17.
//  Copyright © 2020 runny. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>

//查找元素所在位置
Position findNode(List L,int x){
    Position p = L;
    while(p&&p->Data!=x){
        p=p->next;
    }
    if(p){
        return p;
    }else{
        return NULL;
    }
}

int AddNode(List L,int x){
    List  temp,rear;
    rear = L;
    while(rear->next){
        rear = rear->next;
    }
    if(rear){
        temp =(List)malloc(sizeof(List));
        temp->Data=x;
        rear->next=temp;
        temp->next=NULL;
        return 0;
    }else{
        return -1;
    }
    
    
}

//插入元素 头节点插入
int InsertNode(List L,int x,Position p){
    Position temp,pre;
    pre=L;
    while(pre&&pre->next!=p){
        pre=pre->next;
    }
    if(pre==NULL){//p节点不在链表中
        printf("插入位置p不在链表中!\n");
        return -1;
    }else{
        temp = (Position)malloc(sizeof(Position));
        temp->Data=x;
        temp->next=pre->next;
        pre->next=temp;
        return 0;
    }
}
//节点删除
void DeleteNode(List L,Position p){
    Position temp,pre;
    pre=L;
    while(pre&&pre->next!=p){
        pre=pre->next;
    }
    if(pre==NULL){//p节点不在链表中
        printf("删除位置p不在链表中!\n");
        
    }else{
        temp = p;
        pre->next=p->next;
        free(p);
    }

}

void printLinkList(List L){
    Position p = L;
    while(p){
        printf("%d ",p->Data);
        p=p->next;
    }
    printf("\n");
}
