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
typedef struct AVLNode *AVLTree;
//typedef AVLTree Position;
typedef int ElementType;
struct AVLNode{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};
ElementType Max(ElementType A,ElementType B);
int GetHeight(AVLTree T);
AVLTree FindMax(AVLTree T);
AVLTree FindMin(AVLTree T);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubbleLeftRightRotation(AVLTree A);
AVLTree DoubbleRightLeftRotation(AVLTree A);
AVLTree Insert(AVLTree T,ElementType X);
AVLTree Delete(AVLTree T,ElementType X);
#endif /* AVLTree_h */
