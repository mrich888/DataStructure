#ifndef __CircleDoubleLinkList_H_
#define __CircleDoubleLinkList_H_

#define ELEMENTTYPE void * 

/* 链表结点 取别名*/
typedef struct CircleDoubleLinkNode
{
    ELEMENTTYPE data;

    /*指向前一个结点的指针 */
    struct CircleDoubleLinkNode * prev;
    /* 指向下一个结点的指针 */
    struct CircleDoubleLinkNode *next; /* 指针类型 */


}CircleDoubleLinkNode;

/* 链表 */
typedef struct CircleDoubleLinkList
{
    CircleDoubleLinkNode * head;  /* 链表的虚拟头结点 */
    int len;          /* 链表长度 */

}CircleDoubleLinkList;



/* 链表初始化 */
int CircleDoubleLinkListInit(CircleDoubleLinkList ** pList);

/* 链表头插 */
int CircleDoubleLinkListHeadInsert(CircleDoubleLinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插 */
int CircleDoubleLinkListAppointPosInsert(CircleDoubleLinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int CircleDoubleLinkListHeadDel(CircleDoubleLinkList * pList);

/* 链表指定位置删除 */
int CircleDoubleLinkListDelAppointPos(CircleDoubleLinkList * pList, int pos);

/* 链表删除指定数据 */
int CircleDoubleLinkListDelAppointData(CircleDoubleLinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 获取链表的长度 */

int CircleDoubleLinkListGetLength(CircleDoubleLinkList * pList , int *pSize);

/* 链表的销毁 */
int CircleDoubleLinkListDestory(CircleDoubleLinkList * pList);

/* 链表遍历接口 */
int CircleDoubleLinkListForeach(CircleDoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));

/* 链表逆序遍历 */
int CircleDoubleLinkListBackForeach(CircleDoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));


#endif //__CircleDoubleLinkList_H_