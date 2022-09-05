//
//  stack.c
//  Learn_C
//
//  Created by yfm on 2022/9/5.
//
/**
 栈(stack)是链表系列的另一种数据形式。在栈中，只能在链表的一 端添加和删除项，项被“压入”栈和“弹出”栈。因此，栈是一种LIFO(即后进 先出last in,first out)结构。
 */

#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

#define MAXITEMS 5

typedef struct node {
    struct node *next;
    int data;
} Node;

typedef struct stack {
    Node *top;
    int count;
} Stack;

void InitializeStack(Stack *stack) {
    stack->top = NULL;
    stack->count = 0;
}

bool StackIsEmpty(Stack *stack) {
    return stack->count == 0;
}

bool StackIsFull(Stack *stack) {
    return stack->count == MAXITEMS;
}

bool Push(int *pi, Stack *stack) {
    if(StackIsFull(stack)) {
        printf("error stack is full\n");
        return false;
    }
    Node *pnew = (Node *)malloc(sizeof(Node));
    pnew->data = *pi;
    pnew->next = NULL;
    if(StackIsEmpty(stack)) {
        stack->top = pnew;
    } else {
        pnew->next = stack->top;
        stack->top = pnew;
    }
    stack->count++;
    return true;
}

bool Pop(int *pi, Stack *stack) {
    if(StackIsEmpty(stack)) return false;
    Node *temp = stack->top;
    *pi = stack->top->data;
    stack->top = stack->top->next;
    stack->count--;
    free(temp);
    return true;
}

void stack_example1(void) {
    Stack stack;
    InitializeStack(&stack);
    printf("入栈：\n");
    for(int i=0; i<MAXITEMS; i++) {
        if(Push(&i, &stack)) {
            printf("%d enter stack\n", i);
        }
    }
    printf("出栈：\n");
    while (stack.count > 0) {
        int i;
        Pop(&i, &stack);
        printf("%d leave stack\n", i);
    }
}

void stack_example(void) {
    printf("============= 栈 ==============\n");
    stack_example1();
    printf("============= End ==============\n\n");
}

