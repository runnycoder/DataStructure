//
//  AVLTree.c
//  D_week3
//
//  Created by runny on 2020/6/21.
//  Copyright © 2020 runny. All rights reserved.
//

#include "AVLTree.h"
#include "stdlib.h"
#include "ArrayQueue.h"
Element Max(Element A,Element B){
    return A>B?A:B;
}
int GetHeight(AVLTree T){
    if(!T){
        return -1;
    }else{
        int LHeight = GetHeight(T->Left);
        int RHeight = GetHeight(T->Right);
        return Max(LHeight, RHeight)+1;
    }
}

AVLTree FindMax(AVLTree T){
    if(!T){
        return NULL;
    }else if(T->Right){
        return FindMax(T->Right);
    }else{
        return T;
    }
}

AVLTree FindMin(AVLTree T){
    if(!T){
        return NULL;
    }else if(T->Left){
        return FindMin(T->Left);
    }else{
        return T;
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
//平衡二叉树的删除操作
/*
 平衡二叉树的删除也分三种情况
 1 要删除的结点没有子树 即为叶子结点
 2 要删除的结点有左右子树 包括根结点
 3 要删除的结点只有一个子结点 左或者右
 */
AVLTree Delete(AVLTree T,Element X){
    AVLTree Temp;
    if(!T){
        printf("要删除的元素不存在!");
    }else{
        if(X<T->Data){//要删除的结点在当前结点左边 则递归其左子树
            T->Left = Delete(T->Left,X);
        }else if(X>T->Data){//要删除的结点在当前结点的右边 则递归其右子树
            T->Right = Delete(T->Right,X);
        }else{
            if(T->Left&&T->Right){//要删除的结点左右子结点都在 两种方式要么寻找其左子树的最大值替换当前结点 要么寻找其右子树的最小值替换当前结点 判断左右子树高度 删除高度较大的一方结点 这样可以保证删除前后都是平衡的
                if(GetHeight(T->Left)>GetHeight(T->Right)){//左子树高 删除左边最大的
                    Temp = FindMax(T->Left);
                    T->Data = Temp->Data;
                    T = Delete(T->Left, Temp->Data);
                }else {//右子树高 删除右边最小的
                    Temp = FindMin(T);
                    T->Data = Temp->Data;
                    T=Delete(T->Right, Temp->Data);
                }
               
                
            }else{
                Temp = T;
                if(!T->Left){//没有子结点或只有右结点
                    T=T->Right;
                }else if(!T->Right){//没有子结点或只有左结点
                    T=T->Left;
                }
                free(Temp);
            }
        }
        return T;
    }
}

void LevelOrderTraversal(AVLTree T){
    AQueue Q = createQueue(10);
    addQueue(Q, T);
    while(T&&!isEmpty(Q)){
        T = deleteQueue(Q);
        printf("%d ",T->Data);
        if(T->Left){
            addQueue(Q, T->Left);
        }
        if(T->Right){
            addQueue(Q, T->Right);
        }
    }
}



