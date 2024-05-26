#ifndef __COMMON_H
#define __COMMON_H

#define  ELEMENTTYPE void *

typedef struct dynamaicArray
{
    ELEMENTTYPE *data;  /* 数组的空间 */
    int len;            /* 数组的大小 */
    int capacity;       /* 数组的容量 */
}dynamaicArray;

#endif//__COMMON_H
