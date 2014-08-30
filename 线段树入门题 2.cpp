//HDOJ1166
/*
Input
第一行一个整数T，表示有T组数据。
每组数据第一行一个正整数N（N<=50000）,表示敌人有N个工兵营地，接下来有N个正整数,第i个正整数ai代表第i个工兵营地里开始时有ai个人（1<=ai<=50）。
接下来每行有一条命令，命令有4种形式：
(1) Add i j,i和j为正整数,表示第i个营地增加j个人（j不超过30）
(2)Sub i j ,i和j为正整数,表示第i个营地减少j个人（j不超过30）;
(3)Query i j ,i和j为正整数,i<=j，表示询问第i到第j个营地的总人数;
(4)End 表示结束，这条命令在每组数据最后出现;
每组数据最多有40000条命令
 

Output
对第i组数据,首先输出“Case i:”和回车,
对于每个Query询问，输出一个整数并回车,表示询问的段中的总人数,这个数保持在int以内。
*/

#include <iostream>
#include <cstdio>

#define lson l , m , rt << 1  //左儿子的rt=根的rt*2,rt是当前子树的根。也就是当前所在的节点编号。这样的运算，可以保证编号从根结点开始，保持1,2,3,4,5...
#define rson m + 1 , r , rt << 1 | 1  //右儿子rt=根的rt*2+1
const int maxn = 55555;
int sum[maxn<<2];         //sum[rt]储存了编号为rt的节点里的信息
void PushUP(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];  //向上更新
}

void build(int l,int r,int rt)//递归实现线段树的构造。让根节点表示区间[0,N-1]，即所有N个数所组成的一个区间，然后，把区间分成两半，分别由左右子树表示。
{
    if (l == r)             //一直到左界==右界。这就到了叶子节点。
    {
        scanf("%d",&sum[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);  //这个PushUP是在出递归的过程中被执行的。因此它是自叶子节点向根节点执行的。将叶子节点的信息向上更新到根节点。
}

void update(int p,int add,int l,int r,int rt)       //单点更新。表示第p个位置增加add个人。
{
    if (l == r)
    {
        sum[rt] += add;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p , add , lson);
    else update(p , add , rson);
    PushUP(rt);
}

int query(int L,int R,int l,int r,int rt)                //查询从L到R这段区间上的和
{
    if (L <= l && R>=r)       //如果目标区间[L,R]包含了当前查询区间[l,r]，说明要查询的(部分)内容就在sum[rt]（rt是[l,r]所在区间的编号）
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L , R , lson); //和左儿子有交集，则去左儿子查找    就是这里实现了求和的功能
    if (R > m) ret += query(L , R , rson);//和右儿子有交集，去右儿子查找
    return ret;
}



int main() {
    int T , n;
    scanf("%d",&T);
    for (int cas = 1 ; cas <= T ; cas ++) {
        printf("Case %d:\n",cas);
        scanf("%d",&n);
        build(1 , n , 1);
        char op[10];
        while (scanf("%s",op)) {
            if (op[0] == 'E') break;
            int a , b;
            scanf("%d%d",&a,&b);
            if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));
            else if (op[0] == 'S') update(a , -b , 1 , n , 1);
            else update(a , b , 1 , n , 1);
        }
    }
    return 0;
}