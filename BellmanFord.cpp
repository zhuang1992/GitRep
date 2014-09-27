//BellmanFord 可以用来解决含负权边的单源最短路问题,有向、无向均可。但效率稍低，spfa是其改进。
//还可以单纯地用来判断图中是否有负权回路
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXNODE 1000
#define MAXEDGE 16000
#define INF 0x7ffffff;//这里要注意，不能太大，因为算法里会出现(inf+边长)，太大的话会越界。
using namespace std;
struct EDGE_BUMP
{
    int from,to,cost;
} edge[MAXEDGE];
int dis[MAXNODE];

bool bellmanford(int n,int m)//n为点数，m为边数
{
    dis[0]=0; //0是源点
    for(int i=1; i<n; i++)
    {
        dis[i]=INF;
    }
    for(int i=0; i<n; i++) //一条最短路若存在，最多不会超过n-1条边
    {
        for(int j=0; j<m; j++)
        {
            if(dis[edge[j].to]>dis[edge[j].from]+edge[j].cost)
                dis[edge[j].to]=dis[edge[j].from]+edge[j].cost;
        }
		for(int j=0; j<m; j++)
		{
			if(dis[edge[j].to]>dis[edge[j].from]+edge[j].cost)
				return false; //说明存在在负权环路。
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
/*首先指出，图的任意一条最短路径既不能包含负权回路，也不会包含正权回路，因此它最多包含|v|-1条边。
   其次，从源点s可达的所有顶点如果 存在最短路径，则这些最短路径构成一个以s为根的最短路径树。Bellman-Ford算法的迭代松弛操作，实际上就是按顶点距离s的层次，逐层生成这棵最短路径树的过程。
在对每条边进行1遍松弛的时候，生成了从s出发，层次至多为1的那些树枝。也就是说，找到了与s至多有1条边相联的那些顶点的最短路径；对每条边进行第2遍松弛的时候，生成了第2层次的树枝，就是说找到了经过2条边相连的那些顶点的最短路径……。因为最短路径最多只包含|v|-1 条边，所以，只需要循环|v|-1 次。
每实施一次松弛操作，最短路径树上就会有一层顶点达到其最短距离，此后这层顶点的最短距离值就会一直保持不变，不再受后续松弛操作的影响。（但是，每次还要判断松弛，这里浪费了大量的时间，怎么优化？单纯的优化是否可行？）
如果没有负权回路，由于最短路径树的高度最多只能是|v|-1，所以最多经过|v|-1遍松弛操作后，所有从s可达的顶点必将求出最短距离。如果 d[v]仍保持 +∞，则表明从s到v不可达。
如果有负权回路，那么第 |v|-1 遍松弛操作仍然会成功，这时，负权回路上的顶点不会收敛。
http://blog.csdn.net/logic_nut/article/details/4396518
*/