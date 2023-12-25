#ifndef __doubleLinkList_H_
#define __doubleLinkList_H_

#define ELEMENTTYPE void * 

/* 链表结点 取别名*/
typedef struct doubleLinkNode
{
    ELEMENTTYPE data;

    /*指向前一个结点的指针 */
    struct doubleLinkNode * prev;
    /* 指向下一个结点的指针 */
    struct doubleLinkNode *next; /* 指针类型 */


}doubleLinkNode;

/* 链表 */
typedef struct doubleLinkList
{
    doubleLinkNode * head;  /* 链表的虚拟头结点 */
    doubleLinkNode * tail;  /* 为什么尾指针不需要分配空间 */
    int len;          /* 链表长度 */

}doubleLinkList;



/* 链表初始化 */
int doubleLinkListInit(doubleLinkList ** pList);

/* 链表头插 */
int doubleLinkListHeadInsert(doubleLinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int doubleLinkListTailInsert(doubleLinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插 */
int doubleLinkListAppointPosInsert(doubleLinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int doubleLinkListHeadDel(doubleLinkList * pList);

/* 链表尾删*/
int doubleLinkListTailDel(doubleLinkList * pList);

/* 链表指定位置删除 */
int doubleLinkListDelAppointPos(doubleLinkList * pList, int pos);

/* 链表删除指定数据 */
int doubleLinkListDelAppointData(doubleLinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 获取链表的长度 */

int doubleLinkListGetLength(doubleLinkList * pList , int *pSize);

/* 链表的销毁 */
int doubleLinkListDestory(doubleLinkList * pList);

/* 链表遍历接口 */
int doubleLinkListForeach(doubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));

/* 链表逆序遍历 */
int doubleLinkListBackForeach(doubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));


#endif //__doubleLinkList_H_