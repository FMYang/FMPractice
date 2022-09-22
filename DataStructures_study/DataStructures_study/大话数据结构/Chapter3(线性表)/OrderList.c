//
//  OrderList.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/20.
//
//  线性表的顺序存储

#include "OrderList.h"

// 线性表顺序存储结构，就是数组
#define MAXSIZE 20
typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

// 获取线性表第i个元素
static int Order_GetElem(SqList L, int i, int *e) {
    if(L.length == 0 || i < 1 || i > L.length) {
        return 0;
    }
    *e = L.data[i-1];
    return 1;
}

// 在第i个位置插入元素
static int Order_ListInsert(SqList *L, int i, int e) {
    if(L->length == MAXSIZE || i < 1 || i > L->length) {
        return 0;
    }
    if(i < L->length) {
        for(int k = L->length - 1; k >= i-1; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return 1;
}

static int Order_ListDelete(SqList *L, int i, int *e) {
    if(L->length == 0 || i < 1 || i > L->length) {
        return 0;
    }
    *e = L->data[i-1];
    if(i < L->length) {
        for(int k = i; k < L->length; k++) {
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return 1;
}

static void printList(SqList L) {
    for(int i = 0; i<L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

void Order_Example(void) {
    printf("========== 顺序表 ===========\n");
    SqList list = {.data = { 1, 2, 3, 4, 5, 6, 7 }, .length = 7};
    // 1、查
    int result = 0;
    Order_GetElem(list, 2, &result);
    printf("第2个位置的元素为：%d\n", result);
    Order_ListDelete(&list, 2, &result);
    printf("删除2个位置的元素：%d\n", result);
    printf("删除后的List为：\n");
    printList(list);
    printf("在第2个位置插入元素2\n");
    Order_ListInsert(&list, 2, 2);
    printList(list);
    printf("========== End ===========\n\n");
}
