//本题中使用线段树求逆序数对的总数目，O(nlgn)。角度挺新颖。之后的调整过程就跟线段数无关了。
/*
Problem Description
The inversion number of a given number sequence a1, a2, ..., an is the number of pairs (ai, aj) that satisfy i < j and ai > aj.

For a given sequence of numbers a1, a2, ..., an, if we move the first m >= 0 numbers to the end of the seqence, we will obtain another sequence. There are totally n such sequences as the following:

a1, a2, ..., an-1, an (where m = 0 - the initial seqence)
a2, a3, ..., an, a1 (where m = 1)
a3, a4, ..., an, a1, a2 (where m = 2)
...
an, a1, a2, ..., an-1 (where m = n-1)

You are asked to write a program to find the minimum inversion number out of the above sequences.
 

Input
The input consists of a number of test cases. Each case consists of two lines: the first line contains a positive integer n (n <= 5000); the next line contains a permutation of the n integers from 0 to n-1.
 

Output
For each case, output the minimum inversion number on a single line.

Sample Input
10
1 3 6 9 0 8 5 7 4 2
 

Sample Output
16
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 5555;
int sum[maxn<<2];
void PushUP(int rt)                      //pushup的作用就是当子节点发生了变化，它的父节点（表示左右儿子之和）也相应地跟着变化
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    sum[rt] = 0;  //所有节点的值初始化为0
    if (l == r) return ;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
void update(int p,int l,int r,int rt)
{
    if (l == r)
    {
        sum[rt] ++;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p , lson);
                                                //注意这里p不是落在左儿子区间，就是落在右儿子区间。两者只能取其一
                                                //更新p所在区间
                                                //包含了p的所有区间，相应节点值都加1，表示这个区间里的元素数加1
    else update(p , rson);
    PushUP(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L , R , lson);
    if (R > m) ret += query(L , R , rson);
    return ret;
}
int x[maxn];
int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        build(0 , n - 1 , 1);
        int sum = 0;
        for (int i = 0 ; i < n ; i ++)
        {
            scanf("%d",&x[i]);
            sum += query(x[i] , n - 1 , 0 , n - 1 , 1);   //即刻查询区间[x[i],n-1]里面有多少个元素（即：在前面已插入的数中，找有几个比x[i]大的）
            update(x[i] , 0 , n - 1 , 1);
        }		
		//以下内容就与线段树无关了。
        int ret = sum;
        for (int i = 0 ; i < n ; i ++)
        {
            sum += (n -1- x[i]) - x[i] ;//把位于第一位的num[i]移到最后一位，则变化的逆序对数是在上一个序列（即num[i]为第一位的序列）的基础上加上比num[i]大的数的个数，再减去比num[i]小的数的个数（因为num[i]移到最后以后，只能与前面比他大的数构成逆序对，而在上一个序列中与num[i]构成逆序对的在此序列则没办法构成）。注意n个元素的数组是从0开始的。（即原来能与num[i]构成逆序对的，现在都不行了；原来不行的，现在都行了）
            ret = min(ret , sum);
        }
        printf("%d\n",ret);
    }
    return 0;
}