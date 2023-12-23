#include <stdio.h>
#include "circleDoubleLinkList.h"
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};
/* 静态前置声明 */
/* 静态函数只在本源文件（.c）使用 */
static int CircleDoubleLinkListAccordAppointValGetPos(CircleDoubleLinkList * pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE , ELEMENTTYPE ));
/* 封装新结点成函数,静态函数前置 */
static CircleDoubleLinkNode * createCircleDoubleLinkNode (ELEMENTTYPE val);

/* 链表初始化 */
int CircleDoubleLinkListInit(CircleDoubleLinkList ** pList)
{
    int ret = 0;
    CircleDoubleLinkList *list = (CircleDoubleLinkList *)malloc(sizeof(CircleDoubleLinkList) * 1);//给链表分配空间
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(CircleDoubleLinkList) * 1);

    list->head = (CircleDoubleLinkNode *)malloc(sizeof(CircleDoubleLinkNode) * 1);/* 头结点需要分配空间（有指针但不一定有值) */
    if(list->head == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清空脏数据 */
    memset(list->head, 0,sizeof(CircleDoubleLinkNode) * 1);
    /* 初始化 */
    list->head->data = 0;
    list->head->next = list->head;

    /* 虚拟头结点的prev置空 */
    list->head->prev = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针*/
    *pList = list;

}

/* 链表头插 */
int CircleDoubleLinkListHeadInsert(CircleDoubleLinkList * pList, ELEMENTTYPE val)
{
    return CircleDoubleLinkListAppointPosInsert(pList, 0, val);
}

static CircleDoubleLinkNode * createCircleDoubleLinkNode (ELEMENTTYPE val)
{
    /* 封装一个结点 */
    CircleDoubleLinkNode * newNode = (CircleDoubleLinkNode *)malloc(sizeof(CircleDoubleLinkNode) * 1);
    if(newNode == NULL)
    {
        return NULL;
    }

    /* 清楚脏数据 */
    memset(newNode, 0, sizeof(CircleDoubleLinkNode) * 1);
#if 1
    newNode->data = 0;
    newNode->next = NULL;
    newNode->prev = NULL;
#endif
    /* 赋值 */
    newNode->data = val;

    /* 返回新结点 */
    return newNode;
}

/* 链表指定位置插 */
int CircleDoubleLinkListAppointPosInsert(CircleDoubleLinkList * pList, int pos, ELEMENTTYPE val)
{
    int ret;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    if(pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 新建新结点，封装成函数 */
    CircleDoubleLinkNode * newNode = createCircleDoubleLinkNode(val);


    /* 头结点和虚拟头结点不一样 */
    /* 从虚拟头结点开始遍历 */
    CircleDoubleLinkNode * travelNode = pList->head;
    if(pos == pList->len)
    {
        travelNode = pList->head;   
    }
    else
    {
        while (pos)
        {
            travelNode = travelNode->next;/* 找到想要插入数据的位置 */
            pos--;
        }
    }

    travelNode->prev->next = newNode;
    newNode->prev = travelNode->prev;
    travelNode->prev = newNode;
    newNode->next = travelNode;

    /* 更新链表长度 */
    (pList->len)++;

    return ret;
}

/* 链表头删 */
int CircleDoubleLinkListHeadDel(CircleDoubleLinkList * pList)
{
    return CircleDoubleLinkListDelAppointPos(pList, 1);
}

/* 链表指定位置删除 */
int CircleDoubleLinkListDelAppointPos(CircleDoubleLinkList * pList, int pos)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    /* 临界值：你必须要有数据才能删，故pos必须得大于0 */
    if(pos <= 0 || pos > pList->len ) 
    {
        return INVALID_ACCESS;
    }

    CircleDoubleLinkNode * travelNode = pList->head;
    CircleDoubleLinkNode * needDelNode = NULL;
  
    if(pos == pList->len)
    {
        travelNode = pList->head;
        needDelNode =travelNode->prev;

        needDelNode->prev->next = travelNode;
        travelNode->prev = needDelNode->prev;
        
    }
    else
    {
         while(--pos)
        {
        /* 向后移动位置 */
            travelNode = travelNode->next;
        }
        //跳出循环找到的是哪一个结点？
        needDelNode = travelNode->next;

        travelNode->next = needDelNode->next;
        needDelNode->next->prev = travelNode;
    }
   
  
    /* 释放内存 */
    if(needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    /* 链表长度减一 */
    (pList->len)--;
    return ret;

}

/* 根据指定位置的元素得到再链表中所在的位置 */
static int CircleDoubleLinkListAccordAppointValGetPos(CircleDoubleLinkList * pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE , ELEMENTTYPE ))
{
    /* 静态函数只给本源文件的函数用，不需要判断合法性 */
    
#if 0
    CircleDoubleLinkNode * travelNode = pList->head;
#else
    int pos = 1;
    CircleDoubleLinkNode * travelNode = pList->head->next;
#endif
    int cmp = 0;
    while (travelNode != pList->head)
    {
        cmp = compareFunc(val, travelNode->data);
        if(cmp == 1)
        {
            *pPos = pos; 
            return pos;
        }
        travelNode = travelNode->next;
        pos++;
    }
    *pPos = NOT_FIND;
    return NOT_FIND;
}

/* 链表删除指定数据 */
int CircleDoubleLinkListDelAppointData(CircleDoubleLinkList * pList, ELEMENTTYPE val,int (*compareFunc)(ELEMENTTYPE , ELEMENTTYPE ) )
{

    int ret = 0;
#if 1
    /* 找到要删除的值的位置，就可以复用删除指定位置的函数 */

    int pos =0;
    /* 链表的长度 */
    int size = 0;

    /* 需要遍历链表全部去找 */
    /* 但可能存在 不只一个满足条件的值 // 没有满足条件的值 */
    while (CircleDoubleLinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        CircleDoubleLinkListAccordAppointValGetPos(pList, val, &pos, compareFunc);
        CircleDoubleLinkListDelAppointPos(pList, pos);
    }
#endif
    return ret;
}

/* 获取链表的长度 */
int CircleDoubleLinkListGetLength(CircleDoubleLinkList * pList, int *pSize)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    if(pSize)
    {
        *pSize = pList->len;
    }
    /* 返回链表的长度 */
    return pList->len;
}

/* 链表的销毁 */
int CircleDoubleLinkListDestory(CircleDoubleLinkList * pList)
{
    int ret = 0;
    /* 代码复用 ：使用头删删除结点 */
    int size = 0;
    /* 非零即正，则可以进入循环 */
    while (CircleDoubleLinkListGetLength(pList, &size))
    {
        CircleDoubleLinkListHeadDel(pList);
    }

    if(pList->head->next != pList->head)
    {
        free(pList->head );
        pList->head = NULL;
    }
    return ret;
}
/* 链表的遍历 */
int CircleDoubleLinkListForeach(CircleDoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE))
{

    /*int (*printfFunc)(ELEMENTTYPE) 是形参，它的实参是printStruct */ 
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

#if 1
    /* travelNode 指向链表的第一个元素 */
    CircleDoubleLinkNode * travelNode = pList->head->next;
#else
    /* travelNode 指向链表的最后一个元素 */
    CircleDoubleLinkNode * travelNode = pList->tail;

#endif

    while (travelNode != pList->head)
    {
       
        /* 包装器   钩子  回调函数 */
        printFunc(travelNode->data);
        travelNode = travelNode->next;
    }

    return ret;
}

int CircleDoubleLinkListBackForeach(CircleDoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE))
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    /* travelNode 指向链表的最后一个元素 */
    CircleDoubleLinkNode * travelNode = pList->head->prev;

    /* 结束条件为头指针和尾指针相同 而不是指向的结点为空 */
    /* 头指针指向的是头结点（虚拟头结点）而不是首元结点。*/
    while (travelNode != pList->head)
    {

        /* 包装器   钩子  回调函数 */
        printFunc(travelNode->data);

        travelNode = travelNode->prev;
    }
    return ret;
}
