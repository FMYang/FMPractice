//
//  Tree.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/27.
//

#include "Tree.h"
#include <stdlib.h>

// 二叉查找树
typedef struct trNode {
    int val;
    struct trNode *left; // 左节点
    struct trNode *right; // 右节点
} TrNode;

typedef struct Tree {
    TrNode *root; // 根节点
    int size; // 节点数
} Tree;

// 判断树是否包含元素e
static int inTree(TrNode *root, int e) {
    if(root == NULL) return 0;
    if(e == root->val) {
        return 1;
    } else if(e < root->val) {
        inTree(root->left, e);
    } else if(e > root->val) {
        inTree(root->right, e);
    }
    return 0;
}

// 添加新节点
static void addNode(TrNode *root, TrNode *pnew) {
    // 二叉搜索树不允许有重复的元素，如果存在不添加
    if(inTree(root, pnew->val)) return;
    if(pnew->val < root->val) {
        if(root->left == NULL) {
            root->left = pnew;
        } else {
            addNode(root->left, pnew);
        }
    } else {
        if(root->right == NULL) {
            root->right = pnew;
        } else {
            addNode(root->right, pnew);
        }
    }
}

// 添加新元素
static void addTreeItem(Tree *tree, int e) {
    TrNode *pnew = malloc(sizeof(TrNode));
    pnew->val = e;
    if(tree->root == NULL) {
        tree->root = pnew;
    } else {
        addNode(tree->root, pnew);
    }
}

void inorder(TrNode *root) {
    if(root == NULL) return;
    inorder(root->left);
    inorder(root->right);
    printf("%d ", root->val);
}

void Tree_Example(void) {
    Tree t;
    t.root = NULL;
    int arr[5] = {5, 2, 1, 3, 7};
    for(int i=0; i<5; i++) {
        addTreeItem(&t, arr[i]);
    }
    
    inorder(t.root);
    printf("\n");
}
