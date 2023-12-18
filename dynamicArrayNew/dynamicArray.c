#include <stdio.h>
#include "dynamicArray.h"
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR;
}

#define DEFAULT_SIZE 10
int main()
{
#if 0
    /* 静态数组 
        1.不够灵活
        2. 可能会有浪费的现象
    */

    int classStu[30];
    for (int idx = 0; idx < )
    return 0;
#endif
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
    if(pArray->data = = NULL)
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
int dynamicArrayInsertData(dynamicArray *pArray);

/* 动态数组插入数据，在指定位置插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

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
}