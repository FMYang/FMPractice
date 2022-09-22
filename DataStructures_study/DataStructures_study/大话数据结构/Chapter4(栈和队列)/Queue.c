//
//  Queue.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/22.
//
//  队列链式存储结构

#include "Queue.h"
#include <stdlib.h>

// 队列链式存储结构
typedef struct node {
    int data;
    struct node *next;
} QNode;

typedef struct {
    QNode *front; // 头指针，指向头节点
    QNode *rear; // 尾指针
} LinkQueue;

static int EnQueue(LinkQueue *Q, int e) {
    QNode *node = malloc(sizeof(QNode));
    if(!node) return 0;
    node->data = e;
    node->next = NULL;
    Q->rear->next = node;
    Q->rear = node;
    return 1;
}

static int DeQueue(LinkQueue *Q, int *e) {
    if(Q->front == Q->rear) return 0;
    QNode *p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return 1;
}

static void Queue_Create(LinkQueue *Q) {
    QNode *head = malloc(sizeof(QNode));
    Q->front = Q->rear = head;
}

void Queue_Example(void) {
    LinkQueue queue;
    Queue_Create(&queue);
    EnQueue(&queue, 1);
    EnQueue(&queue, 2);
    int r = 0;
    if(DeQueue(&queue, &r)) {
        printf("%d出列\n", r);
    }
    if(DeQueue(&queue, &r)) {
        printf("%d出列\n", r);
    }
    if(!DeQueue(&queue, &r)) {
        printf("队列为空\n");
    }
}
