#ifndef __DoubleLinkList_H_
#define __DoubleLinkList_H_


#define ELEMENTTYPE void*


typedef struct doubleLinkNode
{
    ELEMENTTYPE data;
    /* 指向下一个结点的指针*/
    struct doubleLinkNode *next; /* 指针的类型 */
    /* 指向上一个结点的指针*/
    struct doubleLinkNode *prev;

}doubleLinkNode;

/* 链表 */
typedef struct DoubleLinkList
{
    /* 链表的虚拟头结点 */
    doubleLinkNode * head;
    doubleLinkNode * tail;//不需要分配空间，只有需要取里面数据的时候才需要分配空间
    /* 链表的长度 */
    int len;
}DoubleLinkList;

/* 链表初始化 */
int DoubleLinkListInit(DoubleLinkList ** pList);

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int DoubleLinkListAppointPosInsert(DoubleLinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int DoubleLinkListHeadDel(DoubleLinkList * pList);

/* 链表尾删 */
int DoubleLinkListTailDel(DoubleLinkList * pList);

/* 链表指定位置删 */
int DoubleLinkListDelAppointPos(DoubleLinkList * pList, int pos);

/* 链表指定数据删 */
int DoubleLinkListDelAppointData(DoubleLinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

/* 获取链表的长度 */
int DoubleLinkListGetLength(DoubleLinkList * pList, int *pSize);

/* 链表的销毁 */
int DoubleLinkListDestory(DoubleLinkList * pList);

/* 链表遍历接口 */
int DoubleLinkListForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));


#endif