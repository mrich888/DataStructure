#include <stdio.h>
#include "LinkList.h"
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

/* 链表初始化 */
int LinkListInit(LinkList ** pList)
{
    int ret = 0;
    LinkList *list = (LinkList *)malloc(sizeof(LinkList) * 1);//分配空间
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(LinkList) * 1);

    list->head = (LinkNode *)malloc(sizeof(LinkNode) * 1);/* 头插入需要分配空间（有指针但不一定有值) */
    if(list->head == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清空脏数据 */
    memset(list->head, 0,sizeof(LinkNode) * 1);

    list->head->data = 0;
    list->head->next = NULL;
    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针 */
    *pList =list;

}

/* 链表头插 */
int LinkListHeadInsert(LinkList * pList, ELEMENTTYPE val)
{

}

/* 链表尾插 */
int LinkListTailInsert(LinkList * pList, ELEMENTTYPE val)
{

}

/* 链表指定位置插 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val)
{

}

/* 链表头删 */
int LinkListHeadDel(LinkList * pList)
{

}

/* 链表尾删*/
int LinkListTailDel(LinkList * pList)
{

}

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList * pList, int pos)
{

}

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val)
{

}

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize)
{

}

/* 链表的销毁 */
int LinkListDestory(LinkList * pList)
{

}

int LinkListForeach(LinkList * pList)
{

}