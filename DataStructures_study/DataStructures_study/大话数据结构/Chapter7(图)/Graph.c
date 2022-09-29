//
//  Graph.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/29.
//
/**
 图的存储结构：
 邻接矩阵、十字矩阵
 邻接表、邻接多重表
 边集数组
 
 比较重要的是邻接矩阵和邻接表，它们分别代表着边集是用数组还是链表的方式的存储。
 
 图的遍历：
 广度优先遍历（Breadth_First_Search），又称广度优先搜索，简称BFS
 深度优先遍历（Depth_First_Search），又称深度优先搜索，简称DFS
 
 BFS常见应用场景：
 网络爬虫
 GPS导航系统
 路径查找
 
 DFS通常用于贪心算法
 DFS常见应用场景：
 在给定图中查找循环（死锁检测）
 在有向图中查找强连通分量
 检查给定的图是否本质上是二分图
 */
#include "Graph.h"
#include <stdlib.h>
#include <stdbool.h>

#define MAXVERTEX 7

////////////////////////////////////////////////////
typedef struct node {
    int data;
    struct node *next;
} QNode;

typedef struct {
    QNode *front; // 头指针，指向头节点
    QNode *rear; // 尾指针
} LinkQueue;

static bool QueueIsEmpty(LinkQueue *Q) {
    return Q->front == Q->rear;
}

static int EnQueue(LinkQueue *Q, int e) {
    QNode *node = malloc(sizeof(QNode));
    if(!node) return 0;
    node->data = e;
    node->next = NULL;
    Q->rear->next = node;
    Q->rear = node;
    return 1;
}

static int DeQueue(LinkQueue *Q) {
    if(QueueIsEmpty(Q)) return 0;
    QNode *p = Q->front->next;
    int e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return e;
}

static void Queue_Create(LinkQueue *Q) {
    QNode *head = malloc(sizeof(QNode));
    Q->front = Q->rear = head;
}

////////////////////////////////////////////////////////
typedef struct Graph {
    int numberOfVertexs; // 顶点数
    int vertex[MAXVERTEX]; // 顶点表
    int edge[MAXVERTEX][MAXVERTEX]; // 邻接矩阵
} Graph;

static void CreateGraph(Graph *graph) {
    for(int i=0; i<MAXVERTEX; i++) {
        graph->vertex[i] = i;
    }
    for(int i=0; i<MAXVERTEX; i++) {
        for(int j=0; j<MAXVERTEX; j++) {
            graph->edge[i][j] = 0;
        }
    }
}

static void AddEdge(Graph *graph, int from, int to) {
    graph->edge[from][to] = 1;
    graph->edge[to][from] = 1;
}

void bfsTraversal(Graph *graph, int vertex) {
    bool visited[MAXVERTEX] = { false };
        
    LinkQueue queue;
    Queue_Create(&queue);
    
    for(int i = vertex; i < MAXVERTEX; i++) {
        if(!visited[i]) {
            visited[i] = true;
            printf("%d ", graph->vertex[i]);
            EnQueue(&queue, i);
            while (!QueueIsEmpty(&queue)) {
                i = DeQueue(&queue);
                
                for(int j=0; j<MAXVERTEX; j++) {
                    if(graph->edge[i][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        printf("%d ", graph->vertex[j]);
                        EnQueue(&queue, j);
                    }
                }
            }
        }
    }
}

void Graph_Example(void) {
//    LinkQueue queue;
//    Queue_Create(&queue);
//    EnQueue(&queue, 1);
//    EnQueue(&queue, 2);
//    printf("出列: ");
//    printf("%d ", DeQueue(&queue));
//    printf("%d ", DeQueue(&queue));
//    printf("%d ", DeQueue(&queue));
//    printf("%d \n", DeQueue(&queue));
    
    Graph graph;
    CreateGraph(&graph);
    AddEdge(&graph, 0, 1);
    AddEdge(&graph, 0, 2);
    AddEdge(&graph, 1, 3);
    AddEdge(&graph, 1, 4);
    AddEdge(&graph, 2, 1);
    AddEdge(&graph, 2, 5);
    AddEdge(&graph, 3, 6);
//
//    //
//    for(int i = 0; i<MAXVERTEX; i++) {
//        for(int j = 0; j<MAXVERTEX; j++) {
//            printf("[%d][%d] = %d ", i, j, graph.edge[i][j]);
//            if(j > 0 && j % (MAXVERTEX - 1) == 0) {
//                printf("\n");
//            }
//        }
//    }
//    printf("\n");
    bfsTraversal(&graph, 1);
}
