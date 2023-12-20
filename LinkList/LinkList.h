#ifndef __LINKLIST_H_
#define __LINKLIST_H_


#define ELEMENTTYPE int


/* 取别名 */
typedef struct LinkNode
{
    int data;
    /* 指向下一个结点的指针*/
    struct LinkNode *next; /* 指针的类型 */
}LinkNode;

/* 链表 */
typedef struct LINKLIST
{
    /* 链表的虚拟头结点 */
    LinkNode * head;

    /* 链表的长度 */
    int len;
}LinkList;

/* 链表初始化 */
int LinkListInit(LinkList ** pList);

/* 链表头插 */
int LinkListHeadInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int LinkListTailInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int LinkListHeadDel(LinkList * pList);

/* 链表尾删 */
int LinkListTailDel(LinkList * pList);

/* 链表指定位置删 */
int LinkListDelAppointPos(LinkList * pList, int pos);

/* 链表指定数据删 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val);

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize);

/* 链表的销毁 */
int LinkListDestory(LinkList * pList);


#endif