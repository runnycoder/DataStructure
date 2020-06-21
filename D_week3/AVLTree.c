//
//  AVLTree.c
//  D_week3
//
//  Created by runny on 2020/6/21.
//  Copyright © 2020 runny. All rights reserved.
//

#include "AVLTree.h"
Max(Element A,Element B){
    return A>B?A:B;
}
int GetHeight(AVLTree T){
    if(!T){
        return 0;
    }else{
        int LHeight = GetHeight(T->Left);
        int RHeight = GetHeight(T->Right);
        return Max(LHeight, RHeight)+1;
    }
}
//A结点左单旋
AVLTree SingleLeftRotation(AVLTree A){
    //A 必须有一个左结点 左旋更新A与B的高度 返回新的根节点B
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(GetHeight(A->Left),  GetHeight(A->Right))+1;
    B->Height = Max(GetHeight(B->Left),  A->Height)+1;
    return B;
}
//A结点右单旋转
AVLTree SingleRightRotation(AVLTree A){
    //A 必须有一个右结点 右旋更新A与B的高度 返回新的根节点B
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->Height = Max(GetHeight(A->Left),  GetHeight(A->Right))+1;
    B->Height = Max(GetHeight(B->Left),  A->Height)+1;
    return B;
}

//A结点左右双旋
AVLTree DoubbleLeftRightRotation(AVLTree A){
    //A必须有一个左结点B,B必须有一个右结点C
    //将A,B与C做两次单选 返回新的结点C
    
    //将B与C做右单旋转 返回C
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
    
}

//A结点右左双旋
AVLTree DoubbleRightLeftRotation(AVLTree A){
    //A必须有一个右结点B,B必须有一个左结点C
    //将A,B与C做两次单选 返回新的结点C
    
    //将B与C做左单旋转 返回C
    A->Right = SingleLeftRotation(A->Right);
    return SingleLeftRotation(A);
    
}
//平衡二叉树的插入
AVLTree Insert(AVLTree T,Element X){
    if(!T){//空树
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Left = NULL;
        T->Right = NULL;
        T->Height = 0;
    }else if(X<T->Data){
        T->Left = Insert(T, X);
        if(GetHeight(T->Left)-GetHeight(T->Right)==2){//左右高度相差2说明不平衡了
            if(X<T->Left->Data){//如果插入点在T元素左边的左边 说明需要左单旋
                T= SingleRightRotation(T);
            }else{//如果插入点在T元素左边的右边 说明需要左右双旋
                T= DoubbleLeftRightRotation(T);
            }
        }
    }else if(X>T->Data){
        T->Right = Insert(T, X);
        if(GetHeight(T->Left)-GetHeight(T->Right)==-2){
            if(X>T->Right->Data){
                T= SingleRightRotation(T);
            }else{
                T= DoubbleRightLeftRotation(T);
            }
        }
    }//如果相等 则什么都不做 无需插入
        
    //更新树的高度
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right))+1;
    return T;
}

