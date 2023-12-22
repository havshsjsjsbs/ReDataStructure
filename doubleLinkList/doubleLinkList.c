#include <stdio.h>
#include "doubleLinkList.h"
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    NOT_FOUND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};
/* 静态函数只在本源文件使用 */
/* 链表初始化 */
#if 0
int DoubleLinkListInit(DoubleLinkList ** pList)
{
    int ret = 0;
    DoubleLinkList *list = (DoubleLinkList *)(sizeof(DoubleLinkList) * 1);
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list, 0, sizeof(DoubleLinkList) * 1);

    list->head = (doubleLinkNode *)malloc(sizeof(doubleLinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list->head, 0, sizeof(doubleLinkNode) * 1);
    list->head->data = 0;
    list->head->next = NULL;

    /* 尾指针初始化的时候， 尾指针=头指针 */
    list->tail = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针 */
    *pList = list;
    return ret;


}
#else
int DoubleLinkListInit(DoubleLinkList** pList)
{
    int ret = 0;
    DoubleLinkList *list = (DoubleLinkList*)malloc(sizeof(DoubleLinkList) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    //清空脏数据
    memset(list, 0, sizeof(DoubleLinkList) * 1);
    list->head = (doubleLinkNode *)malloc(sizeof(doubleLinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
     //清空脏数据
    memset(list->head, 0, sizeof(DoubleLinkList) * 1);
    list->head->data = 0;
    list->head->next = NULL;

    //初始化时尾指针 = 头指针
    list->tail = list->head;

    //链表的长度为零
    list->len = 0;

 
    //二级指针
    *pList = list;

 return ret;
}
#endif

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList *pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList * pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, pList->len, val);
}

/* 链表指定位置插入 */
int DoubleLinkListAppointPosInsert(DoubleLinkList * pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    if(pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    };

    /* 封装结点 */
    doubleLinkNode * newNode = (doubleLinkNode *)malloc(sizeof(doubleLinkNode) * 1);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清除脏数据 */
    memset(newNode, 0, sizeof(doubleLinkNode) * 1);
    newNode->data = 0;
    newNode->next = NULL;
    /* 赋值 */
    newNode->data = val;
#if 1
    /* 从虚拟头结点开始遍历 */
    doubleLinkNode * travelNode = pList->head;    
#else
    doubleLinkNode * travelNode = pList->head->next;
#endif
    /* 这种情况下需要更改尾指针 */
    int flag = 0;
    if(pos == pList->len)//空的头插&尾插
    {
        /* 修改结点指向 */
        travelNode = pList->tail;
        flag = 1;

    }
    else
    {
        while(pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
    }
    
    /* 修改结点指向 */
    newNode->next = travelNode->next;
    travelNode->next = newNode;

    if(flag)
    {
        pList->tail = newNode;
    }

    /* 更新链表长度 */
    (pList->len)++;
    return ret;
}

/* 链表头删 */
int DoubleLinkListHeadDel(DoubleLinkList * pList)
{
    return DoubleLinkListDelAppointPos(pList, 1);
}

/* 链表尾删 */
int DoubleLinkListTailDel(DoubleLinkList * pList)
{
    return DoubleLinkListDelAppointPos(pList, pList->len);
}

/* 链表指定位置删 */
int DoubleLinkListDelAppointPos(DoubleLinkList * pList, int pos)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    if(pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

#if 1
    doubleLinkNode * travelNode = pList->head;
#else
#endif
    int flag = 0;
    if (pos == pList->len)
    {
        flag = 1;
    }
    doubleLinkNode * needDelNode = NULL;
    while(--pos)
    {
        /* 向后移动位置 */
        travelNode = travelNode->next;
        
    }
    //跳出循环找的是哪个元素
    needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;

    /* 释放内存 */
    if(needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    /* 链表长度减1 */
    (pList->len)--;
    return ret;

}

/* 根据指定的元素得到在链表中的位置 */
static int DoubleLinkListAccordAppointValGetPos(DoubleLinkList * pList, ELEMENTTYPE val, int *pPos,  int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    /* 静态函数只在本源文件使用,不需要判断合法性 */
    int ret = 0;
#if 0
    doubleLinkNode *travelNode = pList->head;
#else
    int pos = 1;
    doubleLinkNode *travelNode = pList->head->next;
#endif
    while(travelNode != NULL)
    {
        #if 0
        if(travelNode->data == val)
        {
            *pPos = pos;
            //return pos;
        }
        #else
        int cmp = compareFunc(val, travelNode->data);
        if(cmp == 0)
        {
            *pPos = pos;
            //return pos;
        }
        travelNode = travelNode->next;
        pos++;
        #endif
    }

    return *pPos;
    return NOT_FOUND;
}

/* 链表指定数据删 */
int DoubleLinkListDelAppointData(DoubleLinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    int ret = 0;

    int pos = 0;
    int size = 0;

    
    while(DoubleLinkListGetLength(pList, &size) && pos != NOT_FOUND)
    {
        int pos = 0;
        //DoubleLinkListAccordAppointValGetPos(pList, val, &pos);
        DoubleLinkListAccordAppointValGetPos(pList, val, &pos, compareFunc);
        DoubleLinkListDelAppointPos(pList, pos);
        return ret;
    }
    
}

/* 获取链表的长度 */
int DoubleLinkListGetLength(DoubleLinkList *pList, int *pSize)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pSize)
    {
        *pSize = pList->len;
    }

    // 返回链表的长度
    return pList->len;
    
}

/* 链表的销毁 */
int DoubleLinkListDestory(DoubleLinkList * pList)
{
    int ret = 0;
    /* 我们使用头删释放链表 */
    int size = 0;
    while(DoubleLinkListGetLength(pList, &size))
    {
        DoubleLinkListHeadDel(pList);
    }

    if(pList->head != NULL)
    {
        free(pList->head);
        /*指针*/
        pList->head = NULL;
        pList->tail = NULL;
    }
    return ret;
}

/* 链表遍历接口 */
#if 0
int DoubleLinkListForeach(DoubleLinkList * pList)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    /* travelNode指向虚拟头结点 */
    doubleLinkNode * travelNode = pList->head;
    while(travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
    /* travelNode 指向链表的第一个元素 */
    doubleLinkNode * travelNode = pList->head->next;
    while(travelNode->next != NULL)
    {
        printf("travelNode->data:%d\n", travelNode->data);
        travelNode = travelNode->next;
    }
#endif
    return ret;

   
}
#else
int DoubleLinkListForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE))
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    //travelNode指向虚拟头结点
    doubleLinkNode * travelNode = pList->head;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
    //travelNode指向链表第一个元素
    doubleLinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        #if 0
        printf("travelNode->data:%d\n", travelNode->data);
        #else
        /* 包装器 回调函数 */
        printFunc(travelNode->data);
        #endif
        travelNode = travelNode->next;

    }
    
#endif
   
    return ret;
}
#endif
