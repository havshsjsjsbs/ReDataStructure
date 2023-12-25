#include "doubleLinkListQueue.h"

/* 队列初始化 */
int DoubleLinkListQueueInit(DoubleLinkListQueue **pQueue)
{
    return DoubleLinkListInit(pQueue);
}

/* 队列入队 */
int DoubleLinkListQueuePush(DoubleLinkListQueue *pQueue, ELEMENTTYPE val)
{
    return DoubleLinkListTailInsert(pQueue, val);
}

/* 队头元素 */
int DoubleLinkListQueueTop(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal)
{
    return DoubleLinkListGetHeadVal(pQueue, pVal);
}

/* 队尾元素 */
int DoubleLinkListQueueRear(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal)
{
    return DoubleLinkListGetTailVal(pQueue, pVal);
}

/* 队列出队 */
int DoubleLinkListQueuePop(DoubleLinkListQueue *pQueue)
{
    return DoubleLinkListHeadDel(pQueue);
}

/* 队列大小 */
int DoubleLinkListQueueGetSize(DoubleLinkListQueue *pQueue, int *pSize)
{
    return DoubleLinkListGetLength(pQueue, pSize);
}

/* 队列是否为空 */
int DoubleLinkListQueueIsEmpty(DoubleLinkListQueue *pQueue)
{
    int size = 0;
    DoubleLinkListGetLength(pQueue, &size);
    return size == 0 ? 1 : 0;
}

/* 队列销毁 */
int DoubleLinkListQueueDestory(DoubleLinkListQueue *pQueue)
{
    return DoubleLinkListDestory(pQueue);
}
