//
//  BinaryTree.h
//  D_week3
//
//  Created by runny on 2020/6/20.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
typedef struct TreeNode *BinaryTree;
//typedef BinaryTree Position;
struct TreeNode{
    int Data;
    BinaryTree left;
    BinaryTree right;
};
void preOrderTraversal(BinaryTree BT);
void inOrderTraversal(BinaryTree BT);
void postOrderTraversal(BinaryTree BT);

//非递归方式前序遍历二叉树
void levelPreOrderTraversal(BinaryTree BT);

//非递归方式中序遍历二叉树
void levelPreOrderTraversal(BinaryTree BT);

//非递归方式后序遍历二叉树
void levelPostOrderTraversal(BinaryTree BT);

//层序遍历
void LevelorderTraversal ( BinaryTree BT );
#endif /* BinaryTree_h */
