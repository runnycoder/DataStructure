//
//  BinaryIsomorphismTree.h
//  D_week3
//
//  Created by runny on 2020/6/22.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef BinaryIsomorphismTree_h
#define BinaryIsomorphismTree_h

#include <stdio.h>
typedef struct ITreeNode * ITree;
typedef int IElementType;
struct ITreeNode{
    IElementType Data;
    ITree Left;
    ITree Right;
    int flag;//标识符 标识此结点是否被访问过 0-未访问 1-已访问
};
#endif /* BinaryIsomorphismTree_h */
