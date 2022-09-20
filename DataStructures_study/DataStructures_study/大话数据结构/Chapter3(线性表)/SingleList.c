//
//  SingleList.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/20.
//

#include "SingleList.h"
#include <stdlib.h>

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
