#include<bits/stdc++.h>

using namespace std;

#define Maxsize 100000

typedef struct
{
    char date[Maxsize];
    int length;
}SqString;

void CreatSqString(SqString *&String,char a[],int n)
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



void GetNextval(SqString*& t,int nextval[])
{
    int j=0,k=-1;
    nextval[0]=-1;

    while(j<t->length-1)
    {
        if(k==-1 || t->date[j]==t->date[k])
        {
            j++;
            k++;

            if(t->date[j]!=t->date[k])
            {
                nextval[j]=k;
            }
            else
            {
                nextval[j]=nextval[k];
            }
        }
        else
        {
            k=nextval[k];
        }
    }
}


int KMPIndex(SqString*& s,SqString*& t)
{
    int nextval[Maxsize],i=0,j=0;
    GetNextval(t,nextval);

    while(i<s->length && j<t->length)
    {
        if(j==-1 || s->date[i]==t->date[j])
        {
            i++;
            j++;
        }
        else
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
    cin.tie(nullptr);

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
