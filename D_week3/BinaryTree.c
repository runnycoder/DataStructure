//
//  BinaryTree.c
//  D_week3
//
//  Created by runny on 2020/6/20.
//  Copyright © 2020 runny. All rights reserved.
//

#include "ArrayStack.h"
#include "ArrayQueue.h"
//前序二叉树遍历
void preOrderTraversal(BinaryTree BT){
    if(BT){
        printf("%d ",BT->Data);
        preOrderTraversal(BT->left);
        preOrderTraversal(BT->right);
    }
}

//中序二叉树遍历
void inOrderTraversal(BinaryTree BT){
    if(BT){
        preOrderTraversal(BT->left);
        printf("%d ",BT->Data);
        preOrderTraversal(BT->right);
    }
}

//中序二叉树遍历
void postOrderTraversal(BinaryTree BT){
    if(BT){
        preOrderTraversal(BT->left);
        preOrderTraversal(BT->right);
        printf("%d ",BT->Data);
    }
}

//非递归方式前序遍历二叉树
void levelPreOrderTraversal(BinaryTree BT){
    AStack stack = CreateAStack(20);
    while(BT||!AStackIsEmpty(stack)){
        while(BT){
            printf("%d ",BT->Data);
            AStackPush(stack,BT);
            BT = BT->left;
        }
        if(!AStackIsEmpty(stack)){
            BT = AStackPop(stack);
            BT = BT->right;
        }
    }
}

//非递归方式中序遍历二叉树
void levelInOrderTraversal(BinaryTree BT){
    AStack stack = CreateAStack(20);
    while(BT||!AStackIsEmpty(stack)){
        while(BT){
            AStackPush(stack,BT);
            BT = BT->left;
        }
        if(!AStackIsEmpty(stack)){
            BT = AStackPop(stack);
            printf("%d ",BT->Data);
            BT = BT->right;
        }
    }
}
//非递归方式实现后序遍历二叉树 使用两个堆栈 通过Src堆栈访问二叉树 将访问的次序压入Des堆栈
void levelPostOrderTraversal(BinaryTree BT){
    AStack SrcStack = CreateAStack(10);
    AStack DesStack = CreateAStack(10);
    AStackPush(SrcStack, BT);
    while (!AStackIsEmpty(SrcStack)) {
        BinaryTree p = AStackPop(SrcStack);
        AStackPush(DesStack, p);
        if(p->left){
            AStackPush(SrcStack, p->left);
        }
        if(p->right){
            AStackPush(SrcStack, p->right);
        }
    }
    while(!AStackIsEmpty(DesStack)){
        printf("%d ",AStackPop(DesStack)->Data);
    }
}

//层序遍历可用队列实现 此处需要引用之前的队列
void LevelorderTraversal ( BinaryTree BT ){
    AQueue Q = createQueue(10);
    if(!BT){
        return ;
    }
    addQueue(Q,  BT);
    while(!isEmpty(Q)){
        BT = deleteQueue(Q);
        printf("%d",BT->Data);
        if(BT->left){
            addQueue(Q,BT->left);
        }
        if(BT->right){
            addQueue(Q,BT->right);
        }
    }
}
