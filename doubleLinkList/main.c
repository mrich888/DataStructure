#include<stdio.h>
#include"doubleLinkList.h"
#include<string.h>

#define BUFFER_SIZE 3

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;

/* 自定义打印 */
int printStruct(void *arg)
{
    /* 强转成结构体类型 */
    stuInfo *info = (stuInfo*)arg;
    printf("age:%d\t, sex:%c\n", info->age, info->sex);
}

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


    doubleLinkList * list = NULL;
    /* 初始化链表 */
    doubleLinkListInit(&list);
#if 0
    int num = 1;
    doubleLinkListHeadInsert(list,&num);
    int size = 0;
    doubleLinkListGetLength(list, &size);

    doubleLinkListForeach(list, printBasicData);
#endif

#if 1
    int buffer[BUFFER_SIZE] = {1, 2, 3};
    /* 插入数据 */

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListHeadInsert(list, (void *)&buffer[idx]);
    }
  
    /* 获取链表的长度 */
    int size = 0;
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);

    
    //doubleLinkListAppointPosInsert(list, 2, (void *)5);
    // doubleLinkListGetLength(list, &size);
    // printf("size:%d\n", size);

    doubleLinkListForeach(list, printBasicData);

    

#endif
#if 0
    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 10;
    stu3.sex = 'm';

    stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListHeadInsert(list, (void *)&buffer[idx]);
    }
    int size = 0;
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);
    
#if 0
    /* 头删 */
    doubleLinkListHeadDel(list);
#endif

#if 0
    /* 尾删 */
    doubleLinkListTailDel(list);
#endif

#if 0
    /* 指定位置删除 */
    doubleLinkListDelAppointPos(list, 2);
#endif 
#endif
#if 1
    /* 指定元素删除 */
    //(stuInfo *)&stu1
    int del = 2;
    doubleLinkListDelAppointData(list, (void *)&del, compareData);
#endif 

    /* 遍历 */
    doubleLinkListForeach(list, printStruct);

    return 0;
}