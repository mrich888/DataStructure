#ifndef __LinkList_H_
#define __LinkList_H_

#define ELEMENTTYPE int
/* 链表结点 取别名*/
typedef struct LinkNode
{
    ELEMENTTYPE data;

    /* 指向下一个结点的指针 */
    struct LinkNode *next; /* 指针类型 */


}LinkNode;

/* 链表 */
typedef struct LinkList
{
    LinkNode * head;  /* 链表的虚拟头结点 */
    LinkNode * tail;  /* 为什么尾指针不需要分配空间 */
    int len;         /* 链表长度 */

}LinkList;



/* 链表初始化 */
int LinkListInit(LinkList ** pList);

/* 链表头插 */
int LinkListHeadInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int LinkListTailInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int LinkListHeadDel(LinkList * pList);

/* 链表尾删*/
int LinkListTailDel(LinkList * pList);

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList * pList, int pos);

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val);

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize);

/* 链表的销毁 */
int LinkListDestory(LinkList * pList);

/* 链表遍历接口 */
int LinkListForeach(LinkList * pList);


#endif //__LinkList_H_