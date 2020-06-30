//
//  main.c
//  D_week4
//
//  Created by runny on 2020/6/24.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>
//#include "NetCollection.h"
#include "stdlib.h"
#include "GrapShortestPath.h"
//void Initialization(ElementType C[]);

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    ConnectNet();
//    CollectionType C ;
//    C=(CollectionType)malloc(sizeof(ElementType)*100);
//    Initialization(C);
//
//    int n;
//    char in;
//    printf("请输入需要连接电脑的台数!\n");
//    scanf("%d",&n);
//
//
//    do {
//        printf("请输出所要进行的操作!\nI 连接两台电脑\nC 检查输入的两台电脑是否联通 \nS 检查整个网路是否连接完毕,结束程序\n");
//        scanf("%c",&in);
//        scanf("%c",&in);
//
//            switch (in) {
//            case 'I':
//                Input_Connection(C);
//                break;
//            case 'C':
//                Check_Connection(C);
//                break;
//            case 'S':
//                Check_NetWork(C, n);
//                break;
//        }
//    } while (in!='S');
    MGraph Graph = BuildMatrixGraphOrderByInput();
    FindTheBestVertexToOtherVertices(Graph);

    return 0;
}
//void Initialization(ElementType C[]){
//    for (int i = 0; i<100; i++) {
//        C[i]=-1;
//    }
//}

