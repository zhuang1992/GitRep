//HDOJ 1698
/*
Input
The input consists of several test cases. The first line of the input is the number of the cases. There are no more than 10 cases.
For each case, the first line contains an integer N, 1<=N<=100,000, which is the number of the sticks of Pudge’s meat hook and the second line contains an integer Q, 0<=Q<=100,000, which is the number of the operations.
Next Q lines, each line contains three integers X, Y, 1<=X<=Y<=N, Z, 1<=Z<=3, which defines an operation: change the sticks numbered from X to Y into the metal kind Z, where Z=1 represents the cupreous kind, Z=2 represents the silver kind and Z=3 represents the golden kind.
 

Output
For each case, print a number in a line representing the total value of the hook after the operations. Use the format in the example.
 

Sample Input
1
10
2
1 5 2
5 9 3
 

Sample Output
Case 1: The total value of the hook is 24.
*/

#include <iostream>
#include <cstdio>
#include <memory.h>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn=100010;
int sum[maxn<<2];         //sum[rt]储存的是rt所代表区间里所有钩子的价值
int col[maxn<<2];         //col[rt]储存的是第rt个钩子的价值

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];  //向上更新
}

void PushDown(int rt,int m)
{
    if (col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = (m - (m >> 1)) * col[rt];
        sum[rt<<1|1] = (m >> 1) * col[rt];
        col[rt] = 0;
    }
}

void build(int l,int r,int rt)
{
    sum[rt]=1;
    col[rt]=0;
    if (l == r)return;

    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);  //这个PushUP是在出递归的过程中被执行的。因此它是自叶子节点向根节点执行的。将叶子节点的信息向上更新到根节点。
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        col[rt] = c;
        sum[rt] = c * (r - l + 1);
        return ;
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (R > m) update(L , R , c , rson);
    PushUp(rt);
}
int main()
{
    int caseNum;
    cin>>caseNum;
    int t=0;
    while(caseNum--)
    {


        t++;
        int num;
        scanf("%d",&num);
        int op;
        scanf("%d",&op);
        build(1,num,1);
        while(op--)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            update(x,y,z,1,num,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",t,sum[1]);//sum[1]即表示1~n这一区间上所有钩子的价值总和
    }
    return 0;
}