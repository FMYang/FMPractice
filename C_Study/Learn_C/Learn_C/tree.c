//
//  tree.c
//  Learn_C
//
//  Created by yfm on 2022/9/2.
//

#include "tree.h"

typedef struct trnode {
    struct trnode *left;
    struct trnode *right;
    int data;
} TrNode;

typedef struct tree {
    TrNode *root; 
    int size; // 树的项数
} Tree; // Tree 定义为指向 Trnode 的指针类型


void InitializeTree(void);





void tree_example1(void) {
    
}

void tree_example(void) {
    printf("============= 树 ==============\n");
    tree_example1();
    printf("============= End ==============\n\n");
}
