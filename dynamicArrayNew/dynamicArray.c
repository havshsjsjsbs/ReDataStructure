#include <stdio.h>
#include "dynamicArray.h"
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
}

#define DEFAULT_SIZE 10

/* 静态函数前置声明 */
static int expandDynamiCapacity(dynamicArray *pArray);


#if 0
    /* 静态数组 
        1.不够灵活
        2. 可能会有浪费的现象
    */

    int classStu[30];
    for (int idx = 0; idx < )
    return 0;
#endif

static int expandDynamiCapacity(dynamicArray *pArray)
{
    ELEMENTTYPE * tmpPtr = pArray->data;
    int needExpandCapacity = pArray->capacity + (pArray->capacity) >> 1;

    pArray->data =(ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);

    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 把之前的数据全部拷贝 */
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] =  tempPtr[idx];
    }

    /* 释放以前的内存，避免内存泄露 */
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }
    
}
    /* 动态数组的初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    if(pArray == NULL)//数组名是地址，首元素为空即空
    {
        return NULL_PTR;
    }

    /* 避免传入非法值 */
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }

    /* 分配空间 */
    pArray->data = malloc(sizeof(ELEMENTTYPE) * int capacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * int capacity);
    pArray->len = 0;
    pArray->capacity = capacity;

    return ON_SUCCESS;
}


/* 动态数组插入数据(默认插到数组的末尾) */
int dynamicArrayInsertData(dynamicArray *pArray)
{
   return dynamicArrayAppointPosInsertData(pArray, pArray->len, ELEMENTTYPE val);
}

/* 动态数组插入数据，在指定位置插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
     if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 判断位置的合法性 */
     if(pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 数组扩容的临界值：数组大小的1.5倍 >= 数组容量 */
    if(pArray->len + (pArray->len >> 1) >= pArray->capacity)
    {
        expandDynamicCapacity(pArray);
    }
   
    /* 数据后移，读出pos位置插入*/
    for(int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] =  pArray->data[idx - 1];
    }
    /* 找到对应的值 写入到数组中 */
    pArray->data[pos] = val;

    /* 数组的大小加一 */
    (pArray->len)++;
}

/* 动态数组修改指定位置数据 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组删除数据（默认情况下删除末尾数据） */
int dynamicArrayDeleteData(dynamicArray *pArray);

/* 动态数组删除指定位置数据，后面数据全部前移 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos);

/* 动态数组删除指定元素 */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val);



/* 动态数组销毁 */
int dynamicArrayDestroy(dynamicArray *pArray);

/* 获取动态数组的大小 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pSize);

/* 获取动态数组的容量 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pCapacity);
