//
//  PolynomialOperation.c
//  D_week2
//
//  Created by runny on 2020/6/18.
//  Copyright © 2020 runny. All rights reserved.
//

#include "PolynomialOperation.h"
#include "stdlib.h"

//添加新的节点到指定多项式的后面
void Attach(int c,int e,Polynomial *pRear){
    Polynomial p;
    p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->codef=c;
    p->expon=e;
    p->link=NULL;
    //追加结点 并将尾指针指向新节点
    (*pRear)->link=p;//->符号优先级比*要高 所以要加括号
    *pRear=p;
}

int compare(int a,int b){
    if(a>b){
        return 1;
    }else if(a==b){
        return 0;
    }else{
        return -1;
    }
}

Polynomial polyAdd(Polynomial P1,Polynomial P2){
    Polynomial front,rear,temp;
    int codefSum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;
    while(P1&&P2){
        switch (compare(P1->expon, P2->expon)) {//判断当前项指数大小
            case 1://P1>P2
                Attach(P1->codef, P1->expon, &rear);
                P1=P1->link;
                break;
            case -1://P1<P2
                Attach(P2->codef, P2->expon, &rear);
                P2=P2->link;
                break;
            case 0://P1=P2
                codefSum = P1->codef+P2->codef;
                if(codefSum){//系数相加不为零则追加
                    Attach(codefSum, P1->expon, &rear);
                }
                P1=P1->link;
                P2=P2->link;
                break;
        }
    }
        //将剩下的链表追加到求和链表的后面
        if(P1){
            while(P1){
                Attach(P1->codef, P1->expon, &rear);
                P1=P1->link;
            }
        }else{
            while(P2){
                Attach(P2->codef, P2->expon, &rear);
                P2=P2->link;
            }
        }
        //尾节点指向空 front指向多项式的第一项 释放头节点空间
        rear->link = NULL;
        temp = front;
        front = front->link;
        free(temp);
        return front;
}
//暴力式多项式乘法 将P1当前项(cX^e)与p2的每一项相乘然后追加
Polynomial polyMultiplication_Violence(Polynomial P1,Polynomial P2){
    Polynomial p,t1,t2;
    t1= P1;
    t2= P2;
    p=NULL;
    
    //先用p1的一项和p2的每一项相乘构建一个多项式
    while(t1){
        Polynomial temp =(Polynomial)malloc(sizeof(struct PolyNode));
        Polynomial tempP = temp;
        Polynomial lt;
        t2=P2;
        while (t2) {
            Attach(t1->codef*t2->codef, t1->expon+t2->expon, &temp);
            t2=t2->link;
        }
        lt=tempP;
        tempP=tempP->link;
        free(lt);
        p=polyAdd(p, tempP);
        t1=t1->link;
    }
    return p;
}
//插入式多项式乘法 将P1的当前项 * P2的当前项 插入到结果多项式中关键是找到合适的插入位置
Polynomial polyMutiplication_Insert(Polynomial P1,Polynomial P2){
    Polynomial p,rear,t1,t2,temp;
    int c,e;
    if(!P1||!P2){
        return NULL;
    }
    t1 = P1;t2=P2;
    p = (Polynomial)malloc(sizeof(struct PolyNode));
    rear = p;
    while(t2){
        Attach(t1->codef*t2->codef, t1->expon+t2->expon, &rear);
        t2=t2->link;
    }
    t1=t1->link;
    while (t1) {
        t2=P2;rear=p;
        while (t2) {
            c=t1->codef*t2->codef;
            e=t1->expon+t2->expon;
            while(rear->link&&rear->link->expon>e){//寻找插入的位置
                rear = rear->link;
            }
            if(rear->link&&rear->link->expon==e){//如果找到的项指数与插入项相同
                c+=rear->link->codef;
                if(c){//如果相加之后系数为空
                    temp = rear->link;
                    rear->link= temp->link;
                    free(temp);
                }
            }
            //构造节点将当前计算项插入
            temp = (Polynomial)malloc(sizeof(struct PolyNode));
            temp->codef=c;
            temp->expon=e;
            temp->link=rear->link;
            rear->link=temp;
            rear = rear->link;//为什么要将rear移动到temp？ 因为对于当前项t1 * t2(avg) t1,t2都是按从高到低排列的所以 t1(current)*t2(fisrt)的系数是当前循环最大的 后续的都只会在temp的后面
            
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = p;
    p = p->link;
    free(t2);
    return p;
}

Polynomial readPoly(){
    Polynomial p,rear,t;
    int c,e,N;
    printf("构造多项式,多项式指数由高到底排列,请输入多项式的项数!\n");
    scanf("%d",&N);
    p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->link=NULL;
    rear=p;
    while (N--) {//循环读入个项的指数和系数
        printf("请输入此项的系数和指数!\n");
        scanf("%d %d",&c,&e);
        Attach(c, e, &rear);
    }
    //删除临时添加的头节点
    t=p;
    p=p->link;
    free(t);
    return p;
}

void printPoly(Polynomial P){
    while (P) {
        if(P->link!=NULL){
            printf("%dx^%d+",P->codef,P->expon);
        }else{
            printf("%dx^%d",P->codef,P->expon);
        }
        P=P->link;
    }
    printf("\n");
}

