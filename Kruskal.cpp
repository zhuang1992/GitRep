//poj1861,记录了树中有哪些边，及这些边的最大值
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXNODE 1500
#define MAXEDGE 16000
using namespace std;
int parent[MAXNODE]; //每个集合的leader
int rank[MAXNODE]; //每个集合的秩
struct Edge
{
    int from,to,cost;
} edge[MAXEDGE]; //池子法建图


void MakeSet(int n)
{
    memset(rank,0,sizeof(rank));
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
    }
}
int FindParent(int x) //带路径压缩的FindParent。往上走一趟，找leader，再往下走回来，将查找路径上所有节点的parent都指向leader.
{
    if(x!=parent[x])
        parent[x]=FindParent(parent[x]);
    return parent[x];
}

bool cmp (Edge a,Edge b)
{
    if(a.cost!=b.cost)
        return a.cost<b.cost;
    else if(a.from!=b.from)
        return a.from<b.from;
    return a.to<=b.to;
}
int path[MAXNODE];
void Kruskal(int n,int m,int &ans,int &num,int &maxe) //kruskal是将所有“点”，分别看成一个集合
{
    int j=0;
    MakeSet(n);
    sort(edge,edge+m,cmp);
    for(int i=0; i<n-1; i++) //循环一次，加入一条边。MST要加入n-1条边。
    {
        int pf,pt;
        while(1) //用来找下一条应该加入的边
        {
            pf=FindParent(edge[j].from);
            pt=FindParent(edge[j].to);
            if(pf!=pt) //只要数据没问题，不会出现边所有边都用完了，还没加够n-1条边的情况。所以这里不用担心死循环。
            {
                //下标为j的边加入了MST
                ans+=edge[j].cost;
                maxe=max(maxe,edge[j].cost);
                path[num++]=j;
                break;
            }
            j++;
        }
        parent[pt]=pf; //union操作
    }
    return;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].cost);
    }
    int ans=0;
    int maxe=-1;
    int num=0;
    Kruskal(n,m,ans,num,maxe);
    printf("%d\n",maxe);
    printf("%d\n",num);
    for(int i=0; i<num; i++)
    {
        printf("%d %d\n",edge[path[i]].from,edge[path[i]].to);
    }
    return 0;
}
