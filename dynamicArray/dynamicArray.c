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
    INVALID_ACCESS,
};

#define DEFAULT_SIZE 10

/* 静态函数前置声明:静态函数一定要前置声明 */
static int expandDynamicCapacity(dynamaicArray *pArray);
static int shrinkDynamicCapacity(dynamaicArray *pArray);

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
int dynamaicArrayInsertData(dynamaicArray *pArray, ELEMENTTYPE val)
{
    return dynamaicArrayAppointPosInsertData(pArray, pArray->len, val);
}

/* 动态数组扩容 */
static int expandDynamicCapacity(dynamaicArray *pArray)
{
    int ret = 0;
    /* 扩容 */
    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);

    /* 备份指针 */
    ELEMENTTYPE * tmpPtr =pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 把之前的数据全部拷贝过来 */
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    /* 释放以前的内存 避免内存泄漏 */
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    /* 更新动态数组的容量 */
    pArray->capacity = needExpandCapacity;

    return ret;
}

/* 动态数组插入数据，在指定位置 */
int dynamaicArrayAppointPosInsertData(dynamaicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 判断位置的合法性 */
    if(pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 插入之前扩容,扩容前先判断
       数组扩容的临界值是：数组大小的1.5倍 > = 数组容量
    */
    if((pArray->len + (pArray->len >> 1)) >= pArray->capacity)
    {
        
    }
#if 1
    /* 数据后移 留出pos位置插入 */
    for(int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }
#else 
    //应该从后往前赋值
    for (int  idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx + 1] = pArray->data[idx]; 
    }
#endif  

    /* 找到对应的值，写入到数组中 */
    pArray->data[pos] = val;

    /* 数组的大小加一 */
    (pArray->len)++;

    return ON_SUCCESS;

}

/* 动态数组修改指定位置的数据 */
int dynamaicArrayMoidfyAppointPosData(dynamaicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 判断位置的合法性 */
    if(pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 更新位置的数据 */
    pArray->data[pos] = val;

    return ON_SUCCESS;
}

/* 动态数组删除数据（默认情况下删除最后末尾的数据）*/
int dynamaicArrayDeleteData(dynamaicArray *pArray)
{
    dynamaicArrayDeleteAppointPosData(pArray, pArray->len-1);

}

static int shrinkDynamicCapacity(dynamaicArray *pArray)
{
    int needshrinkCapacity = pArray->capacity - (pArray->capacity >> 1);

    /* 备份指针 */
    ELEMENTTYPE * tmpPtr =pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needshrinkCapacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 把之前的数据全部拷贝过来 */
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    /* 释放以前的内存 避免内存泄漏 */
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    /* 更新动态数组的容量 */
    pArray->capacity = needshrinkCapacity;

    return ON_SUCCESS;
}


/* 动态数组删除指定位置的数据 */
int dynamaicArrayAppointPosData(dynamaicArray *pArray, int pos)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    if(pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 缩容 */
    if(pArray->len + (pArray->len >> 1) < pArray)
    {
        shrinkDynamicCapacity(pArray);

    }

    /* 数据前移 */
    for(int idx = pos; idx < pArray->len; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }

    /* 更新数组的大小 */
    (pArray->len)--;
    return ON_SUCCESS;
}

/* 动态数组删除指定的元素 */
int dynamaicArrayDeleteAppointData(dynamaicArray *pArray, ELEMENTTYPE val, int (*comparaFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    /* todo... */
#if 0
    int idx = 0;
    for(idx; idx < pArray->len; idx++)
    {
        if(val == pArray->data[idx])
        {
            dynamaicArrayDeleteAppointPosData(pArray, idx);
            /* 从头开始 */
            idx = 0;
        }
    }
#else
    for(int idx = pArray->len - 1; idx >=0; idx--)
    {
        #if 0
        if(*(int *)val == *(int*)(pArray->data[idx]))
        {
            dynamaicArrayDeleteAppointPosData(pArray, idx);
        }
        #else
        int ret = comareFunc(val, pArray->data[idx]);
        if(ret == 1)
        {
            dynamaicArrayDeleteAppointPosData(pArray, idx);
        }
        #endif
    }
#endif

    return ON_SUCCESS;
}

/* 动态数组的销毁 */
int dynamaicArrayDestroy(dynamaicArray *pArray)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    if(pArray->data != NULL)
    {
        free(pArray->data);
        pArray->data = NULL;
    }

    return ON_SUCCESS;
}

/* 获取数组的大小 */
int dynamaicArrayGetSize(dynamaicArray *pArray, int *pSize)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 解引用 */
    if(pSize != NULL)
    {
        *pSize = pArray->len;
    }
    return pArray->len;
}

/* 获取数组的容量 */
int dynamaicArrayGetCapacity(dynamaicArray *pArray, int *pCapacity)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    if (pCapacity != NULL)
    {
        
    }
    
}

/* 获取指定位置的元素数据 */
int dynamaicArrayGetAppointPosVal(dynamaicArray *pArray, int pos, ELEMENTTYPE *pVal)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    if(pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }

    if(pVal)
    {
        *pVal = pArray->data[pos];
    }
    return ON_SUCCESS;

}

/* 数组排序 */
int dynamaicArrayAppointWaySort(dynamaicArray *pArray, int (*comparaFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    int ret = 0;
    return ret;
}