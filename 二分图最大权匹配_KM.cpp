//by cainiao2hao
第二份代码中
//nx为二分图左边一部分点的个数，ny为右边部分点的个数
//lx,ly为标号
如果直接用的话需要给nx,ny赋值。




#include<stdio.h>
#include<iostream>
#include<cstring>
#define N 1005
#define INF 1000000000
using namespace std;
struct Pool
{
    int pre,k,v;
}p[N*N];
int v[N],num;
void add(int a,int b,int c)
{
    p[++num].pre=v[a];
    p[num].k=b;
    p[num].v=c;
    v[a]=num;
}

int n,m;
int nx,ny,lx[N],ly[N],mat[N],slack[N];
bool fx[N],fy[N];
bool crosspath(int x)
{
    if(fx[x])return false;
    fx[x]=true;
    for(int tmp=v[x],k;k=p[tmp].k,tmp;tmp=p[tmp].pre)
    {
        if(fy[k])continue;
        int d=lx[x]+ly[k]-p[tmp].v;
        if(!d)
        {
            fy[k]=true;
            if(!mat[k]||crosspath(mat[k]))
            {
                mat[k]=x;
                return true;
            }
        }else slack[k]=min(slack[k],d);
    }
    return false;
}
int km()
{
    memset(ly,0,sizeof(ly));
    for(int i=1;i<=nx;i++)
    {
        lx[i]=-INF;
        for(int tmp=v[i];tmp;tmp=p[tmp].pre)
            lx[i]=max(lx[i],p[tmp].v);
    }
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=nx;i++)
    {
        memset(slack,0x3f,sizeof(slack));
        while(1)
        {
            memset(fx,false,sizeof(fx));
            memset(fy,false,sizeof(fy));
            if(crosspath(i))break;
            int val=INF;
            for(int tmp=v[i],k;k=p[tmp].k,tmp;tmp=p[tmp].pre)
                if(!fy[k])val=min(val,slack[k]);
            for(int j=1;j<=nx;j++)
                lx[j]-=fx[j]?val:0;
            for(int j=1;j<=ny;j++)
                if(fy[j])ly[j]+=val;
                else slack[j]-=val;
        }
    }
    int ans=0;
    for(int i=1;i<=ny;i++)
        ans+=lx[mat[i]]+ly[i];
    return ans;
}

void build()
{
    while(m--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        memset(v,0,sizeof(v));
        num=0;
        build();
        printf("%d\n",km());
    }
    return 0;
}