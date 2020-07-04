//
//  QuickSort.c
//  D_week5
//
//  Created by runny on 2020/7/4.
//  Copyright © 2020 runny. All rights reserved.
/**
    快速排序 核心思想分治法
    从待排序数组中选择一个元素P(元素的选择方法决定了快速排序的效率)
    然后调整待排序数组 使得P->left<P<P->Right
    递归其左右子序列
    好处是 在一次位置调整之后被选中的元素P和左右断点三个元素 后序的位置就已经确定了
*/
#include "QuickSort.h"
typedef int  ElementType;

void Swap(ElementType* A,ElementType* B){
    ElementType Temp;
    Temp = *A;
    *A=*B;
    *B=Temp;
}

/// 选择快速排序的核心调整元素
/// @param Source <#Source description#>
/// @param Left <#Left description#>
/// @param Right <#Right description#>
ElementType selectPivot(ElementType Source[],int Left,int Right){
    int Center;
    Center = (Left+Right)/2;
    if(Source[Left]>Source[Center]){
        Swap(&Source[Left],&Source[Center]);
    }
    if (Source[Left]>Source[Right]) {
        Swap(&Source[Left],&Source[Right]);
    }
    if (Source[Center]>Source[Right]) {
        Swap(&Source[Center],&Source[Right]);
    }
    //将中间的元素和R-1位置的元素交换位置 方便后续调整处理
    Swap(&Source[Center],&Source[Right-1]);
    return Source[Right-1];
}

void QuickSort(ElementType Source[],int Left,int Right){
    int Pivot,Threshold,Low,High;
    if(Right-Left>=Threshold){//如果待排序元素多于设定的阈值则进行快速排序 否则进行简单的插入排序
        Pivot = selectPivot(Source, Left, Right);
        Low = Left;
        High = Right-1;
        while (1) {
            while (Source[++Low]<Pivot) {
                Low++;
            }
            while (Source[--High]>Pivot) {
                High--;
            }
            if (Low<High) {//将比Pivot小的值交换到左边 比Pivot大的值交换到右边
                Swap(&Source[Low], &Source[High]);
            }else{
                break;
            }
        }
        Swap(&Source[Low], &Source[Right-1]);//将Pivot放到正确的位置
        QuickSort(Source,Left,Low-1);
        QuickSort(Source,Low+1,Right);
    }else{
        //递归子列到了一定规模之后进行简单插入排序
        int i,j;
        ElementType TempI;
        for (i=Left+1; i<Right-Left+1; i++) {
            TempI=Source[i];
            for (j=i; j>Left; j--) {
                if(Source[i]>Source[i-1]){
                    Swap(&Source[i-1], &Source[i]);
                }
            }
            Source[j]=TempI;
        }
        

    }
}
