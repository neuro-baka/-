#include<bits/stdc++.h>
using namespace std;
typedef struct{
  char a;
  int dis;
}data;
typedef struct
{
    data s[1000];
    int length;
}line;
void Create(line *&l,char name[],int diss[],int n)
{
    int i=1;
    l=(line *)malloc(sizeof(line));
    while(i<=n)
    {
      l->s[i].a=name[i];
      l->s[i].dis=diss[i];
      i++;
    }
    l->length=n;
}
void Add(line *&l,char name,int diss)
{
    int i=1;
    int now=l->length+1;

    l->s[now].a=name;
    l->s[now].dis=diss;

    l->length=now;
}
void Remove(line *&l,char oldname,int diss)
{
    int i;
    int n=l->length;
    int pos;
    for(i=1;i<=n;i++)
    {
        if(l->s[i].a==oldname&&diss==l->s[i].dis)
        {
            pos=i;
            break;
        }
    }
    for(i=pos+1;i<=n;i++)
    {
        l->s[i-1].a=l->s[i].a;
        l->s[i-1].dis=l->s[i].dis;
    }
    l->length=l->length-1;
}
void Change(line *&l,char oldname,char newname,int diss)
{
    int i;
    for(i=1;i<=l->length;i++)
    {
        if(l->s[i].a==oldname)
        {
            l->s[i].a=newname;
            l->s[i].dis=diss;
            return;
        }
    }
}
data Search(line *&l,char oldname,int diss)
{
    int i;
    for(i=1;i<=l->length;i++)
    {
        if(l->s[i].a==oldname&&l->s[i].dis==diss)
        {
            printf("search successfully at %d.\n",i);
            data temp;
            temp={oldname,diss};
            return temp;
        }
    }
    printf("search unsuccessfully\n");
}
void Suggest(line *l1,line *l2,char start,char last)
{
   ///cha zhao;
   ///找起点
   int i;
int   flag=0;
   int startpos,lastpos;
   for(i=1;i<=l1->length;i++)
   {
      if(l1->s[i].a==start)
      {
         flag++;
         startpos=i;
         break;
      }
   }
   ///找终点
   for(i=1;i<=l2->length;i++)
   {
       if(l2->s[i].a==last)
       {
           flag++;
           lastpos=i;
           break;
       }
   }
   if(flag<2)
   {
       cout<<"未找到合适路径"<<endl;
       return;
   }
   ///找中间点
   int j;
   for(i=startpos+1;i<=l1->length;i++)
   {
       for(j=1;j<lastpos;j++)
       {
           if(l1->s[i].a==l2->s[j].a)
           {
               cout<<"找到合适路径"<<endl;
              printf("在%c上一号车，在%c站中转上二号车，直达终点站%c\n",start,l1->s[i].a,last);
               return;
           }
       }
   }

}
void show(line *l)
{
    int i;
    for(i=1;i<=l->length;i++)
    {
        printf("%c %d\n",l->s[i].a,l->s[i].dis);
    }
    cout<<endl;
}
int main()
{
    line *line1;
    char name[20];
    int diss[20];
    name[1]='A';
    name[2]='B';
    name[3]='D';
    name[4]='D';
    diss[1]=0;
    diss[2]=500;
    diss[3]=20;
    diss[4]=10;
    Create(line1,name,diss,3);
    Add(line1,name[4],diss[4]);
    Remove(line1,name[4],diss[4]);
    Change(line1,name[3],'C',900);
    show(line1);
    line *line2;
    char name2[20];
    int diss2[20];
    name2[1]='D';diss2[1]=0;
    name2[2]='B';diss2[2]=600;
    name2[3]='E';diss2[3]=800;
    Create(line2,name2,diss2,3);
    show(line2);
    Suggest(line1,line2,'A','E');
    return 0;
}



