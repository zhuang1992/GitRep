/*题意：谣言在n个人之间传播，谣言从一个人传给另一个人需要一定时间（是有向图）。问谣言从哪个人开始传，传遍所有人所用时间最短（这里的时间指的是，传到最后一个人时所用的时间）。输出这个人的编号，及所需要时间。


分析：Dijkstra是用来求单源最短路的，而这里起点不确定。采用Floyd算法先对图进行收缩，O(n^3)的复杂度。对每个点，找到这个点做源点时，谣言传遍所有人所需要的“时间”，遍历所有点，找到最短的那个“时间”，复杂度为O(n^2)。


对于floyd算法：

算法描述：
(1) 用数组dis[i][j]来记录i,j之间的最短距离。初始化dis[i][j],若i=j则dis[i][j]=0,
若i,j之间有边连接则dis[i][j]的值为该边的权值，否则dis[i][j]的值为无穷大 。
(2) 对所有的k值从1到n，修正任意两点之间的最短距离，计算dis[i][k]+dis[k][j]的值，
若小于dis[i][j],则dis[i][j]= dis[i][k]+dis[k][j]，否则dis[i][j]的值不变。*/

void Floyd(int dis[n+1][n+1],int n)
{
    int i,j,k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j] = dis[i][k]+dis[k][j];
                }

}



#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7fffffff
using namespace std;
int map[105][105];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                map[i][j]=INF;
            }
        }
        for(int i=0; i<n; i++)map[i][i]=0;
        for(int i=0; i<n; i++)
        {
            int t;
            scanf("%d",&t);
            for(int j=0; j<t; j++)
            {
                int p;
                int d;
                scanf("%d %d",&p,&d);
                map[i][p-1]=d;
            }
        }

        for ( int k = 0; k < n; ++k )            //floyd对图进行收缩,map[i][j]储存的内容变成了i,j间最短的距离
        {
            for ( int i = 0; i <n; ++i )
            {
                for ( int j = 0; j <n; ++j )
                {
                    if(map[i][k]!=INF && map[k][j]!=INF)
                    {
                        if ( map[i][k] + map[k][j] < map[i][j] )
                        {
                            // 找到更短路径
                            map[i][j] = map[i][k] + map[k][j];
                        }
                    }
                }
            }
        }

        int minn,start;
        minn=INF;
        for(int i=0; i<n; i++)
        {
            int maxn=0;
            for(int j=0; j<n; j++)
            {
                maxn=max(map[i][j],maxn);  //以i为源点时，所需要消耗的“时间”（即传播到最远的那个人所需要时间）。<span style="white-space:pre">                  </span>   <span style="white-space:pre">                    </span>   //因为前面已经对图进行了收缩，map[i][j]储存的已经是i到j的最短距离了
            }
            if(minn>maxn)     //找到用时最短的那个源点
            {
                minn=maxn;
                start=i;
            }
        }
        if(minn==INF)printf("disjoint\n");
        else
        {
            printf("%d %d\n",start+1,minn);
        }

    }
    return 0;
}
