#ifndef __DoubleLinkListQueue_H_
#define __DoubleLinkListQueue_H_

/* 队列初始化 */
int DoubleLinkListQueueInit();

/* 队列入队 */
int DoubleLinkListQueuePush();

/* 队头元素 */
int DoubleLinkListQueueTop();

/* 队尾元素 */
int DoubleLinkListQueueRear();

/* 队列出队 */
int DoubleLinkListQueuePop();

/* 队列大小 */
int DoubleLinkListQueueGetSize();

/* 队列是否为空 */
int DoubleLinkListQueueIsEmpty();

/* 队列销毁 */
int DoubleLinkListQueueDestory();

#endif