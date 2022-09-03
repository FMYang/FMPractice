//
//  list.c
//  Learn_C
//
//  Created by yfm on 2022/9/1.
//
//  抽象数据类型 - 链表

#include "list.h"
#include <stdbool.h> /* C99特性      */
#include <stdlib.h>  // 提供 malloc()、free() 的原型

void list_example1(void) {
    // 链表
    struct film {
        char title[40];
        int rating;
        struct film *next;
    };
    
    struct film *head = NULL;
    struct film first = { "film1", 10 };
    struct film second = { "film2", 100 };
    struct film third = { "film3", 1000 };
    first.next = &second;
    second.next = &third;
    third.next = NULL;
    head = &first;
    while (head != NULL) {
        printf("%s %d \n", head->title, head->rating);
        head = head->next;
    }
}

typedef struct node {
    int data;
    struct node *next;
} Node; // typedef将Node作为node结构的类型名
typedef Node * List; // 定义链表，指向结构的指针，结构包含一个指向下个结构的指针

// 初始化链表
void InitializeList(List *plist) {
    *plist = NULL;
}

// 链表是否为空
bool ListIsEmpty(const List plist) {
    if(plist == NULL) {
        return true;
    }
    return false;
}

// 链表是否已满
bool ListIsFull(const List plist) {
    Node *pt;
    bool full = false;
    pt = (Node *)malloc(sizeof(Node));
    if(pt == NULL) {
        full = true;
    }
    return full;
}

// 链表中的项数
unsigned int ListItemCount(List plist) {
    unsigned int count = 0;
    Node *pnode = plist;
    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

// 添加Item
bool AddItem(int data, List *plist) {
    Node *pnew;
    Node *scan = *plist;
    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL) {
        return false;
    }
    pnew->data = data;
    pnew->next = NULL;
    if(scan == NULL) {
        *plist = pnew;
    } else {
        while (scan->next != NULL) {
            scan = scan->next;
        }
        scan->next = pnew;
    }
    return true;
}

// 把函数作用于链表中的每一项
void Traverse(List * plist, void(*pfun)(int data)) {
    Node *pnode = *plist;
    while (pnode != NULL) {
        (*pfun)(pnode->data);
        pnode = pnode->next;
    }
}

// 释放为链表分配的内存
void EmptyTheList(List *plist) {
    Node *psave;
    while (*plist != NULL) {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

void pfun(int data) {
    printf("data = %d\n", data);
}

void reverse(List *list) {
    Node *cur = (*list)->next;
    Node *prev = NULL, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    printf("反转链表：\n");
    while (prev != NULL) {
        printf("data = %d\n", prev->data);
        prev = prev->next;
    }
}

void list_example2(void) {
    List p = NULL; // 初始化链表
//    InitializeList(&p);
    if(ListIsFull(p)) return;
    for(int i=0; i<5; i++) {
        AddItem(i, &p);
    }
    Traverse(&p, pfun);
    reverse(&p);
}

void list_example(void) {
    printf("============= 链表 ==============\n");
//    list_example1();
    list_example2();
    printf("============= End ==============\n\n");
}
