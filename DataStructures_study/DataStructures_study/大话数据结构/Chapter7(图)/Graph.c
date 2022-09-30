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

#define MAXVERTEX 9

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

static int DeQueue(LinkQueue *Q, int *e) {
    if(QueueIsEmpty(Q)) return 0;
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

////////////////////////////////////////////////////////
typedef struct Graph {
    char vertex[MAXVERTEX]; // 顶点表
    int edge[MAXVERTEX][MAXVERTEX]; // 邻接矩阵
    int numberOfVertexs; // 顶点数
} Graph;

static void AddEdge(Graph *graph, int from, int to) {
    graph->edge[from][to] = 1;
    graph->edge[to][from] = 1;
}

static void CreateGraph(Graph *graph) {
    graph->numberOfVertexs = 9;
    for(int i=0; i<graph->numberOfVertexs; i++) {
        for(int j=0; j<graph->numberOfVertexs; j++) {
            graph->edge[i][j] = 0;
        }
    }
    
//    graph->vertex[0]='A';
//    graph->vertex[1]='B';
//    graph->vertex[2]='C';
//    graph->vertex[3]='E';
//    graph->vertex[4]='F';
//
//    AddEdge(graph, 0, 1);
//    AddEdge(graph, 0, 2);
//    AddEdge(graph, 1, 3);
//    AddEdge(graph, 2, 4);
//    AddEdge(graph, 3, 4);

    
    graph->vertex[0]='A';
    graph->vertex[1]='B';
    graph->vertex[2]='C';
    graph->vertex[3]='D';
    graph->vertex[4]='E';
    graph->vertex[5]='F';
    graph->vertex[6]='G';
    graph->vertex[7]='H';
    graph->vertex[8]='I';

    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 5);

    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 8);
    AddEdge(graph, 1, 6);

    AddEdge(graph, 2, 3);
    AddEdge(graph, 2, 8);

    AddEdge(graph, 3, 4);
    AddEdge(graph, 3, 7);
    AddEdge(graph, 3, 6);
    AddEdge(graph, 3, 8);

    AddEdge(graph, 4, 5);
    AddEdge(graph, 4, 7);

    AddEdge(graph, 5, 6);

    AddEdge(graph, 6, 7);
}

// 广度优先遍历
void BFSTraversal(Graph graph, int vertex) {
    bool visited[MAXVERTEX] = { false };
        
    // 初始化一个辅助用的队列
    LinkQueue queue;
    Queue_Create(&queue);
    
    // 遍历所有顶点
    for(int i = 0; i < graph.numberOfVertexs; i++) {
        if(!visited[i]) { // 未访问过就处理
            visited[i] = true; // 设置当前顶点访问过
            printf("%c ", graph.vertex[i]);
            EnQueue(&queue, i); // 将此顶点入队列
            
            while (!QueueIsEmpty(&queue)) { // 当前队列不为空
                DeQueue(&queue, &i); // 将队列中的元素出列，赋值给i
                
                for(int j=0; j<graph.numberOfVertexs; j++) {
                    // 判断其他顶点若与当前顶点存在边，并未访问过
                    if(graph.edge[i][j] == 1 && !visited[j]) {
                        visited[j] = true; // 将找到的顶点标记为已访问
                        printf("%c ", graph.vertex[j]);
                        EnQueue(&queue, j); // 将找到的顶点入队列
                    }
                }
            }
        }
    }
    printf("\n");
}

void Graph_Example(void) {
    Graph graph;
    CreateGraph(&graph);
    BFSTraversal(graph, 0);
}
