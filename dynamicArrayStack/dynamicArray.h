#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_


typedef void* ELEMENTTYPE;

typedef struct dynamicArray
{
    ELEMENTTYPE *data;       /* 数组空间 */
    int len;        /* 数组的大小 */
    int capacity;   /* 数组的容量 */
}dynamicArray;

/* API : application program interface. */

/* 动态数组的初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity);

/* 动态数组插入数据(默认插到数组的末尾) */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val);

/* 动态数组插入数据，在指定位置插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组修改指定位置数据 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组删除数据（默认情况下删除末尾数据） */
int dynamicArrayDeleteData(dynamicArray *pArray);

/* 动态数组删除指定位置数据，后面数据全部前移 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos);

/* 动态数组删除指定元素 */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));



/* 动态数组销毁 */
int dynamicArrayDestroy(dynamicArray *pArray);

/* 获取动态数组的大小 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pSize);

/* 获取动态数组的容量 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pCapacity);

/* 获取指定位置元素数据 */
int dynamicArrayGetAppointPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *val);

/* 数组排序 */
int dynamicArrayAppointWaySort(dynamicArray *pArray, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

#endif