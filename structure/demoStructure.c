#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 16
#define DEFAULT_SIZE 2

/* 结构体 */
/* 1. 什么叫结构体：将不同类型的属性封装成一个类型 */
/* 2. 怎么定义结构体？ */

typedef struct stuInfo
{
    int age;
    int height;
    int weight;
    char sex;
    char name[BUFFER_SIZE];
    char *address;
#if 0
    char clothes;
    char shoes;
    char phones;
#endif
}stuInfo;

#if 0
/*  取别名 typedef */
typedef struct stuInfo stuInfo;
#endif 



/* 结构体会默认进行字节对齐：读取速度快（但浪费空间）*/
/* 结构的[位域]到网络编程的时候再深究。todo... */
/* 什么叫变长结构体 */



/* 函数：结构体做函数参数 */
#if 0
/* 值传递：不影响实参 */
int printStruct(stuInfo stu)
{
    /* 栈空间小得很，不允许超过8M */
    stu.age = 100;
    printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%c\t,stu.weight:%d\t,stu.name:%s\n",
    stu.age, stu.height, stu.sex, stu.weight, stu.name);
    return 0;
}

#else

/* 传入参数：不要改变值 */
int printStruct(const stuInfo *stu)
{
    /* 栈空间小得很，不允许超过8M。 */
    /* 结构必须用指针， 省内存空间。*/
    int ret = 0;
    int len = sizeof(stu);
    printf("len:%d\n",len);/*指针的长度*/
    return 0;
}
#endif



/* 结构体数组做函数参数 */
int printStructBuffer(stuInfo *stu, int stuSize)
{
    for(int idx = 0; idx < stuSize; idx++)
    {
        printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%c\t,stu.weight:%d\t,stu.name:%s\n",
        stu[idx].age, stu[idx].height, stu[idx].sex, stu[idx].weight, stu[idx].name);
    }
    return 0;
}


int main()
{
#if 1
    /* 3. 怎么使用结构体 */
    stuInfo stu;
    memset(&stu, 0, sizeof(stu));

    /* 4. 结构体的大小 */
    int len =sizeof(stu);
    printf("len:%d\n", len);
#if 0
    stu.age = 10;
    stu.height = 50;
    stu.sex = 'm';
    stu.height = 100;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);

    printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%c\t,stu.weight:%d\t,stu.name:%s\n",
    stu.age, stu.height, stu.sex, stu.weight, stu.name);

#endif
    /* 5. 结构体数组 */
    /* 数组： 
        1.一块连续连续得内存地址
        2.存放的是同一种数据类型
    */
    stuInfo buffer[DEFAULT_SIZE];

    buffer[0].age = 10;
    buffer[0].weight = 30;
    buffer[0].sex = 'm';
    buffer[0].height = 130;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);

    buffer[1].age = 20;
    buffer[1].weight = 50;
    buffer[1].sex = 'f';
    buffer[1].height = 160;
    strncpy(buffer[0].name, "wangwu", sizeof(buffer[1].name) - 1);
   
    
    printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%c\t,stu.weight:%d\t,stu.name:%s\n",
        buffer[0].age, buffer[0].height, buffer[0].sex, buffer[0].weight, buffer[0].name);
    printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%c\t,stu.weight:%d\t,stu.name:%s\n",
        buffer[1].age, buffer[1].height, buffer[1].sex, buffer[1].weight, buffer[1].name);
#endif
  

#if 1
    /* 结构体指针 */
    stu.age = 10;
    stu.height = 50;
    stu.sex = 'm';
    stu.height = 100;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);

#if 0
    /* 指针 */
    int a = 5;
    int *p = &a;

    /* 结构体指针 */
    stuInfo * info =&stu;
    /* 结构体指针 读数据 或者 写数据 都是用->  */

    info -> age = 30;
#endif

    printStruct(&stu);
    printf("stu.age:%d\n", stu.age);

#endif

#if 1
    /* 5. 结构体数组 */
    /* 数组： 
        1.一块连续连续得内存地址
        2.存放的是同一种数据类型
    */
    stuInfo buffer[DEFAULT_SIZE];

    buffer[0].age = 10;
    buffer[0].weight = 30;
    buffer[0].sex = 'm';
    buffer[0].height = 130;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);

    buffer[1].age = 20;
    buffer[1].weight = 50;
    buffer[1].sex = 'f';
    buffer[1].height = 160;
    strncpy(buffer[0].name, "wangwu", sizeof(buffer[1].name) - 1);

    printStructBuffer(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif

#if 1
    /* 结构体指针 */
    stu.age = 10;
    stu.weight = 30;
    stu.sex = 'm';
    stu.height = 130;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);

    stu.address = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if(stu.address == NULL);
    {
        return -1;
    }
    strcpy(stu.address, "china");
    printf("china:%p\n", "china");
#endif

 
    return 0;
}