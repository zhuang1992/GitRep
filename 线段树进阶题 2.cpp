//poj3468
/*Description

You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. One type of operation is to add some given number to each number in a given interval. The other is to ask for the sum of numbers in a given interval.

Input

The first line contains two numbers N and Q. 1 ≤ N,Q ≤ 100000.
The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ≤ Ai ≤ 1000000000.
Each of the next Q lines represents an operation.
"C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
"Q a b" means querying the sum of Aa, Aa+1, ... , Ab.

Output

You need to answer all Q commands in order. One answer in a line.

Sample Input

10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output

4
55
9
15*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn=100010;
long long sum[maxn<<2];
long long add[maxn<<2];

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];  //向上更新
}

void PushDown(int rt,int m)
{
    if (add[rt])
    {
        add[rt<<1] += add[rt];           //注意这里是加减，而不是更新。所以用+=，而非=。
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt] * (m - (m >> 1));
		sum[rt<<1|1] += add[rt] * (m >> 1);
		add[rt] = 0;
    }
}

void build(int l,int r,int rt)
{
    add[rt]=0;
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return;
    }

    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);  //这个PushUp是在出递归的过程中被执行的。因此它是自叶子节点向根节点执行的。将叶子节点的信息向上更新到根节点。
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        add[rt] +=(long long) c;
        sum[rt] +=(long long) c * (r - l + 1);
        return ;                        //返回，子节点暂时不要更新
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (R > m) update(L , R , c , rson);
    PushUp(rt);
}

long long  query(int L,int R,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt , r - l + 1);                   //
    int m = (l + r) >> 1;
    long long ret = 0;
    if (L <= m) ret += query(L , R , lson);
    if (R > m) ret += query(L , R , rson);
    return ret;
}

int main()
{
    int n,q;
    while(scanf("%d %d",&n,&q)!=EOF)
    {
        build(1,n,1);
        while(q--)
        {
            char op;

            getchar();
            scanf("%c",&op);
            if(op=='Q')
            {
                int a,b;
                scanf("%d %d",&a,&b);
                long long ans=query(a,b,1,n,1);
                printf("%lld\n",ans);
            }
            else
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                update(a,b,c,1,n,1);
            }
        }
    }
    return 0;
}
