#include <string.h>
#include "binarySearchTree.h"
#include <stdlib.h>
#include "doubleLinkListQueue.h"

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIN = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 静态函数前置声明 */

/* 两个值比较大小 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
/* 创建结点 */
static BSTreeNode * createNewBstNode(ELEMENTTYPE val, BSTreeNode *parent);
/* 根据指定的值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);
/* 判断二叉搜索树度为2 */
static int binarySearchTreeNodeHasTwochildrens(BSTreeNode * node);
/* 判断二叉搜索树度为1 */
static int binarySearchTreeNodeHasOnechildren(BSTreeNode * node);
/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodeHasIsLeaf(BSTreeNode * node);
/* 前序遍历 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node);
/* 中序遍历 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node);
/* 后序遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node);
/* 获取当前结点的前驱结点 */
static BSTreeNode * bsTreeNodeProDeccessor(BSTreeNode * node);
/* 获取当前结点的后继结点 */
static BSTreeNode * bsTreeNodeProSuccessor(BSTreeNode * node);




/* 两个值比较大小 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
#if 0
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
#endif
}

/* 创建结点 */
static BSTreeNode * createNewBstNode(ELEMENTTYPE val, BSTreeNode *parent)
{
    /* 给新结点分配空间 */
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    /* 结点可空即不放东西 */
    if (newBstNode == NULL)
    {
        return NULL;
    }
    /* 先清除脏数据*/
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    
    /* 再初始化根结点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 然后给新结点赋值 */
    newBstNode->data = val;
    newBstNode->parent = parent;
    return newBstNode;
}

/* 判断二叉搜索树度为2 */
static int binarySearchTreeNodeHasTwochildrens(BSTreeNode * node)
{
    return node->left != NULL && node->right != NULL;
}
/* 判断二叉搜索树度为1 */
static int binarySearchTreeNodeHasOnechildren(BSTreeNode * node)
{
    return ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL));
}
/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodeHasIsLeaf(BSTreeNode * node)
{
    return( node->left == NULL && node->right == NULL);
}

/* 获取当前结点的前驱结点 */
static BSTreeNode * bsTreeNodeProDeccessor(BSTreeNode * node)
{
    if (node ->left != NULL)
    {
        BSTreeNode * travelNode = node->left;
        /* 先判断它的右子树是否为空 */
        while (travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode; 
    }
    /* 程序到这一定没有左子树，那就需要向父结点找 */
    while (node->parent != NULL && node == node->parent->left)
    {
        node = node->parent;
    }
    /* node->parent == null */
    /* node == node->parent->right */
    return node->parent;
}
/* 获取当前结点的后继结点 */
static BSTreeNode * bsTreeNodeProSuccessor(BSTreeNode * node)
{
    if (node->right != NULL)
    {
        BSTreeNode * travelNode = node->right;
        while (travelNode->left != NULL)
        {
            travelNode = travelNode->left;
        }
        return travelNode; 
    }
    /* 程序到这一定没有右子树，那就需要向父结点找 */
    while (node->parent != NULL && node == node->parent->right)
    {
        node = node->parent;
    }
    /* node->parent == null */
    /* node == node->parent->left */
    return node->parent;
}

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

    /* 初始化树（包括钩子函数在这边赋值）*/
    {
        bstree->root = NULL;
        bstree->size = 0;
        bstree->compareFunc =  compareFunc;
        bstree->printFunc =  printFunc;
    }
   
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
    /* 分配根结点（即创建根结点） */
    bstree->root = createNewBstNode(0, NULL);

    /* 根节点不能为空 */
    if(bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }

    *pBstree = bstree;

    return ret;
}

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

    /* 找：不为空，找到对应的父结点为止。 */

    /* travelNode 指向根结点 */
    BSTreeNode * travelNode = pBstree->root;
    BSTreeNode * parentNode = pBstree->root;
    BSTreeNode * newBstNode = createNewBstNode(val, parentNode);
    int cmp = 0;

    while (travelNode != NULL)
    {
        /* 标记父结点 */
        parentNode = travelNode;
        /* 根据符号确定到底放左边还是右边 */
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
   
    /* 挂： */
    if (cmp < 0)
    {
         /* 挂在左子树 */
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
    while (travelNode != NULL)
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

/* 前序遍历 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    pBstree->printFunc(node->data);
    preOrderTravel(pBstree, node->left);
    preOrderTravel(pBstree, node->right);
}
/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    preOrderTravel (pBstree, pBstree->root);
    return ret;
}

/* 中序遍历 */
/* 左子树 根结点 右子树*/
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    inOrderTravel(pBstree, node->left);
    pBstree->printFunc(node->data);
    inOrderTravel(pBstree, node->right);
}
/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    inOrderTravel(pBstree, pBstree->root);
    return ret;
}

/* 后序遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    postOrderTravel(pBstree, node->left);
    postOrderTravel(pBstree, node->right);
    pBstree->printFunc(node->data);
}
/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    postOrderTravel(pBstree, pBstree->root);
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

/* 树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int * pHeight)
{
    int ret = 0;
    /* 判断树是否为空 */
    if (pBstree == NULL)
    {   
        return NULL;
    }
    /* 判断是否有结点 */
    if (pBstree->size == 0)
    {
        return 0;
    }

    /* 树的高度（根节点入队高度为1） */
    int height = 0;
    /* 树每一层的结点数量 */
    int levelSize = 1;
    /* 可以将队列放到树里面初始化 */
    doubleLinkListQueue * queue = NULL;
    doublelinklistQueueInit(&queue);
    
    /* 将根结点入队 */
    doublelinklistQueuePush(queue, pBstree->root);
    BSTreeNode * BstVal = NULL;

    int queueSize = 0;

    while (doublelinklistQueueSize(queue, &queueSize))
    {
        doublelinklistQueueTop(queue, (void *)&BstVal);
        doublelinklistQueuePop(queue);
        levelSize--;
        /* 左子树不为空，入队 */
        if (BstVal->left != NULL)
        {
            doublelinklistQueuePush(queue, BstVal->left);
        }
        /* 右子树不为空，入队 */
        if (BstVal->right != NULL)
        {
            doublelinklistQueuePush(queue, BstVal->right);
        }
        /* 当前层的结点未完全输出时，不会去获取此时队列中的元素长度 */
        /* 树的当前层结点遍历结束 */
        if (levelSize == 0)
        {
            height++; 
            doublelinklistQueueSize(queue, &levelSize);/* */
        }
    }
    /* 释放队列 */
    doublelinklistQueueDestory(queue);
    *pHeight = height;
    return ret;
}

/* 二叉搜索树的销毁 */
int binarySearchTreeDestroy(BinarySearchTree *pBstree)
{
    int ret;
    if(pBstree == NULL)
    {
        return NULL_PTR;
    }
    /* 利用队的思想输出 */
    doubleLinkListQueue *queue = NULL;
    doubleLinkListQueueInit(&queue);
    /* ①先将栈顶元素入队 */
    doubleLinkListQueuePush(queue, pBstree->root);
    /* ②判断 */
    BSTreeNode * travelNode = NULL;
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        /* 用travelnode指向队头的结点*/
        doubleLinkListQueueTop(queue, (void **)&travelNode);
        doubleLinkListQueuePop(queue);
        /* 若有右左结点，先将子结点入队，再释放队头结点 */
        if (travelNode->left != NULL)
        {
            doubleLinkListQueuePush(queue, travelNode->left);
        }
        if (travelNode->right != NULL)
        {
            doubleLinkListQueuePush(queue, travelNode->right);
        }
        /* 结点 */
        if (travelNode)
        {
            free(travelNode);
            travelNode = NULL;
        }
    }

    /* 释放队列 */
    doubleLinkListQueueDestroy(queue);

    /* 释放树 */
    if (pBstree)
    {
        free(pBstree);
        pBstree = NULL;
    }
    
    return ret;
}
