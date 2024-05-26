#ifndef __DYNAMIC_ARRAY_STACK_H_
#define __DYNAMIC_ARRAY_STACK_H_

#include "common.h"


typedef dynamaicArray dynamaicArrayStack;

/* 栈的初始化 */
int dynamaicArrayStackInit(dynamaicArrayStack *pStack);

/* 压栈 */
int dynamaicArrayStackPush(dynamaicArrayStack *pStack, ELEMENTTYPE val);

/* 查看栈顶元素 */
int dynamaicArrayStackTop(dynamaicArrayStack *pStack, ELEMENTTYPE *pVal);

/* 出栈 */
int dynamaicArrayStackPop(dynamaicArrayStack *pStack);

/* 判断栈是否为空 */
int dynamaicArrayStackEmpty(dynamaicArrayStack *pStack);

/* 获取栈的大小 */
int dynamaicArrayGetStackSize(dynamaicArrayStack *pStack, int *pSize);

/* 栈的销毁 */
int dynamaicArrayStackDestroy(dynamaicArrayStack *pStack);

#endif