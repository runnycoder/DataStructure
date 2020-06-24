//
//  HeapOperation.c
//  D_week3
//
//  Created by runny on 2020/6/24.
//  Copyright © 2020 runny. All rights reserved.
//  堆的操作练习 堆是一种完全二叉树类型的存储结构 任意结点的值都比其左右的子结点要大的称为最大堆 反之称为最小堆 此处采用数组存储完全二叉树 数组0位置为哨兵 防止操作过程中越界

#include "HeapOperation.h"
#include "stdlib.h"
#define MAX_DATA 1000;
#define MIN_DATA -1000;
MaxHeap CreateMaxHeap(int MaxSize){
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    HElementType * Data = (HElementType *)malloc(sizeof(HElementType)*(MaxSize+1));
    H->Data =Data;
    H->Capacity=MaxSize;
    H->Size=0;
    H->Data[0]=MAX_DATA;
    return H;
}

MinHeap CreateMinHeap(int MaxSize){
    MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
    HElementType * Data = (HElementType *)malloc(sizeof(HElementType)*(MaxSize+1));
    H->Data =Data;
    H->Capacity=MaxSize;
    H->Size=0;
    H->Data[0]=MIN_DATA;
    return H;
}

int IsFull(MaxHeap H){
    return (H->Size==H->Capacity);
}

int IsEmpty(MaxHeap H){
    return (H->Size==0);
}
//最大堆插入
int MaxHeapInsert(MaxHeap H,HElementType X){
    int i;
    if(IsFull(H)){
        printf("最大堆已满!");
        return -1;
    }
    i = ++H->Size;//将i指向最后要插入的位置
    //上滤寻找X插入的位置
    for(;H->Data[i/2]<X;i/=2){//如果插入位置的父结点值要比插入数值小 则交换位置
        H->Data[i]=H->Data[i/2];
    }
    //循环结束后i的位置就是 X要插入的位置
    H->Data[i]=X;
    return 1;
}
//最小堆插入
int MinHeapInsert(MinHeap H,HElementType X){
    int i;
    if(IsFull(H)){
        printf("最小堆已满!");
        return -1;
    }
    i = ++H->Size;
    for (; H->Data[i/2]>X; i/=2) {
        H->Data[i]=H->Data[i/2];
    }
    H->Data[i]=X;
    return 1;
    
}

//堆删除 从根节点删除 然后用最后的元素替换根节点 再从根结点下滤寻找合适的位置
HElementType MaxHeapDelete(MaxHeap H){
    int Parent,Child;
    if(IsEmpty(H)){
        printf("最大堆已空!");
        return -1;
    }
    HElementType temp = H->Data[H->Size--];
    HElementType MaxItem = H->Data[1];
    for (Parent = 1; Parent*2<H->Size; Parent=Child) {
        Child = 2*Parent;
        if(Child!=H->Size&&H->Data[Child]<H->Data[Child+1]){//先判断左子结点是否已经是最后的数值了 否则会出现角标越界
            Child = Child +1;
        }
        if(temp>H->Data[Child]){
            break;
        }else{
            H->Data[Parent] = H->Data[Child];
        }
    }
    H->Data[Parent]=temp;
    return MaxItem;
}

HElementType MinHeapDelete(MinHeap H){
    HElementType MinItem,Temp;
    MinItem = H->Data[1];
    Temp = H->Data[H->Size--];
    int Parent,Child;
    for (Parent=1; Parent*2<=H->Size; Parent=Child) {
        Child = 2*Parent;
        if(Child!=H->Size&&H->Data[Child]>H->Data[Child+1]){//在左右结点之中选择最小的一个
            Child ++;
        }
        if(Temp<H->Data[Child]){
            break;
        }else{
            H->Data[Parent]=H->Data[Child];
        }
    }
    H->Data[Parent]=Temp;
    return MinItem;
}

/*建造最大堆 假设H->Data[]中的元素已经存在数组当中 调整数组中元素的顺序 使其满足最大堆特性
 */

void MaxPercDown(MaxHeap H,int p){
    int Parent,Child;
    HElementType X = H->Data[p];
    for (Parent=p; Parent*2<H->Size; Parent=Child) {
        Child = 2*Parent;
        if(Child!=H->Size&&H->Data[Child]<H->Data[Child+1]){
            Child++;
        }
        if(H->Data[Child]<X){//Parent>Child说明当前位置就是合适的位置
            break;
        }else{//Parent<Child则需要下滤X 直到找到合适的位置
            H->Data[Parent] = H->Data[Child];
        }
    }
    H->Data[Parent] = X;
    
}
//建造最小堆 假设H->Data[]中的元素已经存在数组当中 调整数组中元素的顺序 使其满足最小堆特性
void MinPercDown(MinHeap H,int p){//p代表要调整的位置
    int Parent,Child;
    HElementType X = H->Data[p];
    for (Parent=p; Parent*2<=H->Size; Parent=Child) {
        Child = 2*Parent;
        if(Child!=H->Size&&(H->Data[Child]>H->Data[Child+1])){
            Child++;
        }
        if(X>H->Data[Child]){
            break;
        }else{
            H->Data[Parent]=H->Data[Child];
        }
    }
    H->Data[Parent] = X;
}

void BuildMaxHeap(MaxHeap H){
    int i;
    for (i=H->Size/2; i>0; i--) {
        MaxPercDown(H,i);
    }
}

void BuildMinHeap(MaxHeap H){
    int i;
    for (i=H->Size/2; i>0; i--) {
        MinPercDown(H,i);
    }
}


