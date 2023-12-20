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

    int len;         /* 链表长度 */

}LinkList;

/* 链表初始化 */
int LinkListInit();

/* 链表头插 */
int LinkListHeadInsert();

/* 链表尾插 */
int LinkListTailInsert();

/* 链表指定位置插 */
int LinkListAppointPosInsert();

/* 链表头删 */
int LinkListHeadDel();

/* 链表尾删*/
int LinkListTailDel();

/* 链表指定位置删除 */
int LinkListDelAppointPos();

/* 链表删除指定数据 */
int LinkListDelAppointData();

/* 获取链表的长度 */
int LinkListGetLength();

/* 链表的销毁 */
int LinkListDestory();


#endif //__LinkList_H_