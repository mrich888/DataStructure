#include <stdio.h>
#include "binarySearchTree.h"
#include <stdlib.h>

enum STATUS_CODE
{
    NOT_FIN = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree)
{
    int ret = 0;
    BinarySearchTree * bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    
    /* 清楚脏数据 */
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);

    /* 初始化树 */
    bstree->root = NULL;
    bstree->size = 0;

    /* 有指针的一定要分配空间，在这里先分配空间 */
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
    
    /* 初始化根结点 */
    bstree->root->data = 0;
    bstree->root->left = NULL;
    bstree->root->right = NULL;
    bstree->root->parent = NULL;

    *pBstree = bstree;

    return ret;
}

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree **pBstree, ELEMENTTYPE val)
{
    int ret = 0;
    return ret;
}