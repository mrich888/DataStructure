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
    
    /* 初始化的时候，尾指针 = 头指针 */
    list->tail = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针*/
    *pList = list;

}

/* 链表头插 */
int LinkListHeadInsert(LinkList * pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int LinkListTailInsert(LinkList * pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, pList->len, val);
}

/* 链表指定位置插 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val)
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

    /* 封装一个结点 */
    LinkNode * newNode = (LinkList *)malloc(sizeof(LinkNode) * 1);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清楚脏数据 */
    memset(newNode, 0, sizeof(LinkNode) * 1);
#if 0
    newNode->data = 0;
    newNode->next = NULL;
#endif
    /* 赋值 */
    newNode->data = val;

#if 1
    /* 头结点和虚拟头结点不一样 */
    /* 从虚拟头结点开始遍历 */
    LinkNode * travelNode = pList->head; /* pList是连接结点的线 */
#else
    LinkNode * travelNode = pList->head->next;
#endif
    /* 这种情况下需要更改尾指针 */
    int flag = 0;
    if(pos == pList->len)
    {
        travelNode = pList->tail;

    }
    else
    {
        while (pos)
        {
        travelNode = travelNode->next;/* 找到想要插入数据的位置 */
        pos--;
        }
    }
    newNode->next = travelNode->next;
    travelNode->next = newNode;

    if(flag)
    {
        pList->tail = newNode;
    }

    
#if 0
    /* 修改结点指向 */
    /* 先断再连，先后再前 */
    newNode->next = travelNode->next; 
    travelNode->next = newNode;
#endif
    /* 更新链表长度 */
    (pList->len)++;

    return ret;
}

/* 链表头删 */
int LinkListHeadDel(LinkList * pList)
{
    /* todo... */
    return LinkListDelAppointPos(pList, 1);
}

/* 链表尾删*/
int LinkListTailDel(LinkList * pList)
{
    return LinkListDelAppointPos(pList, pList->len);
}

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList * pList, int pos)
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

#if 1
    LinkNode * travelNode = pList->head;
#else
    LinkNode * travelNode = pList->head->next;
#endif
    while(--pos)
    {
        /* 向后移动位置 */
        travelNode = travelNode->next;
    }
    //跳出循环找到的是哪一个结点？
    LinkNode * needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;
#if 0
    if(travelNode->next != NULL)
    {
        free(travelNode->next);
        travelNode->next = NULL;
    }
#endif
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

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val)
{

}

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize)
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

    return ret;
}

/* 链表的销毁 */
int LinkListDestory(LinkList * pList)
{

}
/* 链表的遍历 */
int LinkListForeach(LinkList * pList)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
#if 0
    /* travelNode 指向虚拟头结点 */ 
    LinkNode * travelNode = pList->head;
     while (travelNode != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:\n", travelNode->data);
    }
#else
    /* travelNode 指向链表的第一个元素 */
    LinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        printf("travelNode->data:\n", travelNode->data);
        travelNode = travelNode->next;
    }
#endif
    return ret;
}