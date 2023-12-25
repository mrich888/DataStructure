#include <stdio.h>
#include "doubleLinkListQueue.h"

#define BUFFER_SIZE 5

int main()
{
    doubleLinkListQueue *queue = NULL;

    doubleLinkListQueueInit(&queue);

    int buffer[BUFFER_SIZE] = {111, 222, 333};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListQueuePush(queue, (void *)&buffer[idx]);
    }
    
    int size = 0;
    
}