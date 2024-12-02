#include <stdio.h>
#include <stdlib.h>
int mp[100][100];
int value[100][100];
int mark[100][100];
struct node
{
    int x,y;
} s[200];
struct noded
{
    int kx,ky;
    int e;
} ss[200];
struct noda
{
    int xx,yy;
} chu[200];
int n,m,k,d;
typedef struct
{
    int x,y;
    int step;
} element;
typedef struct
{
    element data[1000100];
    int front;
    int rear;
} queue;
void init(queue*q)
{
    q->front=0;
    q->rear=0;
}
int empty(queue*q)
{
    return q->rear==q->front;
}
void en(queue*q,element x)
{
    q->rear++;
    q->data[q->rear]=x;

}
element qu(queue*q)
{
    element temp;
    if(q->front==0)
    {
        q->front++;
        temp=q->data[q->front];
    }
    else
    {
        temp=q->data[q->front];
        q->front++;
    }
    //q->front++;
    return temp;
}
queue q;
int aa[8]= {0,0,-1,1};
int bb[8]= {-1,1,0,0};
void bfs(int chux,int chuy)
{

    element temp= {chux,chuy,0};
    init(&q);
    en(&q,temp);
    while(empty(&q)==0)
    {
        temp=qu(&q);
        int i;
        if(mp[temp.x][temp.y]>0)
        {
            int xian=temp.step*mp[temp.x][temp.y];
            if(xian<value[temp.x][temp.y])
            {
                value[temp.x][temp.y]=xian;
            }
        }
        for(i=0; i<4; i++)
        {
            int fx=temp.x+aa[i];
            int fy=temp.y+bb[i];
            int fstep=temp.step+1;
            if(fx>0&&fy>0&&fx<=n&&fy<=n&&mp[fx][fy]!=-1&&mark[fx][fy]!=1)
            {
                element ne= {fx,fy,fstep};

                en(&q,ne);
            }
        }
    }
}
int main()
{

    scanf("%d %d %d %d",&n,&m,&k,&d);
    int i;
    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&s[i].x,&s[i].y);
        //printf("%d",s[i].x);
    }
    for(i=1; i<=k; i++)
    {
        scanf("%d %d %d",&ss[i].kx,&ss[i].ky,&ss[i].e);
        //printf("%d",ss[i].kx);
    }
    for(i=1; i<=d; i++)
    {
        scanf("%d %d",&chu[i].xx,&chu[i].yy);
    }
    int j,kk;
    ///value chushihua
    for(i=1; i<=d; i++)
    {
        mp[chu[i].xx][chu[i].yy]=-1;
    }
    for(i=1; i<=k; i++)
    {
        mp[ss[i].kx][ss[i].ky]+=ss[i].e;
        value[ss[i].kx][ss[i].ky]=0x3f3f3f3f;
    }
    for(j=1; j<=m; j++)
    {
        for(i=1; i<=n; i++)
        {
            for(kk=1; kk<=n; kk++)
            {
                mark[i][k]=0;
            }
        }
        int aa=s[j].x;
        int bb=s[j].y;
        bfs(aa,bb);
    }
    int sum=0;
    for(i=1; i<=k; i++)
    {
        sum+=value[ss[i].kx][ss[i].ky];
    }
    printf("%d",sum);
    return 0;
}

