#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define BarrelSize 10
using namespace std;

typedef struct Barrel
{
    int cnt;
    int node[BarrelSize];
}barrel;

void Bucket_Sort(int num[],int n)
{
    int min,max,barrelnum;
    barrel* pBarrel;
    max=min=num[0];
    for(int i=0;i<n;i++)
    {
        if(num[i]>max)max=num[i];
        else if(num[i]<min)min=num[i];
    }
    barrelnum=(max-min+1)/BarrelSize+1;  //����Ͱ������
    pBarrel=new barrel[barrelnum];//��������Ҫ��Ͱ���������������ڴ�
    memset(pBarrel,0,barrelnum*sizeof(barrel));
    int k;
    for(int i=0;i<n;i++)
    {
        k=(num[i]-min+1)/BarrelSize; //floor���������num[i]������Ͱ���
        (pBarrel+k)->node[(pBarrel+k)->cnt]=num[i]; //pBarrel+k��pBarrel[k]
        (pBarrel+k)->cnt++;
    }
    int pos=0;
    for(int i=0;i<barrelnum;i++)
    {
        sort((pBarrel+i)->node,(pBarrel+i)->node+(pBarrel+i)->cnt);//��ÿһ��Ͱ��������
        for(int j=0;j<(pBarrel+i)->cnt;j++)
        {
            num[pos++]=(pBarrel+i)->node[j];
        }
    }
    delete pBarrel; //�ͷŸ����ռ�
}
int main()
{
    int data[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 91}, i;
    int size = sizeof(data) / sizeof(int);
    Bucket_Sort(data, size);

    for (i = 0; i < size; i++)
        printf("%d ", data[i]);
}
