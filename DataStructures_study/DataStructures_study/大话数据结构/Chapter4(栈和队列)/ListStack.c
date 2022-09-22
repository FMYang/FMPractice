//
//  ListStack.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/21.
//
//  栈的链式存储结构


#include "ListStack.h"
#include <stdlib.h>

// 栈的链式存储结构
typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct LinkStack {
    Node *top;
    int count;
} LinkStack;

static int Push(LinkStack *S, int e) {
    Node *s = malloc(sizeof(Node));
    if(!s) return 0; // 空间不够
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return 1;
}

static int Pop(LinkStack *S, int *e) {
    if(S->count == 0) return 0;
    *e = S->top->data;
    Node *p = S->top;
    S->top = S->top->next;
    S->count--;
    free(p);
    return 1;
}

void LinkStack_Example(void) {
    LinkStack stack;
    Push(&stack, 1);
    Push(&stack, 2);
    int e = 0;
    Pop(&stack, &e);
    printf("%d出栈 count = %d\n", e, stack.count);
}
