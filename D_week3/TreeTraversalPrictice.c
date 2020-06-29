//
//  TreeTraversalPrictice.c
//  D_week3
//
//  Created by runny on 2020/6/29.
//  Copyright © 2020 runny. All rights reserved.
//

#include "TreeTraversalPrictice.h"
#include "main.h"


//给定一颗树的前序 中序数组 求出后序遍历
int pre[6]  =   {1,2,3,4,5,6};
int in[6]   =   {3,2,4,1,6,5};


/// 根据前序和中序求出后序遍历
/// @param preL preL 前序遍历数组左边的最左边的下标
/// @param inL inL 中序遍历数组左边的最左边的下标
/// @param postL postL 后序遍历数组左边的最左边的下标
/// @param n n 待处理元素的个数
/// @param post n post[]存储后续遍历的数组
void solve(int preL,int inL,int postL,int n,int post[]){
    
    //递归基础
    if(n==0){
        return;
    }
    if(n==1){//只剩一个元素 直接放到后序数组中
        post[postL]=pre[preL];
        return;
    }
    
    int root = pre[preL];
    post[postL+n-1] = root;
    int i ;
    for (i=0; i<n; i++) {
        if(in[i]==root){
            break;
        }
    }
    int LNumber=i; int RNumber=n-LNumber-1;
    solve(preL+1, inL, postL , LNumber,post);
    solve(preL+LNumber+1, inL+LNumber+1, postL+LNumber, RNumber,post);
}

int A[10] ={0,1,2,3,4,5,6,7,8,9};

//根据结点数目算出完全二叉树左子树结点的数目
int getLeftCompleteBinaryTreeNumber(int n){
    int L;
    int H = (int)floor(log2(n));//树的高度
    int X =  n+1-(int)pow(2,H);//完全二叉树最后一层元素的个数
    
    int LastHelfNumber = (int)pow(2,H);
    int Lx = X<LastHelfNumber?X:LastHelfNumber;//左子树最后一层的个数 在X和H+1层完美二叉树的一半中取最小值
    L = (int)pow(2, H-1)-1+Lx;
    return L;
}
/// 根据一个从小到大排好序的数组 生成一个新的完全二叉树存储到新的数组中
/// @param ALeft 要处理数组的最左边下标
/// @param ARight 要处理数组的最右边下标
/// @param TRoot 二叉树存储数组当前根结点的下标
/// @param T 二叉树存储数组
//首次调用 Aleft=0 ARight=n-1 TRoot=0;
void BinaryTreeBuild(int ALeft,int ARight,int TRoot,int T[]){
    int n = ARight-ALeft+1;//当前处理数组段元素的个数
    int L;//左子树的数目
    int LTRoot;
    int RTRoot;
    if(n==0){
        return;
    }
    L = getLeftCompleteBinaryTreeNumber(n);//算出n个结点完全二叉树左子树的数目
    T[TRoot]=A[ALeft+L];//根节点元素存入数组T
    //递归根结点左右子树 由于完全二叉树存储是从下标0开始的所以 左子树的根结点不是 2*TRoot 二十 2*TRoot+1
    LTRoot = 2*TRoot+1;
    RTRoot = LTRoot+1;
    BinaryTreeBuild(ALeft, ALeft+L-1, LTRoot, T);
    BinaryTreeBuild(ALeft+L+1, ARight, RTRoot, T);
}
