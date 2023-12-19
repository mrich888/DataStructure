#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_

/* 避免头文件重复包含 */

typedef int ELEMENTTYPE;

typedef struct dynamaicArray
{
    ELEMENTTYPE *data;  /* 数组的空间 */
    int len;            /* 数组的大小 */
    int capacity;       /* 数组的容量 */
}dynamaicArray;

/* API: application program interface. */

/* 动态数组的初始化 */
int dynamaicArrayInit(dynamaicArray *pArray, int capacity);

/* 动态数组插入数据（默认查到数组的末尾）*/
int dynamaicArrayInsertData(dynamaicArray *pArray, ELEMENTTYPE val);

/* 动态数组插入数据，在指定位置 */
int dynamaicArrayAppointPosInsertData(dynamaicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组修改指定位置的数据 */
int dynamaicArrayMoidfyAppointPosData(dynamaicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组删除数据（默认情况下删除最后末尾的数据）*/
int dynamaicArrayDeleteData(dynamaicArray *pArray);

/* 动态数组删除指定位置的数据 */
int dynamaicArrayAppointPosData(dynamaicArray *pArray, int pos);

/* 动态数组删除指定的元素 */
int dynamaicArrayDeleteAppointData(dynamaicArray *pArray, ELEMENTTYPE val, int (*comparaFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 动态数组的销毁 */
int dynamaicArrayDestroy(dynamaicArray *pArray);

/* 获取数组的大小 */
int dynamaicArrayGetSize(dynamaicArray *pArray, int *pSize);

/* 获取数组的容量 */
int dynamaicArrayGetCapacity(dynamaicArray *pArray, int *pCapacity);

/* 获取指定位置的元素数据 */
int dynamaicArrayGetAppointPosVal(dynamaicArray *pArray, int pos, ELEMENTTYPE *pVal);

/* 数组排序 */
int dynamaicArrayAppointWaySort(dynamaicArray *pArray, int (*comparaFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

#endif //__DYNAMIC_ARRAY_H_