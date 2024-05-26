#include <stdio.h>
#include "balanceBinarySearchTree.h"

/* 测试 */
#define BUFFER_SIZE 3

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
    BalanceBinarySearchTree * AVL;
    binarySearchTreeInit(&AVL, compareBasicFunc, printBasicData);

    int buffer[BUFFER_SIZE] = {56, 28, 75};// 75, 73, 77, 13, 7, 26, 100, 12
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
       balanceBinarySearchTreeInsert(AVL, (void *)&buffer[idx]);
    }
    /* 获取二叉搜索树的结点个数 */
    int size = 0;
    balanceBinarySearchTreeGetNodeSize(AVL, &size);
    printf("size:%d\n", size);

    /* 获取二叉搜索树的高度*/
    int height = 0;
    balanceBinarySearchTreeGetHeight(AVL, &height);
    printf("height:%d\n", height);
}