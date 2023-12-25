#ifndef __DoubleLinkListQueue_H_
#define __DoubleLinkListQueue_H_

#include "DoubleLinkList.h"

typedef DoubleLinkList DoubleLinkListQueue;

/* 队列初始化 */
int DoubleLinkListQueueInit(DoubleLinkListQueue **pQueue);

/* 队列入队 */
int DoubleLinkListQueuePush(DoubleLinkListQueue *pQueue, ELEMENTTYPE val);

/* 队头元素 */
int DoubleLinkListQueueTop(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal);

/* 队尾元素 */
int DoubleLinkListQueueRear(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal);

/* 队列出队 */
int DoubleLinkListQueuePop(DoubleLinkListQueue *pQueue);

/* 队列大小 */
int DoubleLinkListQueueGetSize(DoubleLinkListQueue *pQueue, int *pSize);

/* 队列是否为空 */
int DoubleLinkListQueueIsEmpty(DoubleLinkListQueue *pQueue);

/* 队列销毁 */
int DoubleLinkListQueueDestory(DoubleLinkListQueue *pQueue);

#endif