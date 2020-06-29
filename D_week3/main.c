//
//  main.c
//  D_week3
//
//  Created by runny on 2020/6/20.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>
//#include "ArrayList.h"
//#include "ArrayQueue.h"
//#include "BinaryTree.h"
//#include "AVLTree.h"
#include "main.h"


int main(int argc, const char * argv[]) {
// insert code here...
//    BinaryTree BT = (BinaryTree)malloc(sizeof(struct TreeNode));
//    BT->Data = 1;
//
//    BinaryTree BT1 = (BinaryTree)malloc(sizeof(struct TreeNode));
//    BT1->Data = 2;
//    BT1->left = NULL;
//    BT1->right = NULL;
//
//    BinaryTree BT2 = (BinaryTree)malloc(sizeof(struct TreeNode));
//    BT2->Data = 3;
//    BT2->left = NULL;
//    BT2->right = NULL;
//
//    BT->left = BT1;
//    BT->right = BT2;
    
//    preOrderTraversal(BT);
//    printf("\n");
//    inOrderTraversal(BT);
//    printf("\n");
//    postOrderTraversal(BT);
//    printf("\n");
//    levelPreOrderTraversal(BT);
//    printf("\n");
//    levelInOrderTraversal(BT);
//    printf("\n");
//    levelPostOrderTraversal(BT);
//    printf("\n");
    
//    LevelorderTraversal(BT);


//    AVLTree T = NULL;
//    for (int i = 1; i<8; i++) {
//        T = Insert(T, i);
//    }
//    LevelOrderTraversal(T);
//    printf("\n");
//    T = Delete(T, 6);
//    LevelOrderTraversal(T);
//
    int H = (int)floor(log2(10));//树的高度
    int X =  10+1-(int)pow(2,H);//最后一层元素的个数
    int LastHelfNumber = (int)pow(2,H);
    int Lx = X<LastHelfNumber?X:LastHelfNumber;
    int L = (int)pow(2, H-1)-1+Lx;
    printf("Hello, World!%d\n",L);
    
}

