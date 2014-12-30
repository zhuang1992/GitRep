#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
const int maxn=10010;
int C[maxn];   //用num[i]做下标来检索树状数组。而num[i]的范围是<=32768
int lefts[maxn];
int num[maxn];


int lowbit(int x)
{
    return x&(-x);
}

void insert(int pos)       //注意C[0]不能使用。这个函数的作用是在C[pos]处加1，表示这里有数字。这是树状数组的灵活运用
{
    while(pos <= maxn)
    {
        C[pos] ++;
        pos += lowbit(pos);
    }
}

int sum(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += C[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int res=0;
        memset(C,0,sizeof(C));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            res+=sum(n)-sum(num[i]);
            insert(num[i]+1); //注意C[0]这个位置不可用。因此当num[i]=0时，不行。所以将所有数都加1，这样不会影响逆序数
        }
        int final;
        final=res;

        for (int i=1;i<=n ; i++)
        {
            res += (n -1- num[i]) - num[i] ;//把位于第一位的num[i]移到最后一位，则变化的逆序对数是在上一个序列
            //（即num[i]为第一位的序列）的基础上加上比num[i]大的数的个数，再减去比num[i]小的数的个数
            //（因为num[i]移到最后以后，只能与前面比他大的数构成逆序对，而在上一个序列中与num[i]构成逆序对的在此序列则没办法构成）。
            //注意n个元素的数组是从0开始的。
            final = min(res , final);
        }
        printf("%d\n",final);
    }
}