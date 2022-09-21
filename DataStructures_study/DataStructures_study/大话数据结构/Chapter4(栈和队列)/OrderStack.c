//
//  OrderStack.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/21.
//

#include "OrderStack.h"

// 栈的顺序存储结构，数组实现
#define MAXSIZE 10
typedef struct node {
    int data[MAXSIZE];
    int top;
} SqStack;

static int Push(SqStack *S, int e) {
    if(S->top == MAXSIZE - 1) {
        return 0;
    }
    S->top++;
    S->data[S->top] = e;
    return 1;
}

static int Pop(SqStack *S, int *e) {
    if(S->top == -1) return 0;
    *e = S->data[S->top];
    S->top--;
    return 1;
}

void OrderStack_Example(void) {
    SqStack stack;
    stack.top = -1; // 设置栈顶下标为-1，表示空栈
    Push(&stack, 1); // 入栈
    int result = 0;
    Pop(&stack, &result); // 出栈
    printf("%d出栈 top = %d\n", result, stack.top);
}
