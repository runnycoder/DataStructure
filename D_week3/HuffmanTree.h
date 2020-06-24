//
//  HuffmanTree.h
//  D_week3
//
//  Created by runny on 2020/6/24.
//  Copyright © 2020 runny. All rights reserved.
//  霍夫曼树的构建 WPL带权路径最小的二叉树

#ifndef HuffmanTree_h
#define HuffmanTree_h

#include <stdio.h>

typedef struct TreeNode * HuffmanTree;
struct TreeNode{
    int Weight;
    HuffmanTree Left,Right;
};

#endif /* HuffmanTree_h */
