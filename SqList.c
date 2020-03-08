/*
顺序表，按照空间分配方式不同，分为静态分配和动态分配
静态分配就是，定长数组data[]
动态分配就是，利用指针指定初始空间

此文件使用动态分配
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;

// 静态分配空间需要指定最大空间
#define Maxsize 100

/*
静态分配结构体
*/
// typedef struct 
// {
//     ElemType data[Maxsize];
//     int length;
// }SqList;


/*
动态分配结构体
*/
typedef struct 
{
    ElemType *elem;
    int length;
}SqList;

// basic operation of SqList

/*
SqList init
*/
bool InitList (SqList *L){
    L->elem = (ElemType*)malloc(sizeof(ElemType)*Maxsize);
    if (!L->elem)
        return false;
    L->length = 0;
    return true;
}

/*
SqList create
*/
bool CreateList(SqList *L, ElemType x){
    if (L->length == Maxsize)
        return false;
    L->elem[L->length] = x;
    L->length ++;
    return true;
}

/*
GetElem in SqlList
*/
bool GetElem(SqList L, int n, ElemType *elem){
    if(n < 1 || n > L.length - 1)
        return false;
    *elem = L.elem[n - 1];
    return true;
}

/*
InsertElem to SqlList
*/
bool InsertElem(SqList *L, int n, ElemType elem){
    if(n < 1 || n > L->length - 1)
        return false;
    if(L->length - 1 == Maxsize)
        return false;
    for (int i = L->length - 1; i >= n - 1; i--)
    {
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[n - 1] = elem;
    L->length++;
    return true;   
}

/*
DeleteElem in SqList
*/
bool DeleteElem(SqList *L, ElemType n){
    if(n < 1 || n > L->length)
        return false;
    for (int i = n - 1; i < L->length; i++)
    {
        L->elem[i] = L->elem[i + 1];
    }
    L->length--;
    return true;
}


int main(int argc, char const *argv[])
{
    SqList L;
    puts("1 is success init");
    printf("%d\n",InitList(&L));
    CreateList(&L,1);
    CreateList(&L,3);
    CreateList(&L,4);
    CreateList(&L,6);
    CreateList(&L,7);

    puts("creat sqlist");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ",L.elem[i]);
    }
    putchar('\n');

    int elem;
    puts("get elem at 3");
    GetElem(L,3,&elem);
    printf("%d \n",elem);
    puts("Insert elemt at 3,elem is 0");
    InsertElem(&L, 3, 0);
    
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ",L.elem[i]);
    }
    putchar('\n');

    puts("delete elem in 2");
    DeleteElem(&L, 2);

    for (int i = 0; i < L.length; i++)
    {
        printf("%d ",L.elem[i]);
    }
    putchar('\n');

    return 0;
}
