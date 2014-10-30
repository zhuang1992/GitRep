#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>
#define MAXN 1000000
#define MAXB 1000
using namespace std;
struct bucket
{
    int cnt;
    int content[MAXB];
} buckets[10];

int num[MAXN];
int getdigit(int a,int i)
{
    while(--i&&i>0)
    {
        a/=10;
    }
    return a%10;
}

void RadixSort(int n)
{
    int i,j,k,l;
    for(i=0; i<10; i++)
    {
        memset(buckets,0,sizeof(buckets));
        for(j=0; j<n; j++)
        {
            int t=getdigit(num[j],i);
            buckets[t].content[buckets[t].cnt++]=num[j];
        }
        j=0;
        for(k=0; k<10; k++)
        {
            for(l=0; l<buckets[k].cnt; l++)
            {
                num[j++]=buckets[k].content[l];
            }
        }
    }
}
int main()
{
    int n;
    DWORD take;
    scanf("%d",&n);
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;i++)
        num[i]=rand()%10000;

    take = GetTickCount();
    RadixSort(n);
    printf("\n%ld\n", GetTickCount() - take);//µ¥Î»ÊÇms

    return 0;
}
