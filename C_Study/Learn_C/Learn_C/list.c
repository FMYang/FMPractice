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

void list_example3(void) {
    List p1 = NULL;
    List p2 = NULL;
    AddItem(3, &p1);
    AddItem(4, &p1);
    AddItem(2, &p1);
    AddItem(4, &p2);
    AddItem(6, &p2);
    AddItem(5, &p2);
    int length1 = 0;
    int length2 = 0;
    Node *tmpp1 = p1;
    Node *tmpp2 = p2;
    while (tmpp1 != NULL) {
        length1++;
        tmpp1 = tmpp1->next;
    }
    while (tmpp2 != NULL) {
        length2++;
        tmpp2 = tmpp2->next;
    }
    int length = length1 > length2 ? length1 : length2;
    int *arr1 = (int *)malloc(length * sizeof(int));
    int *arr2 = (int *)malloc(length * sizeof(int));
    int i = 0;
    while (p1 != NULL) {
        arr1[i] = p1->data;
        arr2[i] = p2->data;
        p1 = p1->next;
        p2 = p2->next;
        i++;
    }
    List p3 = NULL;
    int *arr3 = (int *)malloc(length * sizeof(int));
    int tmp = 0;
    for(int i=length-1; i>=0; i--) {
        int newData = (arr1[i] + arr2[i]) % 10 + tmp;
        tmp = (arr1[i] + arr2[i]) / 10;
        arr3[i] = newData;
    }
    for(int i = length-1; i>=0; i--) {
        AddItem(arr3[i], &p3);
    }
}

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
int length1 = 0;
    int length2 = 0;
    struct ListNode *tmpp1 = l1;
    struct ListNode *tmpp2 = l2;
    while (tmpp1 != NULL) {
        length1++;
        tmpp1 = tmpp1->next;
    }
    while (tmpp2 != NULL) {
        length2++;
        tmpp2 = tmpp2->next;
    }
    int length = length1 > length2 ? length1 : length2;
    int *arr1 = (int *)malloc(length * sizeof(int));
    int *arr2 = (int *)malloc(length * sizeof(int));
    int i = 0;
    while (i<length1) {
        arr1[i] = l1->val;
        l1 = l1->next;
        i++;
    }
    i = 0;
    while (i<length2) {
        arr2[i] = l2->val;
        l2 = l2->next;
        i++;
    }
    struct ListNode *p3 = NULL;
    int *arr3 = (int *)malloc(length * sizeof(int));
    int tmp = 0;
    for(int i=length-1; i>=0; i--) {
        int newData = (arr1[i] + arr2[i]) % 10 + tmp;
        tmp = (arr1[i] + arr2[i]) / 10;
        arr3[i] = newData;
    }
    free(arr1);
    free(arr2);
    for(int i = length-1; i>=0; i--) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = arr3[i];
        newNode->next = NULL;
        printf("%d\n", arr3[i]);
        if(p3 == NULL) {
            p3 = newNode;
        } else {
            while(p3->next != NULL) {
                p3 = p3->next;
            }
            p3->next = newNode;
        }
    }
    while(p3 != NULL) {
        printf("%d\n", p3->val);
        p3 = p3->next;
    }
    free(arr3);
    return p3;
}

void list_example(void) {
    printf("============= 链表 ==============\n");
//    list_example1();
//    list_example2();
    list_example3();
    printf("============= End ==============\n\n");
}
