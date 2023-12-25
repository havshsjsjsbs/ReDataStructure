#ifndef __DoubleLinkList_H_
#define __DoubleLinkList_H_

#define ELEMENTTYPE void*

/* 链表节点取别名 */
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;

    /* 指向前一个节点的指针 */
    struct DoubleLinkNode * prev;

    /* 指向下一个节点的指针 */
    struct DoubleLinkNode *next; /* 指针的类型为什么是节点 */
} DoubleLinkNode;

typedef struct DoubleDoubleLinkNode
{
    DoubleLinkNode node;
    
}DoubleDoubleLinkNode;

/* 链表 */
/* 虚拟头节点  1、数据域无意义 2、只使用指针域  */
typedef struct DoubleLinkList
{
    /* 链表的虚拟头节点 */
    DoubleLinkNode * head;
    DoubleLinkNode * tail;    /* 为什么尾指针不需要分配空间 */
     /* 链表长度 */
    int len;
}DoubleLinkList;

/* 链表初始化 */
int DoubleLinkListInit(DoubleLinkList ** pLink);

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int DoubleLinkListAppointPosInsert(DoubleLinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int DoubleLinkListHeadDel(DoubleLinkList *pList);

/* 链表尾删 */
int DoubleLinkListTailDel(DoubleLinkList *pList);

/* 链表指定位置删除 */
int DoubleLinkListDelAppointPos(DoubleLinkList *pList, int pos);

/* 链表删除指定元素 */
int DoubleLinkListDelAppointData(DoubleLinkList *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

/* 获取链表的长度 */
int DoubleLinkListGetLength(DoubleLinkList *pList, int *pSize);

/* 链表的销毁 */
int DoubleLinkListDestory(DoubleLinkList *pList);

/* 链表的遍历接口 */
int DoubleLinkListForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE));

/* 链表逆序打印 */
int DoubleLinkListReverseForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE));

/* 获取链表 头位置值 */
int DoubleLinkListGetHeadVal(DoubleLinkList * pList, int pos, ELEMENTTYPE *pVal);

/* 获取链表 尾位置值 */
int DoubleLinkListGetTailVal(DoubleLinkList * pList,  ELEMENTTYPE *pVal);

/* 获取链表 指定位置值 */
int DoubleLinkListGetAppointPosVal(DoubleLinkList * pList, int pos, ELEMENTTYPE *pVal);
#endif