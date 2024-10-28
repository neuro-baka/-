#include<bits/stdc++.h>

using namespace std;

#define MaxSize 50

#define ElemType node

struct node
{
    int x;
    int y;
    int step;
};

typedef struct
{
    ElemType date[MaxSize];
    int front,rear;
}SqQueue;

const int N=10;

void InitQueue(SqQueue &Q)
{
    Q.rear=Q.front=0;
}

bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MaxSize==Q.front) //队满
    {
        return false;
    }

    Q.date[Q.rear]=x;
    Q.rear=Q.rear+1;
    return true;
}

bool DeQuque(SqQueue &Q,ElemType &x)
{
    if(Q.rear==Q.front)
        return false;
    x=Q.date[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}


bool GetHead(SqQueue Q,ElemType &x)
{
    if(Q.rear==Q.front)
    {
        return false;
    }

    x=Q.date[Q.front];
    return true;
}

bool QueueEmpty(SqQueue Q)
{
    if(Q.rear==Q.front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int n=10;
bool vis[N][N];

char g[10][10]=
{
    {'S','#','#','#','#','#','#','#','#','#'},
    {'#','0','#','#','0','0','0','#','#','#'},
    {'#','0','0','0','0','#','0','0','0','#'},
    {'#','0','0','#','#','#','#','#','0','#'},
    {'#','#','#','0','0','#','0','0','#','0'},
    {'#','#','#','0','0','#','#','0','0','0'},
    {'#','#','#','0','E','#','0','0','#','#'},
    {'#','#','#','#','#','#','0','#','#','#'},
    {'#','#','#','#','#','#','0','0','0','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

node pre[N][N];//前驱节点

int dx[4]= {0,0,-1,1};
int dy[4]= {-1,1,0,0};

node tar;
node start;

bool f=false;

vector<node> vec;

int Max;

map<int,vector<pair<int,int>> > mp;

void bfs(int x,int y)
{
    SqQueue q;

    InitQueue(q);
    EnQueue(q,{x,y,0});

    vis[x][y]=true;

    while(!QueueEmpty(q))
    {
        ElemType u;
        GetHead(q,u);

        ElemType v;
        DeQuque(q,v);

        mp[u.step].push_back({make_pair(u.x,u.y)});

        for(int i=0; i<4; i++)
        {
            int X=u.x+dx[i];
            int Y=u.y+dy[i];

            if(g[X][Y]=='0' || X<0 || Y<0 || X>=n || Y>=n || vis[X][Y]) continue;

            vis[X][Y]=true;
            pre[X][Y]=u;

            if(X==tar.x && Y==tar.y)
            {
                Max=u.step+1;
                mp[Max].push_back(make_pair(X,Y));
                f=true;
                break;
            }

            EnQueue(q,{X,Y,u.step+1});
        }
    }

}

void print(node T)
{
    if(T.x==start.x && T.y==start.y)
    {
        printf("(%d,%d)\n",T.x,T.y);
        return;
    }
    print(pre[T.x][T.y]);
    printf("(%d,%d)\n",T.x,T.y);
}

void print2()
{
    for(int i=1;i<=Max;i++)
    {
        cout<<"通过"<<i<<"步所能到达的点有"<<endl;

        for(auto it:mp[i])
        {
            cout<<"("<<it.first<<","<<it.second<<")"<<" ";
        }

        cout<<endl;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(g[i][j]=='S')
            {
                start=node{i,j};
            }

            if(g[i][j]=='E')
            {
                tar=node{i,j};
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    bfs(start.x,start.y);

    if(f==false)
    {
        cout<<"未能找到路径"<<endl;
    }
    else
    {
        printf("最短路径为:\n");
        print(tar);
    }

    cout<<endl;

    cout<<"起点为"<<"("<<start.x<<","<<start.y<<")"<<endl;
    cout<<"起点为"<<"("<<tar.x<<","<<tar.y<<")"<<endl;

    cout<<endl;

    print2();

    return 0;
}
