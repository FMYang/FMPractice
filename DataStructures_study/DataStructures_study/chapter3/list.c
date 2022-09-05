//
//  list.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/5.
//

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

// 定义链表
typedef struct node {
    int element;
    struct node * next;
} Node;
typedef struct node *List;

List MakeEmpty(List L) {
    L = NULL;
    return L;
}

bool IsEmpty(List L) {
    return L->next == NULL;
}

bool IsLast(Node *p, List L) {
    return p->next == NULL;
}

Node *Find(int x, List L) {
    Node *p = L->next;
    while (p != NULL && p->element != x) {
        p = p->next;
    }
    return p;
}

Node *FindPrevious(int x, List L) {
    Node * p = L;
    while (p->next != NULL && p->next->element != x) {
        p = p->next;
    }
    return p;
}

void Delete(int x, List L) {
    Node *p, *temp;
    p = FindPrevious(x, L);
    if(!IsLast(p, L)) {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

void Insert(int x, List L) {
    if(IsEmpty(L)) return;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->element = x;
    while (L != NULL) {
        L = L->next;
    }
    L->next = newNode;
}

void DeleteList(List L) {
    Node *temp;
    Node *p = L->next;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp->next;
    }
}

Node *Header(List L);
Node *First(List);
Node *Advance(Node *p);
int Retrieve(Node *p);
