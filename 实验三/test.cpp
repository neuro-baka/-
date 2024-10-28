#include<bits/stdc++.h>

using namespace std;

#define Maxsize 100000

typedef struct
{
    char date[Maxsize];
    int length;
}SqString;                      //存储字符与字符串的长度 

void CreatSqString(SqString *&String,char a[],int n)        //创建SqString 
{
    int i=0;

    String=(SqString *)malloc(sizeof(SqString));

    while(i<n)
    {
        String->date[i]=a[i];
        i++;
    }

    String->length=n;
}



void GetNextval(SqString*& t,int nextval[])       //计算nextval数组 
{
    int j=0,k=-1;            //k记录前缀索引 
    nextval[0]=-1;

    while(j<t->length-1)          //遍历到倒数第二个字符 
    {
        if(k==-1 || t->date[j]==t->date[k])       //继续扩展前缀 
        {
            j++;
            k++;

            if(t->date[j]!=t->date[k])         //前后缀不相等 
            {
                nextval[j]=k;           //j位置之前最长相等的前后缀为k 
            }
            else                           //前后缀相等 
            {
                nextval[j]=nextval[k];        //跳过重复的前缀 
            }
        }
        else                              //回溯到上一个可能的前缀位置 
        {
            k=nextval[k];
        }
    }
}


int KMPIndex(SqString*& s,SqString*& t)         //KMP算法实验字符串匹配 
{
    int nextval[Maxsize],i=0,j=0;
    GetNextval(t,nextval);

    while(i<s->length && j<t->length)
    {
        if(j==-1 || s->date[i]==t->date[j])       //字符串匹配成功 
        {
            i++;
            j++;
        }
        else                       //跳过相等的字符，继续匹配 
        {
            j=nextval[j];
        }
    }

    if(j>=t->length) return i-t->length;
    else return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SqString *S,*T;

    char a[50]="asdjoasjdoawjdoajsdoajsda";
    char b[10]="jdoa";

    int n=0;
    int m=0;

    for(int i=0;;i++)
    {
        if(a[i]=='\0') break;
        n++;
    }

    for(int i=0;;i++)
    {
        if(b[i]=='\0') break;
        m++;
    }

    CreatSqString(S,a,n);
    CreatSqString(T,b,m);

    if(KMPIndex(S,T)!=-1)
    {
        cout<<"能成功开锁"<<endl;
    }
    else
    {
        cout<<"不能成功开锁"<<endl;
    }

    return 0;
}
