#ifndef __COMMON_H_
#define __COMMON_H_

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
#endif