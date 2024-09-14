#include <iostream>
#include <string>
using namespace std;

#include "SqList.h"

int main()
{
    int i;
    ElemType e;
    List *list1;
    InitList(list1);

    DestroyList(list1);

//    ListInsert(list1,1,1);
//    ListInsert(list1,2,3);
//    ListInsert(list1,3,5);
//
//    for(i=1;i<=ListLength(list1);i++)
//    {
//        GetElem(list1,i,e);
//        cout<<e<<" ";
//    }
//    cout<<endl;
//    ListDelete(list1,2,e);
//    cout<<"É¾³ýµÄÔªËØÎª£º"<<e<<endl;
//    for(i=1;i<=ListLength(list1);i++)
//    {
//        GetElem(list1,i,e);
//        cout<<e<<" ";
//    }
//    cout<<endl;

    return 0;
}


//void unionList(List *A,List *B,List *&C)
//{
//	int i,j,k,alen,blen,clen;
//	ElemType ea,eb;
//	alen=ListLength(A);blen=ListLength(B);
//	clen=alen+blen;
//	i=j=1;k=1;
//	while(i<=alen&&j<=blen)
//	{
//		GetElem(A,i,ea);GetElem(B,j,eb);
//		if(ea<eb)
//		{
//			ListInsert(C,k,ea);
//			i++;
//		}
//		else
//		{
//			ListInsert(C,k,eb);
//			j++;
//		}
//		k++;
//	}
//	while(i<=alen)
//	{
//		GetElem(A,i,ea);
//		ListInsert(C,k,ea);
//		i++;k++;
//	}
//	while(j<=blen)
//	{
//		GetElem(B,j,eb);
//		ListInsert(C,k,ea);
//		j++;k++;
//	}
//}
//int main()
//{
//
//	List *A,*B,*C;
//	InitList(A);
//	InitList(B);
//	InitList(C);
//	int i;
//	ElemType e;
//	for(i=1;i<=5;i++)
//		ListInsert(A,i,2*i-1);
//	for(i=1;i<=3;i++)
//		ListInsert(B,i,2*i);
//
//	DispList(A);
//	DispList(B);
//	unionList(A,B,C);
//	DispList(C);
//
//
//	return 0;
//}

