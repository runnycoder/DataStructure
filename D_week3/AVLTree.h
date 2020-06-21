//
//  AVLTree.h
//  D_week3
//
//  Created by runny on 2020/6/21.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include <stdio.h>
typedef struct AVLNode *Position;
typedef Position AVLTree;
typedef int Element;
struct AVLNode{
    Element Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};
#endif /* AVLTree_h */
