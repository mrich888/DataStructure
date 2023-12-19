#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
};

#define DEFAULT_SIZE 10

/* 动态数组的初始化 */
int dynamaicArrayInit(dynamaicArray *pArray, int capacity)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 避免传入非法值 */
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }

    /* 分配空间 */
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity); 
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清楚脏数据 */
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);

    /* 初始化动态数组的参数属性 */
    pArray->len = 0;
    pArray->capacity = capacity;

    return ON_SUCCESS;
}

/* 动态数组插入数据（默认查到数组的末尾）*/
int dynamaicArrayInsertData(dynamaicArray *pArray, ELEMENTTYPE val);

/* 动态数组插入数据，在指定位置 */
int dynamaicArrayAppointPosInsertData(dynamaicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组修改指定位置的数据 */
int dynamaicArrayMoidfyAppointPosData(dynamaicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组删除数据（默认情况下删除最后末尾的数据）*/
int dynamaicArrayDeleteData(dynamaicArray *pArray);

/* 动态数组删除指定位置的数据 */
int dynamaicArrayMoidfyAppointPosData(dynamaicArray *pArray, int pos);

/* 动态数组删除指定的元素 */
int dynamaicArrayDeleteAppointData(dynamaicArray *pArray, int pos);

/* 动态数组的销毁 */
int dynamaicArrayDestroy(dynamaicArray *pArray);

/* 获取数组的大小 */
int dynamaicArrayGetSize(dynamaicArray *pArray, int *pSize);

/* 获取数组的容量 */
int dynamaicArrayGetCapacity(dynamaicArray *pArray, int *Capacity);
