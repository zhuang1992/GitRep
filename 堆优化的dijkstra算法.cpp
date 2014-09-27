//堆优化的dijkstra算法（手写堆）
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
const int MaxN = 30001;  //开这么大，在自己电脑上运行不起来，但在oj上可以
const int INF = 0x7fffffff/2 - 1;
typedef struct
{
    int dis , vex;
} ElemType;

typedef struct
{
    int vex , dis;  //vex是该边的终点,dis是该边的长度
}	Edge;

vector < Edge > edge[MaxN];  //edge[i].vex 表示从i指向vex的一条边

bool cmp(ElemType e1 , ElemType e2)
{
    return e1.dis < e2.dis;
}
class Heap     //小顶堆。即最小的元素总是在最上面
{
public:
    Heap()
    {
        n = 0;
    }
    int min(int _a , int _b)  //传入两个下标，返回对应的元素更小的那个下标
    {
        return a[_a].dis < a[_b].dis ? _a : _b;
    }
    void push(ElemType e)
    {
        for (i = ++ n; i > 1 && cmp(e , a[i >> 1]); i >>= 1)
        {
            a[i] = a[i >> 1];
        }
        a[i] = e;
    }
    void pop()
    {
        ElemType e = a[n];
        for (i = 2; i < n; i <<= 1)
        {
            if (i < n - 1)
            {
                i = min(i , i + 1);
            }
            if (cmp(e , a[i])) break;
            a[i >> 1] = a[i];
        }
        a[i >> 1] = a[n --];
    }
    ElemType top()
    {
        return a[1];
    }
    bool empty()
    {
        return !n;
    }
private:
    ElemType a[MaxN];
    int n , i;
};
void dijkstra(int nvex , int st,int end)
{
    Heap h;
    Edge e;
    ElemType  tmp;
    int dis[ MaxN ] , i , now; //dis[i]表示从起点st到点i的距离
    bool visited[ MaxN ] = {0};

    tmp.dis = 0;
    tmp.vex = st; //边tmp的终点初始化为st,长度初始化为0
    h.push(tmp);
    for (i = 0; i <= nvex; i ++)	dis[ i ] = INF;
    dis[ st ] = 0;
    while (!h.empty())
    {
        tmp = h.top();
        h.pop();
        now = tmp.vex;
        if (!visited[ now ])
        {
            visited[ now ] = true;
            for (i = 0; i < (int)edge[ now ].size(); i ++)
            {
                e = edge[ now ][ i ]; //以now为起点的边的集合里面第i个元素（now也是上条边的终点。这样就连起来了）
                if (!visited[ e.vex ])
                {
                    if(dis[ now ] + e.dis < dis[ e.vex ])
                    {
                        dis[e.vex] = dis[ now ] + e.dis; //松弛操作
                        tmp.dis = dis[e.vex];    //tmp储存了从st已到达的点及经过的总长度
                        tmp.vex = e.vex;
                        h.push(tmp);
                    }
                }
            }
        }
    }
    if (dis[ end ] == INF) //无法到达
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n" , dis[ end ]);
    }

}
int main()
{
    Edge e;
    int n , m , i , a , b ;
    int st,end;
    while(scanf("%d%d" , &n , &m)!=EOF)
    {
        for (i=0; i<=n; i++)
        {
            edge[i].clear();
        }
        for (i = 0; i < m; i ++)
        {
            scanf("%d%d%d" , &a , &b , &e.dis);
            e.vex = b;
            edge[a].push_back(e);
            //   e.vex = a;      //  若是无向图，则这个边也要存上。
            //   edge[b].push_back(e);
        }
        scanf("%d %d" , &st,&end);
        dijkstra(n , st,end);
    }
    return 0;
}

//以下使用的是STL里面的priority_queue进行的优化
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MaxN = 201;
const int INF = 0x7fffffff / 2;
typedef struct {	int l , v;	}	Edge;
typedef vector < Edge > VE;
struct Vex	{
	int v , dis;
	friend bool operator<(Vex v1 , Vex v2)	{
		return v1.dis > v2.dis;
	}
};
VE e[ MaxN ];
priority_queue < Vex > Q;

int dijkstra(VE *e , int n , int st , int ed)
{
	int dis[ MaxN ] , i;
	bool visited[ MaxN ] = { 0 };
	for (i = 0;i < n;i ++)	{
		dis[ i ] = INF;
	}

	Vex now , next;
	now.dis = dis[ now.v = st ] = 0;
	Edge et;
	while (!Q.empty())	Q.pop();
	Q.push(now);
	while (!Q.empty())	{
		now = Q.top();Q.pop();
		if (!visited[ now.v ])	{
			visited[ now.v ] = true;
			for (i = 0;i < e[ now.v ].size();i ++)	{
				et = e[ now.v ][ i ];
				next.v = et.v;
				if (!visited[ et.v ] && et.l + dis[ now.v ] < dis[ et.v ])	{
					next.dis = dis[ next.v = et.v ] = et.l + dis[ now.v ];
					Q.push(next);
				}
			}
		}
	}
	for (i = 0;i < n;i ++)	{
		if (dis[ i ] == INF)	{
			printf("-1 ");
		}	else	{
			printf("%d " , dis[ i ]);
		}
	}
	return dis[ ed ];
}

void __test()
{
	Edge ed;
	int n , m , i , a , b , c;

	scanf("%d%d" , &n , &m);
	for (i = 0;i < n;i ++)	{
		e[i].clear();
	}
	for (i = 0;i < m;i ++)	{
		scanf("%d%d%d" , &a , &b , &ed.l);
		ed.v = b;e[a].push_back(ed);
		ed.v = a;e[b].push_back(ed);
	}
	scanf("%d %d" , &a , &b);
	dijkstra(e , n , a , b);
}
int main()
{
	__test();
}
/*
8 9
0 1 5
1 2 8
1 3 7
1 5 4
4 5 6
5 6 7
6 7 3
1 7 2
1 6 1
2 3
3 3
0 1 5
0 2 1
1 2 3
0 1
4 5
0 1 1
0 2 2
0 3 5
1 2 1
1 3 2
0 1
*/
