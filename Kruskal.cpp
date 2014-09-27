//poj1861,��¼����������Щ�ߣ�����Щ�ߵ����ֵ
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXNODE 1500
#define MAXEDGE 16000
using namespace std;
int parent[MAXNODE]; //ÿ�����ϵ�leader
int rank[MAXNODE]; //ÿ�����ϵ���
struct Edge
{
    int from,to,cost;
} edge[MAXEDGE]; //���ӷ���ͼ


void MakeSet(int n)
{
    memset(rank,0,sizeof(rank));
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
    }
}
int FindParent(int x) //��·��ѹ����FindParent��������һ�ˣ���leader���������߻�����������·�������нڵ��parent��ָ��leader.
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
void Kruskal(int n,int m,int &ans,int &num,int &maxe) //kruskal�ǽ����С��㡱���ֱ𿴳�һ������
{
    int j=0;
    MakeSet(n);
    sort(edge,edge+m,cmp);
    for(int i=0; i<n-1; i++) //ѭ��һ�Σ�����һ���ߡ�MSTҪ����n-1���ߡ�
    {
        int pf,pt;
        while(1) //��������һ��Ӧ�ü���ı�
        {
            pf=FindParent(edge[j].from);
            pt=FindParent(edge[j].to);
            if(pf!=pt) //ֻҪ����û���⣬������ֱ����б߶������ˣ���û�ӹ�n-1���ߵ�������������ﲻ�õ�����ѭ����
            {
                //�±�Ϊj�ı߼�����MST
                ans+=edge[j].cost;
                maxe=max(maxe,edge[j].cost);
                path[num++]=j;
                break;
            }
            j++;
        }
        parent[pt]=pf; //union����
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
