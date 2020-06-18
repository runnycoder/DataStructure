//
//  CrossList.c
//  D_week2
//
//  Created by runny on 2020/6/17.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdlib.h>
#include "CrossList.h"

void createCrossList(CrossList *M){
    int row,col,sum,rowNumber,colNumber,value;
    OLNode *p,*q;

    printf("输入M的行数,列数和非零元素的个数!"); /*输入M的行数,列数和非零元素的个数*/
    scanf("%d%d%d", &row,&col,&sum); /*输入M的行数,列数和非零元素的个数*/
    
    //链表头节点初始化
    M->r=row;
    M->c=col;
    M->s=sum;
    if(!(M->rowHead=(OLink*)malloc(sizeof(row*sizeof(OLink))))){
        exit(0);
    }
    if(!(M->colHead=(OLink*)malloc(sizeof(col*sizeof(OLink))))){
        exit(0);
    }
    for (int i = 0; i<=row; i++) {
        M->rowHead[i]=NULL;
    }
    for (int i = 0; i<=col; i++) {
        M->colHead[i]=NULL;
    }
    printf("请输入插入元素行,列,数值,如果数值为0则结束!\n");
    for(
    scanf("%d%d%d", &rowNumber,&colNumber,&value); value!=0; scanf("%d%d%d", &rowNumber,&colNumber,&value))
        {
            if(!(p=(OLNode *)malloc(sizeof(OLNode))))
                exit(0);
            p->row=rowNumber;
            p->col=colNumber;
            p->value=value; /*生成结点*/
            //操作行列指针链接此节点
            if(M->rowHead[rowNumber]==NULL){//如果rowNumebr行为空则插入该结点
                M->rowHead[rowNumber]=p;
                p->right=NULL;
            }else{//否则在rowNumber行寻找插入colNumber列的位置
                for (q=M->rowHead[rowNumber]; q&&q->col<colNumber; q=q->right);
                p->right=q->right;
                q->right=p;
            }
            if(M->colHead[colNumber]==NULL){//如果colNumebr列为空则插入该结点
                M->colHead[colNumber]=p;
                p->down=NULL;
            }else{
                for (q=M->colHead[colNumber]; q&&q->col<rowNumber; q=q->down);
                p->down=q->down;
                q->down=p;
            }
        }
        

}
