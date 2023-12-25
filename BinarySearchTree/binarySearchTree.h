#ifndef __BIANARY_SEARCH_TREE_H
#define __BIANARY_SEARCH_TREE_H

#define ELEMENTTYPE int

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

}BinarySearchTree;

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree);

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val);

#endif 