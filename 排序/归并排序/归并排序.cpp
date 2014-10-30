//归并排序。自顶向下，分治的思想
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


void merge(int num[],int low,int mid,int high,int temp[])
{
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=high)
    {
        temp[k++]=num[i]<=num[j]?num[i++]:num[j++];
    }
    while(i<=mid)
    {
        temp[k++]=num[i++];
    }
    while(j<=high)
    {
        temp[k++]=num[j++];
    }
    for(int i=0;i<k;i++)
    {
        num[low+i]=temp[i];
    }
}

void mergesort(int num[],int low,int high,int temp[])
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(num,low,mid,temp);
        mergesort(num,mid+1,high,temp);
        merge(num,low,mid,high,temp);
    }
}
int MergeSort(int num[],int low,int high,int n)
{
    int* temp=new int[n]; //辅助空间O(n)
    if(temp==NULL)return -1;
    mergesort(num,low,high,temp);
    delete temp;
    return 0;
}

int main()
{
    int num[10]={34,65,241,43,241,241,445,4,11,87};
    MergeSort(num,0,9,10);
    for(int i=0;i<10;i++)
        printf("%d ",num[i]);
    return 0;
}
