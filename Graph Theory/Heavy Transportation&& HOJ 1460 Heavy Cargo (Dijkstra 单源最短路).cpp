/*题意：给出了城市数n,以及街道数m（街道是双向均可通行的）, 对于每一条街mi,给出它的两端的城市，以及所能承载的最大货物运输量。

要求输出，从城市1到城市n，最多能运输多少货物。


分析：无向、带权图的单源最短路问题。 但这里路径的定义变成了：这条路上权值最小的那段路 的权值（而非所有段的权值之和）。

我们的任务就是求出：每一条从1到n的路上，“路径” 的最大值。 这样，就成了求单源最长“路径”。

*/
//hoj 1653
//Dijkstra 单源最短路
//注意此题中路长的定义变成了，各段路的权值的最小值

#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
#define N 1005
#define MinN 0
using namespace std;

int map[N][N];

bool used[N];
int dis[N];
int main()
{
    int caseNum;
    scanf("%d",&caseNum);
    for(int t=1; t<=caseNum; t++) {

        memset(map,0,sizeof(map));  //初始化为零，是因为不相邻的两个点间的通货能力为0（不要惯性思维初始化为无穷大）
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++) {
            int s,e;
            scanf("%d %d",&s,&e);
            scanf("%d",&map[s][e]);
            map[e][s]=map[s][e];

        }

        memset(used,0,sizeof(used));

        for(int i=1; i<=n; i++) {
            dis[i]=map[1][i];        //dis[i]储存点i到源点1的路径
        }

        used[1]=1;
        int count=n;

        while(count--) {
            int m=MinN;
            int v;
            for(int i=2; i<=n; i++) {
                if(!used[i]&&m<dis[i]) {  //更新每个点到源点1的最大的距离（求最长路径）这里可以用堆优化
                    m=dis[i];
                    v=i;
                }
            }
            used[v]=1;
            for(int j=1; j<=n; j++) {
                dis[j]=max(dis[j],min(dis[v],map[v][j])); //转移方程
                //min(dis[v],map[v][j])获得的是1到j这条路的“路径”
                //max()用来更新点1到点j的最长路径      }
            }
            printf("Scenario #%d:\n",t);
            printf("%d\n\n",dis[n]);
        }
        return 0;
    }
