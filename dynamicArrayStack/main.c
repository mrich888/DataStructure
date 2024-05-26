#include <stdio.h>
#include "dynamicArrayStack.h"

#define BUFFER_SIZE 5

int main()
{
    dynamaicArrayStack stack;

    /* 怎么解决套壳问题 */
    dynamaicArrayStackInit(&stack);

    int buffer[] = {5, 32, 21, 56, 87 };
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        dynamaicArrayStackPush(&stack, &buffer[idx]);
    }
    int size = 0;
    dynamaicArrayGetStackSize(&stack, &size);
    printf("size:%d\n", size);

    int *val = NULL;
    while (!dynamaicArrayStackEmpty(&stack))
    {
        dynamaicArrayStackTop(&stack, (void **)&val);
        printf("val:%d\n", *val);
        dynamaicArrayStackPop(&stack);
    }

    /* 栈的销毁 */
    dynamaicArrayStackDestroy(&stack);
    

    return 0;
}