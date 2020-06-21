//
//  BinarySearchTree.h
//  D_week3
//
//  Created by runny on 2020/6/21.
//  Copyright © 2020 runny. All rights reserved.
//  二叉搜索树操作

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
typedef struct TreeNode* BinTree;
typedef int Element;
struct TreeNode{
    Element Data;
    BinTree left;
    BinTree right;
};
typedef BinTree Position;
#endif /* BinarySearchTree_h */
