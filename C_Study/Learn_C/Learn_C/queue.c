//
//  queue.c
//  Learn_C
//
//  Created by yfm on 2022/9/2.
//
//  抽象数据类型 - 队列

#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAXQUEUE 5

// 文件作用域
typedef int Item;
typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct queue {
    Node *front; // 头节点
    Node *rear; // 尾节点
    int items; // 数量
} Queue;

// 初始化队列
void InitializeQueue(Queue *pq) {
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsEmpty(const Queue *pq) {
    return pq->items == 0;
}

bool QueueIsFull(const Queue *pq) {
    return pq->items == MAXQUEUE;
}

int QueueItemCount(const Queue *pq) {
    return pq->items;
}

bool EnQueue(Item item, Queue *pq) {
    if(QueueIsFull(pq)) return false;
    Node *pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL) {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    pnew->item = item;
    pnew->next = NULL;
    if(QueueIsEmpty(pq)) {
        pq->front = pnew;
    } else {
        pq->rear->next = pnew;
    }
    pq->rear = pnew;
    pq->items++;
    return true;
}

// 出列注意释放内存
bool DeQueue(Item *pitem, Queue *pq) {
    if(QueueIsEmpty(pq)) return false;
    Node *pt = pq->front;
    *pitem = pt->item;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if(pq->items == 0) {
        pq->rear = NULL;
    }
    return true;
}

void EmptyQueue(Queue *pq) {
    Item i;
    while (!QueueIsEmpty(pq)) {
        DeQueue(&i, pq);
    }
}

void queue_example1(void) {
    Queue queue;
    InitializeQueue(&queue);
    for(int i = 0; i<5; i++) {
        EnQueue(i, &queue);
    }
    int dequeueItem;
    DeQueue(&dequeueItem, &queue);
    printf("%d dequeue\n", dequeueItem);
    Node *scan = queue.front;
    while (scan != NULL) {
        printf("%d\n", scan->item);
        scan = scan->next;
    }
    EmptyQueue(&queue);
}

void queue_example(void) {
    printf("============= 队列 ==============\n");
    queue_example1();
    printf("============= End ==============\n\n");
}
