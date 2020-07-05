//
//  HashTable.c
//  D_week6
//
//  Created by runny on 2020/7/5.
//  Copyright © 2020 runny. All rights reserved.
//  允许扩展最大散列空间的散列表

#include "HashTable.h"
#include "stdlib.h"
#include "math.h"

#define  MAX_TABLE_SIZE 100000 //允许开辟的哈希表的最大长度
typedef int ElementType;
typedef int Index; //散列表的地址类型
typedef Index Position;

//表元素状态定义 合法元素 空单元 已删除元素
typedef enum{Legitimate,Empty,Deleted} EntryState;

typedef struct HashEntry Cell;
struct HashEntry{//定义哈希表元素类型
    ElementType Data;
    EntryState Info;
};

typedef struct TableNode* HashTable;
struct TableNode{//定义哈希表结构
    int TableSize;
    Cell* Cells;
};


int NextPrime(int N){
    int i;
    int p=N%2?N+2:N+1;//大于N的下一个奇数
    while (p<MAX_TABLE_SIZE) {
        for (i=(int)sqrt(p); i>=2; i--) {
            if(p%i==0){
                break; //p不是素数
            }
        }
        if(i==2){//如果上面的判断循环正常结束说明p是素数
            break;;
        }else{//如果不是 试探下一个奇数
            p+=2;
        }
    }
    return p;
}


Index Hash(ElementType key,int TableSize){
    return key%TableSize;
}

HashTable CreateHashTable(int TableSize){
    HashTable T;
    int i;
    
    T = (HashTable)malloc(sizeof(struct TableNode));
    T->TableSize=NextPrime(TableSize);
    T->Cells = (Cell*)malloc(sizeof(struct HashEntry));
    for (i=0; i<TableSize; i++) {
        T->Cells[i].Info=Empty;
    }
    return T;
}

Position Find(HashTable T,ElementType key){
    Position CurrentPosition,NewPosition;
    int CNum = 0;
    NewPosition=CurrentPosition=Hash(key,T->TableSize);
    while (T->Cells[NewPosition].Info!=Empty&&
           T->Cells[NewPosition].Info!=key) {
        
        //统计冲突并判断奇偶次数 冲突次数和平方冲突处理的映射
        /**
                    Di             1^2      -1^2        2^2      -2^2         3^2     -3^2
                    CNum       1         2             3          4             5         6
         
         */
        if(++CNum%2){//奇数次冲突 加
            NewPosition=CurrentPosition+(CNum+1)*(CNum+1)/4;//((CNum+1)/2)^2
            NewPosition%=T->TableSize;
        }else{//偶数次冲突 减
            NewPosition=CurrentPosition-(CNum*CNum/4); //(CNum/2)^2
            while (NewPosition<0) {
                NewPosition+=T->TableSize;
            }
        }
    }
    return NewPosition;
}

int Insert(HashTable T,ElementType X){
    Position p;
    p = Find(T, X);
    
    if (T->Cells[p].Info!=Legitimate) {//如果这个位置没有元素
        T->Cells[p].Data=X;
        T->Cells[p].Info=Legitimate;
        return 1;
    }else{
        printf("键值已存在!");
        return 0;
    }
}

