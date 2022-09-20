//
//  OrderList.h
//  DataStructures_study
//
//  Created by yfm on 2022/9/20.
//

#ifndef OrderList_h
#define OrderList_h

#include <stdio.h>

// 线性表顺序存储结构，就是数组
#define MAXSIZE 20
typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

void Order_Example(void);

#endif /* OrderList_h */
