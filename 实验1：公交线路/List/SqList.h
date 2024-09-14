#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#define MaxSize 100

typedef int ElemType;
typedef struct SqList
{
	ElemType data[MaxSize];
	int length;
}List;
void InitList(List *&L);
void DestroyList(List *&L);


#endif // SQLIST_H_INCLUDED
