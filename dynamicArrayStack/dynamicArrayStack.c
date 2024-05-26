#include "dynamicArrayStack.h"
#include "dynamicArray.h"

#define DEFAULT_SIZE 10

/* 栈的初始化 */
int dynamaicArrayStackInit(dynamaicArrayStack *pStack)
{
    return dynamaicArrayInit(pStack, DEFAULT_SIZE);
}

/* 压栈 */
int dynamaicArrayStackPush(dynamaicArrayStack *pStack, ELEMENTTYPE val)
{
    /* 调用动态数组的尾插 */
    return dynamaicArrayInsertData(pStack, val);
}

/* 查看栈顶元素 */
int dynamaicArrayStackTop(dynamaicArrayStack *pStack, ELEMENTTYPE *pVal)
{
    /* 获取指定位置元素（数组的最后位置）*/
    return dynamaicArrayGetAppointPosVal(pStack, pStack->len - 1, pVal);
}

/* 出栈 */
int dynamaicArrayStackPop(dynamaicArrayStack *pStack)
{
    return dynamaicArrayDeleteData(pStack);
}

/* 判断栈是否为空 */
int dynamaicArrayStackEmpty(dynamaicArrayStack *pStack)
{
    int size = 0; 
    dynamaicArrayGetSize(pStack, &size);
    return size == 0 ? 1 : 0;
}

/* 获取栈的大小 */
int dynamaicArrayGetStackSize(dynamaicArrayStack *pStack, int *pSize)
{
#if 1
    return dynamaicArrayGetSize(pStack, pSize);
#else
    dynamaicArrayGetSize(pStack, pSize);
    if(pSize)
    {
        return *pSize;
    }
#endif
}

/* 栈的销毁 */
int dynamaicArrayStackDestroy(dynamaicArrayStack *pStack)
{
    return dynamaicArrayDestroy(pStack);
}

