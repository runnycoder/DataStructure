//
//  SortAlgorithms.c
//  D_week5
//
//  Created by runny on 2020/7/3.
//  Copyright © 2020 runny. All rights reserved.
/**
    几种常用的排序算法
    首先明确一个概念 什么是逆序 假设我们定义元素从左到右依次递增
    那么对于A[i]>A[j] ，i<j 则说明Ai Aj是逆序的 称(Ai,Aj)为一对逆序对 排序算法的目的就是消除所有的逆序对
*/
#include "SortAlgorithms.h"
typedef int ElementType;

void swap(ElementType* a,ElementType* b ){
    ElementType temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

/// 冒泡排序 每一轮从0开始交换相邻的元素 选择出来一个最大值放到最右端 同时待排序元素减去1
/// @param S 待排序数组
void bubbleSort(ElementType S[],int N){
    int isSwapFlag=0;//如果一轮扫描中都没有做交换说明已经排序完成 则直接跳出循序
    for (int i = N-1; i>0; i--) {
        for (int p=0; p<i; p++) {
            if(S[p]<S[p+1]){
                swap(&S[p],&S[p+1]);
                isSwapFlag=1;
            }
        }
        if(isSwapFlag==0){
            break;
        }
    }
}


/// 插入排序 初始化已排序的序列为{S[0]} 循环扫描1->N-1 插入已排序的序列同时后移
/// @param S <#S description#>
/// @param N <#N description#>
void insertSort(ElementType S[],int N){
    int i,p;
    int swapLength = 1;
    for (i=swapLength; i<N; i++) {
        ElementType temp = S[i];
        for (p=i; p>0&&temp<S[p-1]; p-=swapLength) {
            S[p]=S[p-1];
        }
        S[p]=temp;
    }
}


/// 希尔排序 选择排序和冒泡排序每次都是交换相邻位置的两个元素 这样一次交换只能消除一个逆序对
/// 假设Ai与Aj相邻 且为逆序对  Ai的逆序对为n Aj的逆序对为m 那么交换之后 Ai的逆序对为n-1 Aj的逆序对依然是m
/// 要想提高排序的效率那么 一次交换就要消灭更多的逆序对 这就是希尔排序的思想
/// @param S <#S description#>
/// @param N <#N description#>
void shellSort(ElementType S[],int N){
    int i,p,swapLength;//每次交换的元素相隔的距离 假设swapLength=5 则 0<->6 1<->7 2<->8
    for (swapLength=N/2; swapLength>0; swapLength/=2) {
        //内部则是一个选择排序
        for (i=swapLength; i<N; i++) {
            ElementType temp=S[i];
            for (p=i; p>swapLength&&temp<S[p-swapLength]; p-=swapLength) {
                S[p]=S[p-swapLength];
            }
            S[p]=temp;
        }
    }
}


void selectSort(ElementType S[],int N){
    int min = 100000;
    int i,j;
    for (i = 0; i<N-1; i++) {
        for (j = i; j<N; j++) {//每次从i->n-1的序列中寻找最小的元素 插入s[i]处
            if(S[j]<min){
                min=S[j];
            }
        }
        swap(&S[i], &S[j]);
    }
}


/// 将一个数组中的元素调整为最大堆
/// 核心思想 最大堆根结点一定是最大的值 如果root<MAX(left,right) 则交换root与MAX(left,right)的位置
/// @param S 待调整的元素数组
/// @param P 根结点的位置
/// @param N 数组元素的个数
void maxHeapPercDown(ElementType S[],int P,int N){
    int Parent,Child;
    ElementType X;
    X=S[p];//取出根结点数值
    //由于数组元素是从0开始 堆事完全二叉树的结构 则左子树的坐标为2*Parent+1
    for (Parent=p; 2*Parent+1<N; Parent=Child) {
        Child=2*Parent+1;
        if(Child!=N-1&&(S[Child]<S[Child+1])){//取左右子树较大的
            Child++;
        }
        if(X>=S[Child]){//如果根结点值最大则跳出循环(前提是当前根结点的左右子树已经是最小堆了 所以这个调整方法 相当于是在一个最大堆中插入一个新的结点进行调整)
            break;
        }else{//如果根结点值要小 则下滤
            S[Parent]=S[Child];
        }
    }
    S[Parent]=X;
}


/// 堆排序 堆排序是在选择排序的基础上进行优化的
/// 选择排序的过程中每次都要从未排序的元素中找到最小值 这个问题可以用堆来解决
/// @param S <#S description#>
/// @param N <#N description#>
void heapSort(ElementType S[],int N){
    //堆排序
    int i;
    
    for (i=N/2-1; i>0; i--) {
        maxHeapPercDown(S, i, N)
    }
    for (i=N-1; i>=; i--) {
        //将最大堆顶元素 与堆最小值交换 并将数组元素减去1 重新调整为最大堆
        swap(S[i], S[0]);
        maxHeapPercDown(S, 0, i);
    }
}
