//
//  LinkedHashTable.c
//  D_week6
//
//  Created by runny on 2020/7/5.
//  Copyright © 2020 runny. All rights reserved.
//  链式冲突解决散列表
#include "LinkedHashTable.h"
#include "stdlib.h"
#include "string.h"

#define KEYLENGTH 15 //关键词字符串最大长度
#define MAX_TABLE_SIZE 10000
typedef char ElementType[KEYLENGTH];
typedef int Index;

/**
 单链表定义
 */
typedef struct  LNode* PtrToLNode;
struct LNode{
    ElementType Data;
    PtrToLNode next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/**
 散列定义
 */
typedef struct TNode* HashTable;
struct TNode{
    int TableSize;
    List Heads;
};

int LinkedNextPrime(int N){
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

int LinkedHash(ElementType key,int DataSize){
    int i ;
    unsigned int temp =0;
    for (i=0; i<KEYLENGTH; i++) {
        if(key[i]!='\0'){//位移映射
            temp=(temp<<5)+key[i];
        }
    }
    return temp%DataSize;
}

int MyStrcmp(ElementType A,ElementType B){
    int i;
    int j;
    char SA;
    char SB;
    int flag = 1;
    
    if(A==NULL&&B==NULL){
        return 1;
    }else if(A!=NULL&&B!=NULL){
        i=j=0;
        SA=A[i];
        SB=B[j];
        while(SA!='\0'&&SB!='\0') {//循环判断字符串A和B的每一位是否相等
            if(SA!=SB){
                flag=0;
                break;
            }
            SA = A[++i];
            SB = B[++j];
        }
        if(!flag){//flag=0 不相等
            return 0;
        }else{//flag=1还要判断此时A B字符串是不是都已经到末尾了
            if(SA=='\0'&&SB=='\0'){
                return 1;
            }else{
                return 0;
            }
        }
    }else{
        return 0;
    }
    
        
    
}

HashTable LinkedCreateTable(int TableSize){
    HashTable H;
    int i;
    H = (HashTable)malloc(sizeof(struct TNode));
    H->TableSize=LinkedNextPrime(TableSize);
    H->Heads = (List)malloc(sizeof(struct LNode)*H->TableSize);
    for (i=0; i<H->TableSize; i++) {
        H->Heads[i].Data[0]='\0';
        H->Heads[i].next=NULL;
    }
    return H;
}

Position LinkedFind(HashTable H,ElementType key){
    Position P;
    Index Pos;
    Pos = LinkedHash(key, H->TableSize);
    P = H->Heads[Pos].next;
    while (P&&!MyStrcmp(key, P->Data)) {
        P=P->next;
    }
    return P;//找到指向P的结点或为指向NULL
}

int LinkedInsert(HashTable H,ElementType key){
    Position P,NewLinkCell;
    Index Pos;
    P = LinkedFind(H, key);
    if(!P){//关键词不在链表中 可以插入
        NewLinkCell = (Position)malloc(sizeof(struct LNode));
        strcpy(NewLinkCell->Data, key);
        Pos =LinkedHash(key, H->TableSize);//寻找插入位置
        
        NewLinkCell->next = H->Heads[Pos].next;
        H->Heads[Pos].next = NewLinkCell;
        return 1;
    }else{//找到了关键词 说明已经存在了
        return 0;
    }
}

void DestroyTable(HashTable H){
    int i;
    Position P,Temp;
    for (i=0; i<H->TableSize; i++) {
        P=H->Heads[i].next;
        while (P) {
            Temp = P;
            P=P->next;
            free(Temp);
        }
    }
    free(H->Heads);
    free(H);
}
