// spfa是BellmanFord的改进。但spfa没有判断负权回路的功能，需要事先判断好，否则spfa不能正常工作。
//因为spfa要用到，与某个点相邻的所有边，因此建图的时候要注意保存这一信息。
//池子法里的first数组可以记录这一信息
//增设一个cnt[]数组，用来记录每一个点入队的次数，若入队次数超过n(结点数)，则说明存在负权回路，retrun infanity。
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXNODE 1000
#define MAXEDGE 16000
#define INF 25000000;//这里要注意，不能太大，因为spfa里会出现(inf+边长)，太大的话会越界。
using namespace std;
struct Edge
{
    int from,to,cost,next;
} edge[MAXEDGE];
int first[MAXNODE];

queue <int> Q;
int dis[MAXNODE];
bool inqueue[MAXNODE];
int spfa(int n,int m)//n为点数，m为边数
{
    dis[0]=0; //0是源点
    //  int ans=0;
    memset(inqueue,0,sizeof(inqueue));
    for(int i=1; i<n; i++)
    {
        dis[i]=INF;
    }
    inqueue[0]=true;
    while(!Q.empty())Q.pop();
    Q.push(0);
    int t;
    while(!Q.empty())
    {
        t=Q.front();
        Q.pop();
        inqueue[t]=false;
        if(first[t]==-1)continue;
        Edge et=edge[first[t]];
        while(1) //对在队列的里的点进行松弛
        {
            if(dis[et.to]>dis[et.from]+et.cost)
            {
                dis[et.to]=dis[et.from]+et.cost;
                if(!inqueue[et.to])
                {
                    Q.push(et.to);
                    inqueue[et.to]=1;
                }
            }
            if(et.next==-1)break;
            else et=edge[et.next];
        }
    }
    return 0;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    memset(first,-1,sizeof(first));
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].cost); //这里存的是有向图
        edge[i].next=first[edge[i].from]; //头插
        first[edge[i].from]=i;//存储边的下标
    }

    spfa(n,m);
    for(int i=0; i<n; i++)
    {
        printf("%d\n",dis[i]);
    }

    return 0;
}
