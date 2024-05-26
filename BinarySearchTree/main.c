#include <stdio.h>
#include "binarySearchTree.h"

/* 测试 */
#define BUFFER_SIZE 2

int compareBasicFunc(void * arg1, void * arg2)
{
    int val1 = *(int * )arg1;
    int val2 = *(int * )arg2;

    return val1 - val2;
}

int printBasicData(void * arg)
{
    int ret = 0;
    int val = *(int * )arg;
    printf("val:%d\n", val);

    return ret;
}

int main()
{
    int ret;
    BinarySearchTree * BST;
    binarySearchTreeInit(&BST, compareBasicFunc, printBasicData);

    int buffer[BUFFER_SIZE] = {56, 28};// 75, 73, 77, 13, 7, 26, 100, 12
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        binarySearchTreeInsert(BST, (void *)&buffer[idx]);
    }
    /* 获取二叉搜索树的结点个数 */
    int size = 0;
    binarySearchTreeGetNodeSize(BST, &size);
    printf("size:%d\n", size);

    /* 获取二叉搜索树的高度*/
    int height = 0;
    binarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n", height);

    /* 中序遍历 */
    // binarySearchTreeInOrderTravel(BST);
    // printf("\n");
    //binarySearchTreePreOrderTravel
    //binarySearchTreePostOrderTravel

    /* 层序遍历 */

    /* 删除 */
    // int delVal = 7;
    // binarySearchTreeDelete(BST, &delVal);

    // /* 获取二叉搜索树的结点个数 */
    // size = 0;
    // binarySearchTreeGetNodeSize(BST, &size);
    // printf("size:%d\n", size);

    return ret;
}