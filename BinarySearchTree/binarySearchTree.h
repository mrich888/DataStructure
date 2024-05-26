#ifndef __BIANARY_SEARCH_TREE_H
#define __BIANARY_SEARCH_TREE_H

#include"doubleLinkListQueue.h" 
#define ELEMENTTYPE void *

typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left;/* 左子树 */
    struct BSTreeNode *right;/* 右子树 */
    struct BSTreeNode *parent;/* 父结点 */

}BSTreeNode;

typedef struct BinarySearchTree
{
    BSTreeNode *root;/* 根结点 */
    int size;/* 树的结点*/
    int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);/* 钩子函数比较器 ，放到树里面（结构体里面） */
    int(*printFunc)(ELEMENTTYPE val);/* 钩子函数包装器 ，实现自定义打印函数接口 */

}BinarySearchTree;

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree,  int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int(*printFunc)(ELEMENTTYPE val));

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树是否包含指定元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val);
/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree);

/* 获取二叉搜索树的结点个数 */
int binarySearchTreeGetNodeSize(BinarySearchTree *pBstree, int * pSize);

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree,int * pHeight);

/* 二叉搜索树的销毁 */
int binarySearchTreeDestroy(BinarySearchTree *pBstree);

/* 二叉搜索树指定结点的删除 */
int binarySearchTreeDelete(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 判断二叉搜索树是否是完全二叉树 */
int binarySearchTreeComlete(BinarySearchTree *pBstree);

#endif 