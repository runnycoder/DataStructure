//
//  MergeSort.c
//  D_week5
//
//  Created by runny on 2020/7/3.
//  Copyright © 2020 runny. All rights reserved.
//  归并排序的实现 归并排序的思想是分治法 把大规模的问题分成小规模的去解决

#include "MergeSort.h"
#include "stdlib.h"
typedef int ElementType;
/**
    递归方式实现归并排序
 */


///将数组中 两个有序的子列合并成新的子列
/// @param A 待处理数组A
/// @param Temp 临时存储合并数据的数组
/// @param L 待排序子列左边开始的坐标
/// @param R 待排序子列右边开始的坐标
/// @param RightEnd 待排序子列右边结束的左边
void Merge(ElementType A[],ElementType Temp[],int L,int R,int RightEnd){
    
    int LeftEnd,Start,OperationNumbers;
    LeftEnd = R-1;
    Start=L;
    OperationNumbers = RightEnd-L+1;
    while (L<LeftEnd&&R<RightEnd) {
        if(A[L]<=A[R]){//将较小值存储到Temp
            Temp[Start++]=A[L++];
        }else{
            Temp[Start++]=A[R++];
        }
    }
    
    while(L<LeftEnd){//左子列未处理完 将左子列追加到Temp的后面
        Temp[Start++]=A[L++];
    }
    while (R<RightEnd) {
        Temp[Start++]=A[R++];
    }
    
    for (int i=0; i<OperationNumbers; i++,RightEnd--) {//有序的将Temp数组中排好序的元素复制到原数组中
        A[RightEnd]=Temp[RightEnd];
    }
}

void MSort(ElementType A[],ElementType Temp[],int L,int RightEnd){
    int Center;
    if(L<RightEnd){
        Center = (L+RightEnd)/2;
        MSort(A, Temp, L, Center);//递归解决左边
        MSort(A, Temp, Center+1, RightEnd);//递归解决右边
        Merge(A, Temp, L, Center+1, RightEnd);//合并左右子列
    }
}

/// 递归方式实现归并排序
/// @param A 待排序数组
/// @param N 元素个数
void RecusiveMergeSort(ElementType A[],int N){
    ElementType* Temp;
    Temp = (ElementType*)malloc(sizeof(ElementType)*N);
    if(Temp){
        MSort(A, Temp, 0, N-1);
        free(Temp);
    }else{
        printf("空间不足!");
    }
  
}

/** 递归方式实现归并结束*/

/** 循环方式实现归并
    核心思想 将未排序的数组看作长度length=1 的N个已排序数列
    第一轮两两进行合并 合并结束length*=2
    循环操作直到lenght=N  循环的次数为logN
 */


/// 两两归并有序子序列
/// @param A 待归并数组A
/// @param Temp 临时数组Temp
/// @param N 元素个数
/// @param Lengh 子列长度
void MergePass(ElementType A[],ElementType Temp,int N,int Lengh){
    
    int i,j;
    for (i=0; i<=N-2*Lengh; i+=2*Lengh) {//此处循环到倒数第二对子列就结束
        Merge(A, Temp, i, i+Lengh, i+2*Lengh-1);
    }
    //判断剩下的长度是是大于一个子列还是小于一个子列
    if(i+Lengh<N){
        Merge(A, Temp, i, i+Lengh+1, N-1);
    }else{
        for (j=i; j<N; j<++) {
            Temp[j]=A[j];
        }
    }
}

void Merge_Sort(ElementType A[],int N){
    ElementType* Temp;
    Temp = (ElementType*)malloc(sizeof(ElementType)*N);
    int Length,i;
    if (Temp!=NULL) {
        while (Length<N) {
            //每轮进行两次合并 保证最后的排序好的元素一定是合并到了A当中
            //当Length=N的时候 A存储的是最后的结果 Temp是前一次的结果
            //当Length>N时 A=Temp
            MergePass(A, Temp, N, Length);//先将A的子列合并到Temp
            Length*=2;
            MergePass(Temp, A, N, Length);//再把Temp子列合并到A
            Length*=2;
        }
        free(Temp);
    }else{
        printf("内存空间不足!");
    }
    
    
    
}
