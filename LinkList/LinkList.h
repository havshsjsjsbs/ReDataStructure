#ifndef __LINKLIST_H_
#define __LINKLIST_H_


#define ELEMENTTYPE void*


/* 取别名 */
typedef struct LinkNode
{
    void* data;
    /* 指向下一个结点的指针*/
    struct LinkNode *next; /* 指针的类型 */
}LinkNode;

/* 链表 */
typedef struct LINKLIST
{
    /* 链表的虚拟头结点 */
    LinkNode * head;
    LinkNode * tail;//不需要分配空间，只有需要取里面数据的时候才需要分配空间
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
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize);

/* 链表的销毁 */
int LinkListDestory(LinkList * pList);

/* 链表遍历接口 */
int LinkListForeach(LinkList * pList, int (*printFunc)(ELEMENTTYPE));


#endif