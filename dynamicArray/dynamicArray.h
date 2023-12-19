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
int dynamaicArrayInit(dynamaicArray *pArray);

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

/* 动态数组的销毁 */
int dynamaicArrayDestroy(dynamaicArray *pArray);

/* 获取数组的大小 */
int dynamaicArrayGetSize(dynamaicArray *pArray, int *pSize);

/* 获取数组的容量 */
int dynamaicArrayGetCapacity(dynamaicArray *pArray, int *Capacity);

#endif //__DYNAMIC_ARRAY_H_