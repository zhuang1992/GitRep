#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

void ShellSort(int num[],int n)
{
    int gap=n/2;
    int i,j;
    for(;gap>=1;gap/=2)
    {
        //分组插入排序
        for(i=gap;i<n;i++)
        {
            j=i;
            if(num[j-gap]>num[j]) //在num[j]所在的组中，num[j]小于组内它前面的那个数,因此要进行调整
            {
                int temp=num[j];
                do
                {
                    if(j>=gap)
                        num[j]=num[j-gap];
                    j-=gap; //在组内，j的前一个元素不是j-1，而是j-gap
                }while(j>=0&&temp<num[j]);
                num[j+gap]=temp;
            }
            /*这样也行，慢一点，因为交换次数多
            while(j-gap>0&&num[j]<num[j-gap])
            {
                swap(num[j],num[j-1]);
                j-=gap;
            }*/
        }
        //for(int k=0;k<n;k++)printf("%d ",num[k]);
        //putchar('\n');
    }
}

int main()
{
    int num[10]={34,65,241,43,241,241,445,4,11,87};
    ShellSort(num,10);
    return 0;
}
