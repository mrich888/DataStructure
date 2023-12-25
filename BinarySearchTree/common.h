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

#endif