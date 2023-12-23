#include<stdio.h>
#include"circleDoubleLinkList.h"
#include<string.h>

#define BUFFER_SIZE 3


int printBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\n", data);

}

int compareData(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    if(*(int *)val1 == *(int *)val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    CircleDoubleLinkList * list = NULL;
    /* 初始化链表 */
    CircleDoubleLinkListInit(&list);
    int buffer[BUFFER_SIZE] = {1, 2, 3};
    /* 插入数据 */

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        CircleDoubleLinkListHeadInsert(list, (void *)&buffer[idx]);
    }
  
    /* 获取链表的长度 */
    int size = 0;
    CircleDoubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);

    //CircleDoubleLinkListForeach(list, printBasicData);
    CircleDoubleLinkListBackForeach(list, printBasicData);

    //CircleDoubleLinkListHeadDel(list);
    //CircleDoubleLinkListDelAppointPos(list, 2);
    //int del = 2;
    //CircleDoubleLinkListDelAppointData(list, (void *)&del, compareData);
    CircleDoubleLinkListDestory(list);
    CircleDoubleLinkListBackForeach(list, printBasicData);
    return 0;
}