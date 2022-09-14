//
//  tree.c
//  Learn_C
//
//  Created by yfm on 2022/9/2.
//
//  二叉搜索树，树不许有重复项。二叉查找树是一个有序的二叉树，每个节点包含一个项。
//
//  二叉搜索树满足如下性质：
//  1.左子树所有节点的元素值均小于根的元素值；
//  2.右子树所有节点的元素值均大于根的元素值。
//

#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAXITEM 10

typedef struct trnode {
    struct trnode *left;
    struct trnode *right;
    int data;
} TrNode;

typedef struct tree {
    TrNode *root; 
    int size; // 树的项数
} Tree; // Tree 定义为指向 Trnode 的指针类型

typedef struct pair {
    TrNode *parent;
    TrNode *child;
} Pair;

void InitializeTree(Tree *ptree) {
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree) {
    return ptree->root == NULL;
}

bool TreeIsFull(const Tree *ptree) {
    return ptree->size == MAXITEM;
}

int TreeItemCount(const Tree *ptree) {
    return ptree->size;
}

// 二叉树查找item
static Pair SeekItem(const int *pi, const Tree *ptree) {
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if(look.child == NULL) {
        return look;
    }
    while (look.child != NULL) {
        if(*pi < look.child->data) {
            look.parent = look.child;
            look.child = look.child->left;
        } else if(*pi > look.child->data) {
            look.parent = look.child;
            look.child = look.child->right;
        } else {
            // 找到
            break;
        }
    }
    return look;
}

// 添加节点
static void AddNote(TrNode *newNode, TrNode *root) {
    if(newNode->data < root->data) {
        // 小于根节点的值，添加到左子树
        if(root->left == NULL) {
            root->left = newNode;
        } else {
            AddNote(newNode, root->left); // 递归
        }
    } else if(newNode->data > root->data) {
        // 大于根节点的值，添加到右子树
        if(root->right == NULL) {
            root->right = newNode;
        } else {
            AddNote(newNode, root->right);
        }
    } else {
        printf("error to add node");
        exit(1);
    }
}

// 删除节点
static void DeleteNode(TrNode **ptr) {
    /* ptr 是指向目标节点的父节点指针成员的地址 */
    TrNode *temp;
    if((*ptr)->left == NULL) { // 删除没有左节点的子节点
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if((*ptr)->right == NULL) { // 删除没有右节点的子节点
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else { // 被删除的节点有两个子节点
        for(temp = (*ptr)->left; temp->right != NULL; temp = temp->right) {
            continue;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

bool InTree(const int *data, const Tree *ptree) {
    return (SeekItem(data, ptree).child == NULL) ? false : true;
}

// 添加项
bool AddTreeItem(const int *pi, Tree *ptree) {
    if(TreeIsFull(ptree)) return false;
    if(InTree(pi, ptree)) return false;
    int data = *pi;
    TrNode *newNode = (TrNode *)malloc(sizeof(TrNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if(ptree->root == NULL) { // 树为空
        ptree->root = newNode; // 新节点为根节点
    } else { // 树不为空
        AddNote(newNode, ptree->root); // 在树中添加新节点
    }
    ptree->size++;
    return true;
}

// 删除项
bool DeleteItem(const int *pi, Tree *ptree) {
    Pair look = SeekItem(pi, ptree);
    if(look.child == NULL) { // 空树
        return false;
    }
    if(look.parent == NULL) { // 删除根节点
        DeleteNode(&ptree->root);
    } else if(look.parent->left == look.child) {
        DeleteNode(&look.parent->left);
    } else {
        DeleteNode(&look.parent->right);
    }
    ptree->size--;
    return true;
}


void treepfun(int data) {
    printf("data = %d\n", data);
}

// 遍历树，对每个节点应用一个函数
static void InOrder(const TrNode *root, void(*pfun)(int item)) {
    if(root != NULL) {
//        (*pfun)(root->data); // 1.先序遍历（根左右）
        InOrder(root->left, treepfun);
        (*pfun)(root->data); // 2.中序遍历（左根右）
        InOrder(root->right, pfun);
//        (*pfun)(root->data); // 3.后序遍历（左右根）
    }
}

static void DeleteAllNodes(TrNode *root) {
    TrNode *pright;
    if(root != NULL) {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

void TraverseTree(const Tree * ptree, void(*pfun)(int item)) {
    if(ptree != NULL) {
        InOrder(ptree->root, pfun);
    }
}

void DeleteAll(Tree * ptree) {
    if(ptree != NULL) {
        DeleteAllNodes(ptree->root);
        ptree->root = NULL;
        ptree->size = 0;
    }
}

/**
 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
 
 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
 
 https://leetcode.cn/problems/search-in-a-binary-search-tree
 */
TrNode * searchBST(TrNode* root, int val) {
    if(root == NULL) return NULL;
    if(root->data == val) return root;
    return searchBST(val < root->data ? root->left : root->right , val);
}

void tree_example1(void) {
    Tree tree;
    InitializeTree(&tree);
    int elements[5] = { 4, 2, 1, 3, 7};
    for(int i=0; i<5; i++) {
        AddTreeItem(&elements[i], &tree);
    }
    TraverseTree(&tree, treepfun);
}

// leecode700
void tree_example2(void) {
    Tree tree;
    InitializeTree(&tree);
    int elements[7] = { 4, 2, 1, 3, 7, 5, 8};
    for(int i=0; i<7; i++) {
        AddTreeItem(&elements[i], &tree);
    }
    TraverseTree(&tree, treepfun);
}

void tree_example(void) {
    printf("============= 树 ==============\n");
    tree_example2();
    printf("============= End ==============\n\n");
}
