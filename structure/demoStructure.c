#include <stdio.h>
#define BUFFER_SIZE 16
#define DEFAULT_SIZE 2

/* 结构体 */
/* 什么叫结构体:将不同类型的属性封装成一个类型 */
/* 怎么定义结构体 */

typedef struct stuInfo
{
    int age;
    int height;
    int weight;
    char sex;
    char name[BUFFER_SIZE];
    char *address;
  
}stuInfo;
/* 结构体默认进行字节对齐：int类型是4个，char是1个，有四个char(本来有phone和clothes...)所以正好补齐，BUFFER_SIZE是16正好也是4的倍数，读取速度快，但浪费空间 */
/* 什么叫变长结构体 */
/* 取别名 typedef */


/* 函数：结构体做函数参数 */
int printStructBuffer(stuInfo *stu, int stuSize)//结构体数组做函数参数弱化为指针，因此未知长度
{
    for(int idx = 0; idx < stuSize; idx++)
    {

        printf("stu.age:%d\t, stu.height:%d\t, stu.sex:%c\t, stu.weight:%d\t, stu.name:%s\t");
        
    }
        return 0;
}
#if 0
typedef struct stuInfo stuInfo;
#endif
#if 0
/* 值传递：不影响实参 */
int printStruct(stuInfo stu)
{
    
    printf("stu.age:%d\t, stu.height:%d\t, stu.sex:%c\t, stu.weight:%d\t, stu.name:%s\t");
    return 0;
}
#else
#if 0
/* 传入参数：不要改变值 */
int printStruct(const stuInfo *stu)
{
    /* 结构体必须用指针，省内存空间 */
    int ret = 0;
    int len = sizeof(stu);
    printf("len:%d\n", len);
    stu->age = 100;
    printf("stu.age:%d\t, stu.height:%d\t, stu.sex:%c\t, stu.weight:%d\t, stu.name:%s\t");
    return 0;
}
#endif
#endif
int main()
{
#if 0
    /* 怎么使用结构体 */
   struct stuInfo stu;
   memset(&stu, 0, sizeof(stu));
#endif
#if 0
    /* 结构体的大小 */
   int len = sizeof(stu);
   printf("len:%d\n",len);
#endif
   /* 结构体数组 */
   /* 数组：
        1.一块连续的内存地址
        2.存放的是同一种数据类型
    */
#if 1
   stuInfo buffer[DEFAULT_SIZE];

   buffer[0].age = 10;
   buffer[0].weight = 50;
   buffer[0].sex = 'm';
   buffer[0].height= 180;
   strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);


   buffer[1].age = 20;
   buffer[1].weight = 50;
   buffer[1].sex = 'f';
   buffer[1].height= 160;
   strncpy(buffer[1].name, "wangwu", sizeof(buffer[1].name) - 1);

   printf("stu.age:%d\t, stu.weight:%d\t, stu.sex:%c\t, stu.height:%d\t, stu.name:%s\t", buffer[0].age, buffer[0].weight, buffer[0].sex, buffer[0].height, buffer[0].name);
   printf("stu.age:%d\t, stu.weight:%d\t, stu.sex:%c\t, stu.height:%d\t, stu.name:%s\t", buffer[1].age, buffer[1].weight, buffer[1].sex, buffer[1].height, buffer[1].name);


   printStructBuffer(buffer, sizeof(buffer)/sizeof(buffer[0]));
#endif
#if 0
   stu.age = 10;
   stu.height = 50;
   stu.sex = 'm';
   stu.height = 170;
   //stu.name = "zhangsan";
   strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);
 
//   printf("stu.age:%d\t, stu.height:%d\t, stu.sex:%c\t, stu.weight:%d\t, stu.name:%s\t");
#endif
#if 0
    int desk;
    int char;
    int balckboard;
    int light;

#endif
#if 0
    /* 回顾指针 */
    int a = 5;
    int *p = &a;

    /* 结构体指针 */
    stuInfo * info = &stu;
    /* 结构体指针 读数据或写数据，都用->*/
    info->age = 30;
#endif
#if 0
    printf("info->age:%d\n", info->age);
    printf("stu.age:%d\n", stu.age);

    printStruct(stu);
#endif
    return 0;
}