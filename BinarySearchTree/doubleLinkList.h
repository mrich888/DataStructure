#ifndef __DOUBLELINKLIST_H_
#define __DOUBLELINKLIST_H_

#include "common.h"

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

/* 获取链表 头位置值 */
int doubleLinkListGetHeadVal(doubleLinkList * pList, ELEMENTTYPE *val);

/* 获取链表 尾位置值 */
int doubleLinkListGetTailVal(doubleLinkList * pList, ELEMENTTYPE *val);

/* 获取链表 指定位置值 */
int doubleLinkListGetAppointPosVal(doubleLinkList * pList, int pos, ELEMENTTYPE *val);

#endif //__doubleLinkList_H_