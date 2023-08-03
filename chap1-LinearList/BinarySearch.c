#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

Position BinarySearch(List L, ElementType X){
    Position left = 0, right = L->Last, middle;
    while(left <= right){
        middle = (left + right) / 2;
        if(L->Data[middle] == X) return middle;
        else if(L->Data[middle] < X) left = middle + 1;
        else right = middle - 1;
    }
    return NotFound;
}


/* 你的代码将被嵌在这里 */
/*
Position BinarySearch(List L, ElementType X){
     if(X == L->Data[1])
        return 1;
     if(X == L->Data[L->Last])
        return L->Last;

     ElementType Middle = (1 + L->Last) / 2;
     while(Middle != 1 && Middle != L->Last){
        if(X == L->Data[Middle]) return Middle;
        else if(X < L->Data[Middle])
            Middle = (1 + Middle) / 2;
        else Middle = (Middle + L->Last) / 2;
     }

     return NotFound;
}
*/
