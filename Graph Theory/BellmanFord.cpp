//BellmanFord ���������������Ȩ�ߵĵ�Դ���·����,����������ɡ���Ч���Եͣ�spfa����Ľ���
//�����Ե����������ж�ͼ���Ƿ��и�Ȩ��·
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXNODE 1000
#define MAXEDGE 16000
#define INF 0x7ffffff;//����Ҫע�⣬����̫����Ϊ�㷨������(inf+�߳�)��̫��Ļ���Խ�硣
using namespace std;
struct EDGE_BUMP
{
    int from,to,cost;
} edge[MAXEDGE];
int dis[MAXNODE];

bool bellmanford(int n,int m)//nΪ������mΪ����
{
    dis[0]=0; //0��Դ��
    for(int i=1; i<n; i++)
    {
        dis[i]=INF;
    }
    for(int i=0; i<n; i++) //һ�����·�����ڣ���಻�ᳬ��n-1����
    {
        for(int j=0; j<m; j++)
        {
            if(dis[edge[j].to]>dis[edge[j].from]+edge[j].cost)
                dis[edge[j].to]=dis[edge[j].from]+edge[j].cost;
        }
		for(int j=0; j<m; j++)
		{
			if(dis[edge[j].to]>dis[edge[j].from]+edge[j].cost)
				return false; //˵�������ڸ�Ȩ��·��
		}
    }
    
    return true;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].cost);
    }
    if(!bellmanford(n,m))printf("Infanity");
    else
    {
        for(int i=0; i<n; i++)
        {
            printf("%d\n",dis[i]);
        }
    }
    return 0;
}
/*����ָ����ͼ������һ�����·���Ȳ��ܰ�����Ȩ��·��Ҳ���������Ȩ��·�������������|v|-1���ߡ�
   ��Σ���Դ��s�ɴ�����ж������ �������·��������Щ���·������һ����sΪ�������·������Bellman-Ford�㷨�ĵ����ɳڲ�����ʵ���Ͼ��ǰ��������s�Ĳ�Σ��������������·�����Ĺ��̡�
�ڶ�ÿ���߽���1���ɳڵ�ʱ�������˴�s�������������Ϊ1����Щ��֦��Ҳ����˵���ҵ�����s������1������������Щ��������·������ÿ���߽��е�2���ɳڵ�ʱ�������˵�2��ε���֦������˵�ҵ��˾���2������������Щ��������·����������Ϊ���·�����ֻ����|v|-1 ���ߣ����ԣ�ֻ��Ҫѭ��|v|-1 �Ρ�
ÿʵʩһ���ɳڲ��������·�����Ͼͻ���һ�㶥��ﵽ����̾��룬�˺���㶥�����̾���ֵ�ͻ�һֱ���ֲ��䣬�����ܺ����ɳڲ�����Ӱ�졣�����ǣ�ÿ�λ�Ҫ�ж��ɳڣ������˷��˴�����ʱ�䣬��ô�Ż����������Ż��Ƿ���У���
���û�и�Ȩ��·���������·�����ĸ߶����ֻ����|v|-1��������ྭ��|v|-1���ɳڲ��������д�s�ɴ�Ķ���ؽ������̾��롣��� d[v]�Ա��� +�ޣ��������s��v���ɴ
����и�Ȩ��·����ô�� |v|-1 ���ɳڲ�����Ȼ��ɹ�����ʱ����Ȩ��·�ϵĶ��㲻��������
http://blog.csdn.net/logic_nut/article/details/4396518
*/