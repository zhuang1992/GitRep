// spfa��BellmanFord�ĸĽ�����spfaû���жϸ�Ȩ��·�Ĺ��ܣ���Ҫ�����жϺã�����spfa��������������
//��ΪspfaҪ�õ�����ĳ�������ڵ����бߣ���˽�ͼ��ʱ��Ҫע�Ᵽ����һ��Ϣ��
//���ӷ����first������Լ�¼��һ��Ϣ
//����һ��cnt[]���飬������¼ÿһ������ӵĴ���������Ӵ�������n(�����)����˵�����ڸ�Ȩ��·��retrun infanity��
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXNODE 1000
#define MAXEDGE 16000
#define INF 25000000;//����Ҫע�⣬����̫����Ϊspfa������(inf+�߳�)��̫��Ļ���Խ�硣
using namespace std;
struct Edge
{
    int from,to,cost,next;
} edge[MAXEDGE];
int first[MAXNODE];

queue <int> Q;
int dis[MAXNODE];
bool inqueue[MAXNODE];
int spfa(int n,int m)//nΪ������mΪ����
{
    dis[0]=0; //0��Դ��
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
        while(1) //���ڶ��е���ĵ�����ɳ�
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
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].cost); //������������ͼ
        edge[i].next=first[edge[i].from]; //ͷ��
        first[edge[i].from]=i;//�洢�ߵ��±�
    }

    spfa(n,m);
    for(int i=0; i<n; i++)
    {
        printf("%d\n",dis[i]);
    }

    return 0;
}
