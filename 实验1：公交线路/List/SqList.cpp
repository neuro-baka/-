#include <iostream>
#include <string>
using namespace std;
#include "stdio.h"
#include "stdlib.h"
#include "SqList.h"

void InitList(List *&L)
{
	L=new List;  //L=(List*)malloc(sizeof(List)); //
	L->length=0;
}
void DestroyList(List *&L)
{
	delete L;//free(L);  //
}
