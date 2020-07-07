//
//  KMPStrMatch.c
//  D_week6
//
//  Created by runny on 2020/7/7.
//  Copyright © 2020 runny. All rights reserved.
//  KMT字符串匹配算法

#include "KMPStrMatch.h"
//暴力字符串匹配算法 循环SourceStr的每一位 对Pattern进行匹配
void ViolenceMatch(char* SourceStr,int SL,char* Pattern,int PL){
    
    int i,j;
    i=0;
    j=0;
    while(i<SL&&j<PL){
        if(SourceStr[i]!=Pattern[j]){//匹配失败 SourceStr回到当前匹配起始位置的下一位 Pattern从头开始
            i=i-j+1;
            j=0;
        }else{//匹配成功 继续下一位
            i++;
            j++;
        }
    }
    if(j==PL){
        printf("匹配成功\n");
    }
}

/**
    KMP字符串匹配算法 暴力匹配法匹配过程中 匹配失败源字符串每次都要回溯
    Pattern从头开始 这样浪费了大量的时间
    ABCABCBACAB
        ABCBAA

 */

//获取模式字符串的next数组 next数组记录的是当前位置字符如果匹配失败 pattern回退的位置
int* getNextArray(char* Pattern,int PL){
    int* next = (char*)malloc(sizeof(char)*PL);
    int i,j;
    i=0;
    j=-1;//初始化为next[0]
    next[0]=-1;
    while(i<PL-1){
        if(j==-1||Pattern[i]==Pattern[j]){//当j=-1的时候说明要么是匹配的第一个元素 要么是回退到了第一个元素 此时i++ j=0 当前元素的回退坐标为j 当j!=-1 且匹配成功 则i++ j++ 当前元素的回退位置等于前一个元素回退位置+1
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
    for (i=0; i<PL; i++) {
        printf("%d \n",next[i]);
    }
    return next;
}

void KMP(char* SourceStr,int SL,char* Pattern,int PL){
    int i,j;
    int* next = getNextArray(Pattern, PL);
    i=0;
    j=0;
    while(i<SL&&j<PL){
        if(SourceStr[i]==Pattern[j]){
            i++;
            j++;
        }else{
            i++;
            j=next[j];
        }
    }
    if(j==PL){
        printf("匹配成功!");
    }
}


