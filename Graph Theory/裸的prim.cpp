/*5 7
1 2 13
1 3 -5
1 4 3
4 3 7
4 5 -1
5 3 20
3 2 -10
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXNODE 500
#define MAXEDGE 2500
#define INF 0x7f
using namespace std;
int map[MAXNODE][MAXNODE];
int dis[MAXNODE];
bool visited[MAXNODE];
int prim(int n,int s) //s表示从s点开始生成MST
{
    int res=0;
    int cnt=n-1;
    memset(visited,0,sizeof(visited));
    for(int i=0; i<n; i++)
    {
        dis[i]=map[0][i];
    }
    visited[s]=1;
    while(cnt--)
    {
        int u=0;
        int tmp=0x7f7f7f7f;
        for(int i=1; i<n; i++)
        {
            if(tmp>dis[i]&&visited[i]==0)
            {
                tmp=dis[i];
                u=i;
            }
        }
        visited[u]=1;
        res+=dis[u];
        for(int i=0; i<n; i++)
        {
            if(dis[i]>map[u][i]&&visited[i]==0)
            {
                dis[i]=map[u][i];
            }
        }
    }
    return res;
}
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    memset(map,INF,sizeof(map));
    while(e--)
    {
        int es,ee,ew;
        scanf("%d %d %d",&es,&ee,&ew);
        map[es][ee]=ew;
        map[ee][es]=ew;
    }
    printf("%d ",prim(n,0));
    return 0;
}
