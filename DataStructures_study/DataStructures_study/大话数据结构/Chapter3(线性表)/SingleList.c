//
//  SingleList.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/20.
//
//  带头节点的单链表

#include "SingleList.h"
#include <stdlib.h>
#include <stdio.h>

// 线性表链式存储结构-单链表
typedef struct node {
    int data;
    struct node *next;
} Node;
typedef Node *LinkList;

// 返回链表中第i个元素的值
int LinkList_GetElem(LinkList L, int i, int *e) {
    int k = 1;
    LinkList p = L->next;
    while (p && k < i) {
        p = p->next;
        k++;
    }
    if(!p || k > i) return 0;
    *e = p->data;
    return 1;
}

// 在链表的第i个位置之前插入元素e
int LinkList_Insert(LinkList *L, int i, int e) {
    int k = 1;
    LinkList p = *L, s;
    while (p && k < i) {
        p = p->next;
        k++;
    }
    if(!p || k > i) return 0;
    s = malloc(sizeof(LinkList));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

// 删除链表的第i个位置的元素，并用e返回其值
int LinkList_delete(LinkList *L, int i, int *e) {
    int k = 1;
    LinkList p = *L, q;
    while (p && k < i-1) {
        p = p->next;
        k++;
    }
    if(!p || k > i) return 0;
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

// 头插法，新节点加载头节点的下一个
void LinkList_CreateHead(LinkList *L, int n) {
    *L = malloc(sizeof(LinkList));
    (*L)->next = NULL;
    LinkList p;
    srand(0);
    for(int i=0; i<n; i++) {
        p = malloc(sizeof(LinkList));
        p->data = random() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p; // 插入表头
    }
}

// 尾插法，新的节点加在最后一个
void LinkList_CreateTail(LinkList *L, int n) {
    *L = malloc(sizeof(LinkList));
    (*L)->next = NULL;
    LinkList p = *L;
    srand(0);
    for(int i=0; i<n; i++) {
        LinkList node = malloc(sizeof(LinkList));
        node->data = random() % 100 + 1;
        node->next = NULL;
        p->next = node;
        p = p->next;
    }
}

// 初始化链表
void LinkList_Create(LinkList *L) {
    // 头节点
    *L = malloc(sizeof(LinkList));
    (*L)->next = NULL;
}

// 将链表L置为空表
int LinkList_Clear(LinkList *L) {
    LinkList p, q;
    p = (*L)->next; // p指向第一个节点
    while (p) {
        q = p->next;
        free(p);
        p = q; // p指向下一个节点
    }
    (*L)->next = NULL; // 头节点指针域为空
    return 1;
}

void LinkList_example(void) {
    printf("========== 单链表 ===========\n");
    LinkList L;
//    LinkList_Create(&L);
//    LinkList_Insert(&L, 1, 1);
//    LinkList_Insert(&L, 2, 2);
//    LinkList_Insert(&L, 3, 3);
//    LinkList_CreateHead(&L, 10);
    LinkList_CreateTail(&L, 10);
    LinkList p = L->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    printf("========== End ===========\n\n");
}
