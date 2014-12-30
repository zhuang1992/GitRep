/*���⣺ҥ����n����֮�䴫����ҥ�Դ�һ���˴�����һ������Ҫһ��ʱ�䣨������ͼ������ҥ�Դ��ĸ��˿�ʼ������������������ʱ����̣������ʱ��ָ���ǣ��������һ����ʱ���õ�ʱ�䣩���������˵ı�ţ�������Ҫʱ�䡣


������Dijkstra��������Դ���·�ģ���������㲻ȷ��������Floyd�㷨�ȶ�ͼ����������O(n^3)�ĸ��Ӷȡ���ÿ���㣬�ҵ��������Դ��ʱ��ҥ�Դ�������������Ҫ�ġ�ʱ�䡱���������е㣬�ҵ���̵��Ǹ���ʱ�䡱�����Ӷ�ΪO(n^2)��


����floyd�㷨��

�㷨������
(1) ������dis[i][j]����¼i,j֮�����̾��롣��ʼ��dis[i][j],��i=j��dis[i][j]=0,
��i,j֮���б�������dis[i][j]��ֵΪ�ñߵ�Ȩֵ������dis[i][j]��ֵΪ����� ��
(2) �����е�kֵ��1��n��������������֮�����̾��룬����dis[i][k]+dis[k][j]��ֵ��
��С��dis[i][j],��dis[i][j]= dis[i][k]+dis[k][j]������dis[i][j]��ֵ���䡣*/

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

        for ( int k = 0; k < n; ++k )            //floyd��ͼ��������,map[i][j]��������ݱ����i,j����̵ľ���
        {
            for ( int i = 0; i <n; ++i )
            {
                for ( int j = 0; j <n; ++j )
                {
                    if(map[i][k]!=INF && map[k][j]!=INF)
                    {
                        if ( map[i][k] + map[k][j] < map[i][j] )
                        {
                            // �ҵ�����·��
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
                maxn=max(map[i][j],maxn);  //��iΪԴ��ʱ������Ҫ���ĵġ�ʱ�䡱������������Զ���Ǹ�������Ҫʱ�䣩��<span style="white-space:pre">                  </span>   <span style="white-space:pre">                    </span>   //��Ϊǰ���Ѿ���ͼ������������map[i][j]������Ѿ���i��j����̾�����
            }
            if(minn>maxn)     //�ҵ���ʱ��̵��Ǹ�Դ��
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
