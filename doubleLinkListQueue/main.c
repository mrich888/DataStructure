#include <stdio.h>
#include "doubleLinkListQueue.h"

#define BUFFER_SIZE 5

int main()
{
    /* 定义一个队列 */
    doubleLinkListQueue *queue = NULL;
    /* 初始化队列 */
    doubleLinkListQueueInit(&queue);

    int buffer[BUFFER_SIZE] = {111, 222, 333, 444, 555};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {   /* 入队 */
        doubleLinkListQueuePush(queue, (void *)&buffer[idx]);
    }

    int size = 0;
    doubleLinkListQueueGetSize(queue, &size);
    printf("size:%d\n", size);
    
    int *val = NULL;
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&val);
        printf("val:%d\n", *val);
        doubleLinkListQueuePop(queue);
    }
    
    doubleLinkListQueueDestroy(queue);
    
}