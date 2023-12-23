#ifndef __DoubleLinkList_H_
#define __DoubleLinkList_H_

#define ELEMENTTYPE void * 

/* 链表结点 取别名*/
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;

    /*指向前一个结点的指针 */
    struct DoubleLinkNode * prev;
    /* 指向下一个结点的指针 */
    struct DoubleLinkNode *next; /* 指针类型 */


}DoubleLinkNode;

/* 链表 */
typedef struct DoubleLinkList
{
    DoubleLinkNode * head;  /* 链表的虚拟头结点 */
    DoubleLinkNode * tail;  /* 为什么尾指针不需要分配空间 */
    int len;          /* 链表长度 */

}DoubleLinkList;



/* 链表初始化 */
int DoubleLinkListInit(DoubleLinkList ** pList);

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插 */
int DoubleLinkListAppointPosInsert(DoubleLinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int DoubleLinkListHeadDel(DoubleLinkList * pList);

/* 链表尾删*/
int DoubleLinkListTailDel(DoubleLinkList * pList);

/* 链表指定位置删除 */
int DoubleLinkListDelAppointPos(DoubleLinkList * pList, int pos);

/* 链表删除指定数据 */
int DoubleLinkListDelAppointData(DoubleLinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 获取链表的长度 */

int DoubleLinkListGetLength(DoubleLinkList * pList , int *pSize);

/* 链表的销毁 */
int DoubleLinkListDestory(DoubleLinkList * pList);

/* 链表遍历接口 */
int DoubleLinkListForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));

/* 链表逆序遍历 */
int DoubleLinkListBackForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));


#endif //__DoubleLinkList_H_