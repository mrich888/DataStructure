#include <stdio.h>
#include "binarySearchTree.h"
#include <stdlib.h>
#include "doubleLinkListQueue.h"
#include "doubleLinkList.h"

enum STATUS_CODE
{
    NOT_FIN = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 静态函数前置声明 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

/* 创建结点 */
static BSTreeNode * createNewBstNode(ELEMENTTYPE val, BSTreeNode *parent);

/* 根据指定的值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree,  int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int(*printFunc)(ELEMENTTYPE val))
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
    /* 钩子函数在这边赋值 */
    bstree->compareFunc =  compareFunc;
    
    bstree->printFunc =  printFunc;

#if 0
    /* 有指针的一定要分配空间，在这里先分配空间 */
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
    
    /* 初始化根结点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
#endif   
    /* 分配根结点 */
    bstree->root = createNewBstNode(0, NULL);
    if(bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    *pBstree = bstree;

    return ret;
}

/* 封装结点 */
static BSTreeNode * createNewBstNode(ELEMENTTYPE val, BSTreeNode *parent)
{
    /* 封装新结点 */
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    
    if (newBstNode == NULL)
    {
        return NULL;
    }
    /* 清除脏数据*/
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    
    /* 初始化根结点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 新结点赋值 */
    newBstNode->data = val;
    newBstNode->parent = parent;
    return newBstNode;
}

#if 0
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    #if 0
    if (val1 < val2)
    {
        return -1;
    }
    else if (val1 > val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    #else
    return val1 - val2;
    #endif
}
#endif


/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;
    /* 如果是空树，直接插入 */
    if (pBstree->size == 0)
    {
        /* 更新数的结点 */
        (pBstree->size)++;

        pBstree->root->data = val;
        return ret;
    }

    /* 不为空，找到对应的父结点为止。即遍历指针停在差啊 */
    /* travelNode 指向根结点 */
    BSTreeNode * travelNode = pBstree->root;
    BSTreeNode * parentNode = pBstree->root;

    /* 根据符号确定到底放左边还是右边 */
    int cmp = 0;
    while (travelNode->data != NULL)
    {
        /* 标记父结点 */
        parentNode = travelNode;
        cmp = pBstree->compareFunc(val, travelNode->data);
        /* 插入元素 < 遍历到的结点 travleNode往左遍历 */
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        /* 插入元素 > 遍历到的结点 travleNode往左遍历 */
        else if (cmp > 0)
        {  
            travelNode = travelNode->right;
        }
        else
        {
            /* 插入元素 = 遍历到的结点 */
            return ret;//按需求返回还是插入
        }
    }
    /* 新结点 */
    BSTreeNode * newBstNode = createNewBstNode(val, parentNode);
    
    /* 挂在左子树 */
    if (cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else
    {
        /*挂在右子树 */
        parentNode->right = newBstNode;
    }
#if 0 
    /* 新结点的parent指针赋值，在函数里直接赋值了 */
    newBstNode->parent = parentNode;
#endif
    /* 更新树的结点 */
    (pBstree->size)++;    
    return ret;
}

/* 根据指定的值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    BSTreeNode * travelNode = pBstree->root;
    int cmp = 0;
    while (travelNode->data != NULL)
    {
        cmp = pBstree->compareFunc(val, travelNode->data);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {  
            travelNode = travelNode->right;
        }
        else
        {
            /* 找到了 */
            return travelNode;
        }
    }
    return NULL;
}


/* 二叉搜索树是否包含指定元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    

    return ret;
}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    
    return ret;
}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    
    return ret;
}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    /* 定义一个队列并初始化 */
    doubleLinkListQueue * queue = NULL;
    doubleLinkListQueueInit(&queue);

    /* 1.根结点入队 */
    doubleLinkListQueuePush(queue, pBstree->root);
    /* 2.判断队列是否为空 */
    BSTreeNode * nodeVal = NULL;
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        /* */
        doubleLinkListQueueTop(queue, (void **)&nodeVal);
        #if 0
        printf("data:%d\n", nodeVal->data);
        #else
        pBstree->printFunc(nodeVal->data);
        #endif
        doubleLinkListQueuePop(queue);

        /* 将左子树入队 */
        if (nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(queue, nodeVal->left);
        }

        /* 将右子树入队 */
        if (nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(queue, nodeVal->right);
        }
    }
    /* 释放队列 */
    doubleLinkListDestory(queue);

    return ret;
}