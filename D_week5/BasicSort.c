//
//  BasicSort.c
//  D_week5
//
//  Created by runny on 2020/7/4.
//  Copyright © 2020 runny. All rights reserved.
//  基数排序

#include "BasicSort.h"
#include "stdlib.h"
#define MaxDigt 4
#define Radix 10

typedef int ElementType;

typedef struct Node* PtrToNode;
//桶元素结点
struct Node{
    int Key;
    PtrToNode next;
};
//桶头结点
struct HeadNode{
    PtrToNode Head,Tail;
};

typedef struct HeadNode Bucket[Radix];

int GetDigt(int X,int D){
    //默认次位D=1 主位D<=MaxDigt
    int d, i;
         
        for (i=1; i<=D; i++) {
            d = X % Radix;
            X /= Radix;
        }
    return d;
    
}

//低位基数排序
void LSDRadixSort(ElementType A[],int N){
    int i,D,Di;
    Bucket B;
    PtrToNode temp,p,List = NULL;
    for (i=0; i<Radix; i++) {//初始化桶数组元素为空链表
        B[i].Head=B[i].Tail=NULL;
    }
    for (i=N; i>0; i--) {//将数组的元素顺序存入链表List中
        temp = (PtrToNode)malloc(sizeof(struct Node));
        temp->Key=A[i];
        temp->next=List;
        List=temp;
    }
    
    for (D=1; D<=MaxDigt; D++) {
        p=List;
        //循环将链表中的元素按位插入桶数组的链表中
        while (p) {
            Di=GetDigt(p->Key, D);//获取当前元素当位的数值
            //从list中摘除首位
            temp = p; p=p->next;
            temp->next=NULL;
            if(B[Di].Head==NULL){//插入桶中的列表
                B[Di].Head=B[Di].Tail=temp;
            }else{
                B[Di].Tail->next=temp;
                B[Di].Tail=temp;
            }
        }
        
       //收集当前桶中的元素 放入链表List中进行下一轮按位排序
       List=NULL;
       for (Di=Radix-1; Di>=0; Di--) {
           if(B[Di].Head){
               /** 将桶中的链表插入到List的表头 目的是让此轮按位排序的元素 按照从位值从小到大链表在从头到位排列*/
               B[Di].Tail->next=List;
               List=B[Di].Head;
               B[Di].Head=B[Di].Tail=NULL;//清空桶
           }
       }
    }
    
    for (i=0; i<N; i++) {
        temp=List;
        List=List->next;
        A[i]=temp->Key;
        free(temp);
    }
    
    
}

/**
 高位基数排序
 核心思想 高位基数排序和地位最大的区别在于
 从高位开始进行桶排序 第一轮就能将 数组的元素分为有明确大小的 Radix个子序列
 然后就可以对子序列递归的使用高位基数排序
 */

void MSD(ElementType A[],int Left,int Right,int D){
    int i,j,Di;
    Bucket B;
    PtrToNode temp,p,List=NULL;
    if(D==0){//递归基础
        return;
    }
    for (i=0; i<Radix; i++) {//初始化桶
        B[i].Head=B[i].Tail=NULL;
    }
    
    //将数组的元素顺序存入列表中
    for (i=Left; i<=Right; i++) {
        temp = (PtrToNode)malloc(sizeof(struct Node));
        temp->Key=A[i];
        temp->next=List;
        List=temp;
    }
    
    p=List;
    //元素依次插入桶中
    while (p) {
        Di = GetDigt(p->Key, D);
        temp=p,p=p->next;
        
        //插入B[Di]号桶中
        if(B[Di].Head){
            B[Di].Head=B[Di].Tail=NULL;
        }else{
            B[Di].Tail->next=temp;
            B[Di].Tail=temp;
        }
    }
    
    //收集桶
    i=j=Left;
    for (Di=0; Di<Radix; Di++) {
        if(B[Di].Head){//如果桶元素不为空则插入数组A中
            p=B[Di].Head;
            while (p) {
                temp=p;
                p=p->next;
                A[j++]=temp->Key;
                free(temp);
            }
            /**递归对B[Di]的桶元素进行排序*/
            MSD(A,i,j-1,D-1);
            i=j;//下一个桶元素的开始坐标为j
        }
    }
}

void MSDRadixSort(ElementType A[],int N){
    MSD(A, 0, N-1, MaxDigt);
}
