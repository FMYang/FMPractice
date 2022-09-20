//
//  SingleList.h
//  DataStructures_study
//
//  Created by yfm on 2022/9/20.
//

#ifndef SingleList_h
#define SingleList_h

#include <stdio.h>

// 线性表链式存储结构-单链表
typedef struct node {
    int data;
    struct node *next;
} Node;
typedef Node *LinkList;

#endif /* SingleList_h */
