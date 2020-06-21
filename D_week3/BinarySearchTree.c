//
//  BinarySearchTree.c
//  D_week3
//
//  Created by runny on 2020/6/21.
//  Copyright © 2020 runny. All rights reserved.
//

#include "BinarySearchTree.h"
#include <stdlib.h>
Position FinMin(BinTree BT){
    if(!BT){
        return NULL;
    }else if(BT->left){
        return FinMin(BT);
    }else{
        return BT;
    }
}

//在二叉搜索树合适的位置插入x 最终返回树根
BinTree Insert(BinTree BT,Element X){
    if(!BT){//如果二叉搜索树为空 构建一颗新的树
        BT = (BinTree)malloc(sizeof(struct TreeNode));
        BT->Data=X;
        BT->left=NULL;
        BT->right=NULL;
    }else{
        if(X<BT->Data){//如果元素小于当前结点 递归左子树寻找合适的插入位置
            BT->left = Insert(BT->left, X);
        }else if(X>BT->Data){//如果元素大于当前结点 递归右子树寻找合适的插入位置
            BT->right = Insert(BT->right, X);
        }//如果等于 则什么都不做 返回当前节点
    }
    return BT;
}
//在二叉搜索树中删除X 最终返回树根
BinTree Delete(BinTree BT,Element X){
    Position temp;
    if(!BT){
        printf("要删除的元素找不到!");
    }else{
        if(X<BT->Data){//递归删除左子树
            BT->left = Delete(BT->left, X);
        }else if(X>BT->Data){//递归删除右子树
            BT->right = Delete(BT->right, X);
        }else{
            if(BT->left&&BT->right){//如果当前节点左右子树都在
                //从右子树寻找最小节点填充此位置
                temp = FinMin(BT->right);
                BT->Data = temp->Data;
                BT->right = Delete(BT->right, temp->Data);//删除右子树的最小节点
            }else {
                temp = BT;
                if(!BT->left){//如果有右结点 或者没有子结点
                    BT = BT->left;
                }else if(!BT->right){
                    BT = BT->right
                }
                free(temp);
            }
        }
    }
    return BT;

}
