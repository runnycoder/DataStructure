//
//  main.c
//  D_week1
//
//  Created by runny on 2020/6/15.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>
int max(int A,int B,int C);
int calculateMaxSubColumn(const int *arr,int length);
int calculateMaxSubColumnO2(const int *arr,int length);
int calculateMaxSubColumnOn(const int *arr,int length);
int DivideCalculdateSubColumn(const int *arr,int left,int right);
//最大子列问题求解
int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
//    int a = 3;
//    int b = 5;
//    int c =4;
//    int maxNumber =  max(a, b, c);
    
    int arr[6] = {-2,2,4,-1,3,-2};
//    int max =  calculateMaxSubColumnOn(arr,6);
    
    int max =  DivideCalculdateSubColumn(arr,0,5);
    printf("最大子列和为:%d\n",max);
    return 0;
}

//暴力求解法 O(n)=n^3
int calculateMaxSubColumn(const int *arr,int length){
    int i,j,k;
    int maxSubListNumber = 0;
    for (i=0; i<length; i++) {
        for (j=0; j<length; j++) {
            int thisSubListNumber = 0;
            for (k=i; k<j; k++) {
                thisSubListNumber+=arr[k];
                if(thisSubListNumber>maxSubListNumber){
                    maxSubListNumber=thisSubListNumber;
                }
            }
        }

    }
    return maxSubListNumber;
}

//只用两层循环 计算下一子列不需要每次都从头开始求和 Sn+1=Sn+An
int calculateMaxSubColumnO2(const int *arr,int length){
    int i,j;
    int maxSubListNumber = 0;
    int tempSubListNumber = 0;
    for (i=0; i<length; i++) {
        tempSubListNumber = 0;
        for (j=i; j<length; j++) {//j = i
            tempSubListNumber+=arr[j];
            if(tempSubListNumber>maxSubListNumber){
                maxSubListNumber=tempSubListNumber;
            }
            
        }

    }
    return maxSubListNumber;
}


//在线处理 如果累加的子列为负数 则放弃此部分子列重新开始累加
int calculateMaxSubColumnOn(const int *arr,int length){
    int i;
    int maxSubListNumber = 0;
    int thisSubListNumber = 0;
    for (i=0; i<length; i++) {
        thisSubListNumber+=arr[i];
        if(thisSubListNumber>maxSubListNumber){
            maxSubListNumber=thisSubListNumber;
        }else if(thisSubListNumber<0){
            thisSubListNumber=0;
        }

    }
    return maxSubListNumber;
}


//递归分治法  把一个数列分为左右两个子列 分别求出左,右和整个子列的最大子列 然后取其中最大的即是最大子列和


int max(int A,int B,int C){
    return A>B?A>C?A:C:B>C?B:C;
}

int DivideCalculdateSubColumn(const int *arr,int left,int right){
    
    int maxLeftSublistNumber = 0;
    int maxRigthSublistNumber = 0;
    int center = (left+right)/2;
    if(left==right){//左子列等于右子列说明只剩下一个数字递归终止
        if(arr[left]>0){
            return arr[left];
        }else{
            return 0;
        }
    }
    
    maxLeftSublistNumber = DivideCalculdateSubColumn(arr,left,center);
    maxRigthSublistNumber = DivideCalculdateSubColumn(arr,center+1,right);
    
    int maxLeftBorderSum = 0;
    int leftBorderSum = 0;
    for (int i = center; i>=left; i--) {
        leftBorderSum+=arr[i];
        if(leftBorderSum>maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }
    }
    
    int maxRightBorderSum = 0;
    int rightBorderSum = 0;
    for (int i = center+1; i<=right; i++) {
        rightBorderSum+=arr[i];
        if(rightBorderSum>maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
        }
    }
    //跨中线最大子列值
    int intMaxBorderSum = maxLeftBorderSum+maxRightBorderSum;
    return max(maxLeftSublistNumber,maxRigthSublistNumber,intMaxBorderSum);
}


