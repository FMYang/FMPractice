//
//  Tree.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/27.
//

#include "Tree.h"
#include <stdlib.h>

typedef struct trNode {
    int val;
    struct trNode *left;
    struct trNode *right;
} TrNode;

typedef struct Tree {
    TrNode *root;
} Tree;

static int inOrder(TrNode *root, int e) {
    if(!root) return 0;
    if(e == root->val) {
        return 1;
    } else if(e < root->val) {
        inOrder(root->left, e);
    } else if(e > root->val) {
        inOrder(root->right, e);
    }
    return 0;
}

static int inTree(TrNode *root, int e) {
    return inOrder(root, e);
}

static void addNode(Tree *tree, int e) {
    TrNode *pnew = malloc(sizeof(TrNode));
    pnew->val = e;
    if(tree->root == NULL) {
        tree->root = pnew;
        return;
    }
    if(inTree(tree->root, e)) return;
    TrNode *root = tree->root;
    while (root) {
        if(e < root->val) {
            if(root->left == NULL) {
                root->left = pnew;
            } else {
                root = root->left;
            }
        } else {
            if(root->right == NULL) {
                root->right = pnew;
            } else {
                root = root->right;
            }
        }
    }
}

void Tree_Example(void) {
    Tree t;
    t.root = NULL;
    addNode(&t, 5);
    addNode(&t, 2);
    addNode(&t, 1);
    addNode(&t, 3);
}
