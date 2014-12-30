//用dfs实现了拓扑排序
//timef为时间戳，每一个顶点初始均为UNDISCOVERED状态。dfn记录了每一个顶点变成FOUND和FINISHED的时间。
//FOUND为第一次搜到这个点的时间
//FINISHED是DFS回溯回该顶点的时间
//最后按各顶点FINISHED时间降序排序，即为拓扑序列
//注意判圈的方式
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include "stack.h"
#define MAXNODE 100
using namespace std;
enum {UNDISCOVERED,FOUND,FINISHED};
struct DFN
{
    int id;
    int v;
    int l;
} dfn[MAXNODE];
typedef struct Node
{
    int adj;
    int cost;
    Node* next;
    Node()
    {
        adj=0;
        cost=0;
        next=NULL;
    }
} EdgeNode;
typedef struct Vnode
{
    EdgeNode* first_edge;
    int id;
    Vnode()
    {
        first_edge=NULL;
    }
} VertexNode;
VertexNode* Adjlist=new VertexNode[MAXNODE];
void AddEdge(int s,int e,int w)
{
    EdgeNode* p=new EdgeNode();
    p->adj=e;
    p->cost=w;
    p->next=Adjlist[s].first_edge;
    Adjlist[s].first_edge=p;
}
int visited[MAXNODE];
int timef;
bool flag;
bool topo_dfs(int st)
{
    if(flag)return false;
    timef++;
    dfn[st].id=st;
    dfn[st].v=timef;
    visited[st]=FOUND;
    EdgeNode* p=Adjlist[st].first_edge;
    while(p!=NULL)
    {
        if(visited[p->adj]==FOUND) //如果找到了一个被发现但尚未被完成的点，则说明存在圈
        {
            flag=1;
            return false;
        }
        else if(visited[p->adj]==UNDISCOVERED)
            topo_dfs(p->adj);
        p=p->next;
    }
    dfn[st].l=++timef;
    visited[st]=FINISHED;
    return true;
}
bool cmp(DFN a,DFN b)
{
    return a.l>b.l;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        int s,e,w;
        scanf("%d %d %d",&s,&e,&w);
        AddEdge(s,e,w);
    }
    memset(dfn,0,sizeof(dfn));
    memset(visited,UNDISCOVERED,sizeof(visited));
    timef=0;
    flag=0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(!topo_dfs(i))
            {
                cout<<"Circle Exists!"<<endl;
                return 0;
            }
        }
    }
    for(int i=0; i<n; i++)
        cout<<i<<": "<<dfn[i].v<<" "<<dfn[i].l<<endl;
    cout<<endl;
    sort(dfn,dfn+n,cmp);
    for(int i=0; i<n; i++)
    {
        cout<<dfn[i].id<<" ";
    }
    return 0;
}
