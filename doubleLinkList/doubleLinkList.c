#include <stdio.h>
#include "doubleLinkList.h"
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    NOT_FIN,
};
/* 静态前置声明 */
/* 静态函数只在本源文件（.c）使用 */
static int DoubleLinkListAccordAppointValGetPos(DoubleLinkList * pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE , ELEMENTTYPE ));
/* 封装新结点成函数 */
static doubleLinkNode * createDoubleLinNode (ELEMENTTYPE val);

/* 链表初始化 */
int DoubleLinkListInit(DoubleLinkList ** pList)
{
    int ret = 0;
    DoubleLinkList *list = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);//给链表分配空间
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(DoubleLinkList) * 1);

    list->head = (doubleLinkNode *)malloc(sizeof(doubleLinkNode) * 1);/* 头结点需要分配空间（有指针但不一定有值) */
    if(list->head == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清空脏数据 */
    memset(list->head, 0,sizeof(doubleLinkNode) * 1);
    /* 初始化 */
    list->head->data = 0;
    list->head->next = NULL;

    /* 虚拟头结点的prev之唯恐 */
    list->head->prev = NULL;
    
    /* 初始化的时候，尾指针 = 头指针 */
    list->tail = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针*/
    *pList = list;

}

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList * pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList * pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, pList->len, val);
}

static doubleLinkNode * createDoubleLinNode (ELEMENTTYPE val)
{
    /* 封装一个结点 */
    doubleLinkNode * newNode = (doubleLinkNode *)malloc(sizeof(doubleLinkNode) * 1);
    if(newNode == NULL)
    {
        return NULL_PTR;
    }

    /* 清楚脏数据 */
    memset(newNode, 0, sizeof(doubleLinkNode) * 1);
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
int DoubleLinkListAppointPosInsert(DoubleLinkList * pList, int pos, ELEMENTTYPE val)
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
    doubleLinkNode * newNode = createDoubleLinNode(val);

#if 0  
    /* 封装一个结点 */
    doubleLinkNode * newNode = (doubleLinkNode *)malloc(sizeof(doubleLinkNode) * 1);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清楚脏数据 */
    memset(newNode, 0, sizeof(doubleLinkNode) * 1);
#if 0
    newNode->data = 0;
    newNode->next = NULL;
#endif
    /* 赋值 */
    newNode->data = val;
#endif 

#if 1
    /* 头结点和虚拟头结点不一样 */
    /* 从虚拟头结点开始遍历 */
    doubleLinkNode * travelNode = pList->head;
#else
    doubleLinkNode * travelNode = pList->head->next;
#endif
    /* 这种情况下需要更改尾指针 */
    int flag = 0;
    if(pos == pList->len)
    {
        travelNode = pList->tail;
        flag = 1;
    }
    else
    {
        while (pos)
        {
            travelNode = travelNode->next;/* 找到想要插入数据的位置 */
            pos--;
        }
        travelNode->next->prev = travelNode;//3  /* 空链表或者尾插入不能实现 */
    }
    
    newNode->next = travelNode->next;//1
    newNode->prev = travelNode;//2
    travelNode->next = newNode;//4

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
int DoubleLinkListHeadDel(DoubleLinkList * pList)
{
    /* todo... */
    return DoubleLinkListDelAppointPos(pList, 1);
}

/* 链表尾删*/
int DoubleLinkListTailDel(DoubleLinkList * pList)
{
    return DoubleLinkListDelAppointPos(pList, pList->len);
}

/* 链表指定位置删除 */
int DoubleLinkListDelAppointPos(DoubleLinkList * pList, int pos)
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
    doubleLinkNode * travelNode = pList->head;
#else
    doubleLinkNode * travelNode = pList->head->next;
#endif
    doubleLinkNode * needDelNode = NULL;

    /* 尾指针需要移动 */
    if(pos == pList->len)
    {   
        /* 尾指针需要移动 */
        doubleLinkNode * temNode = pList->tail;
        pList->tail = pList->tail->prev;
        needDelNode = temNode;
#if 0
        free(temNode)
        if(temNode != NULL)
        {
            temNode = NULL;
        }

#endif      
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
        needDelNode->next->prev = travelNode;/* 尾删不可以 */
    }  
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

/* 根据指定位置的元素得到再链表中所在的位置 */
static int DoubleLinkListAccordAppointValGetPos(DoubleLinkList * pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE , ELEMENTTYPE ))
{
    /* 静态函数只给本源文件的函数用，不需要判断合法性 */
    int ret ;
#if 0
    doubleLinkNode * travelNode = pList->head;
#else
    int pos = 1;
    doubleLinkNode * travelNode = pList->head->next;
#endif
    int cmp = 0;
    while (travelNode != NULL)
    {
        #if 0
        /* 如果遍历的结点里面的值等于我想要删除的值，返回当前的位置（pos）*/
        if(travelNode->data == val)
        {
            /* 解引用 */
            *pPos = pos; 
            return pos;//返回不显示成功与否的返回值 
        }
        #else
        cmp = compareFunc(val, travelNode->data);
        if(cmp == 0)
        {
            *pPos = pos; 
            return pos;
        }
        #endif
        travelNode = travelNode->next;
        pos++;
    }
    *pPos = NOT_FIN;
    return NOT_FIN;
}

/* 链表删除指定数据 */
int DoubleLinkListDelAppointData(DoubleLinkList * pList, ELEMENTTYPE val,int (*compareFunc)(ELEMENTTYPE , ELEMENTTYPE ) )
{

    int ret = 0;
#if 1
    /* 找到要删除的值的位置，就可以复用删除指定位置的函数 */

    int pos =0;
    /* 链表的长度 */
    int size = 0;

    /* 需要遍历链表全部去找 */
    /* 但可能存在 不只一个满足条件的值 // 没有满足条件的值 */
    while (DoubleLinkListGetLength(pList, &size) && pos != NOT_FIN)
    {
        DoubleLinkListAccordAppointValGetPos(pList, val, &pos, compareFunc);
        DoubleLinkListDelAppointPos(pList, pos);
    }
#endif
#if 0
    DoubleLinkListAccordAppointValGetPos(pList, val, &pos);
    DoubleLinkListDelAppointPos(pList, pos);
#endif

#if 0
    /* 遍历：从头开始找哪个位置的值与要删的数据相同 */
    int pos = 1;
    doubleLinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        
        ret = compareFunc(val, travelNode->data);
        travelNode = travelNode->next;

        if(ret == 1)
        {
            DoubleLinkListDelAppointPos(pList, pos);
            //printf("%d\n", ret);
            ret = 0;
            pos--;
        }
        pos++;
    }
#endif
    


    return ret;
}

/* 获取链表的长度 */
int DoubleLinkListGetLength(DoubleLinkList * pList, int *pSize)
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
int DoubleLinkListDestory(DoubleLinkList * pList)
{
    int ret = 0;
    /* 代码复用 ：使用头删删除结点 */
    int size = 0;
    /* 非零即正，则可以进入循环 */
    while (DoubleLinkListGetLength(pList, &size))
    {
        DoubleLinkListHeadDel(pList);
    }

    if(pList->head != NULL)
    {
        free(pList->head );
        pList->head = NULL;
        pList->tail = NULL;
    }
    return ret;
}
/* 链表的遍历 */
int DoubleLinkListForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE))
{

    /*int (*printfFunc)(ELEMENTTYPE) 是形参，它的实参是printStruct */ 
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
#if 0
    /* travelNode 指向虚拟头结点 */ gi
    doubleLinkNode * travelNode = pList->head;
     while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
#if 1
    /* travelNode 指向链表的第一个元素 */
    doubleLinkNode * travelNode = pList->head->next;
#else
    /* travelNode 指向链表的最后一个元素 */
    doubleLinkNode * travelNode = pList->tail;


#endif

    while (travelNode != NULL)
    {
        #if 0
        printf("travelNode->data:%d\n", travelNode->data);
        #else
        /* 包装器   钩子  回调函数 */
        printFunc(travelNode->data);

        #endif
        travelNode = travelNode->next;
    }
#endif
    return ret;
}

int DoubleLinkListBackForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE))
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    /* travelNode 指向链表的最后一个元素 */
    doubleLinkNode * travelNode = pList->tail;

    /* 结束条件为头指针和尾指针相同 而不是指向的结点为空 */
    while (travelNode != pList->head)
    {

        /* 包装器   钩子  回调函数 */
        printFunc(travelNode->data);

        travelNode = travelNode->prev;
    }
    return ret;
}
