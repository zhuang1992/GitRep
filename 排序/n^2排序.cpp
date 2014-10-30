#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>
#define INF 0x7fffffff
#define MAXN 1000000
using namespace std;
int num[MAXN];
void swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
void SelectionSort(int n)
{
    for(int k=0; k<n; k++)
    {
        int minn=num[k];
        int minkey=k;
        for(int i=k+1; i<n; i++)
        {
            if(minn>num[i])
            {
                minn=num[i];
                minkey=i;
            }
        }
        if(k!=minkey)
            swap(num[k],num[minkey]);
    }
}

void InsertSort(int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i;
        while(num[j]<num[j-1])
        {
            swap(num[j],num[j-1]);
            j--;
            if(j==0)break;
        }
    }
}
void BubbleSort(int n)
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if(num[i]>num[j])swap(num[i],num[j]);
        }
}
int main()
{
    int n;
    DWORD take;
    scanf("%d",&n);
    srand((unsigned int)time(NULL));
    for(int i=0; i<n; i++)
        num[i]=rand()%10000;

    take = GetTickCount();
    BubbleSort(n);
    printf("\n%ld\n", GetTickCount() - take);//µ¥Î»ÊÇms
    for(int i=0; i<n; i++)
        printf("%d ",num[i]);
    return 0;
}
