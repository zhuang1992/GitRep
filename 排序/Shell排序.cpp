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
        //�����������
        for(i=gap;i<n;i++)
        {
            j=i;
            if(num[j-gap]>num[j]) //��num[j]���ڵ����У�num[j]С��������ǰ����Ǹ���,���Ҫ���е���
            {
                int temp=num[j];
                do
                {
                    if(j>=gap)
                        num[j]=num[j-gap];
                    j-=gap; //�����ڣ�j��ǰһ��Ԫ�ز���j-1������j-gap
                }while(j>=0&&temp<num[j]);
                num[j+gap]=temp;
            }
            /*����Ҳ�У���һ�㣬��Ϊ����������
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
