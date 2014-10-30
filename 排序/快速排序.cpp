//��������partI�ǰ��α��ϵķ�������pivot��ѡȡ
//partII�ǱȽϳ�����д����
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <ctime>
using namespace std;

int num[100000000];
int FindPivot(int num[],int low,int high) //ʹ�����������ͬ�ؼ��ֵĽϴ��ߵ��±꣬��Ϊ��Ԫ��
{
    int t;
    t=num[low];
    for(int j=low+1;j<=high;j++)
    {
        if(num[j]>t)return j;
        else if(num[j]<t)return low;
    }
    return -1; //�������е�Ԫ�ش�С����ͬ���򷵻�-1
}

int Partition(int num[],int low,int high) //���֡��α������ֻ��ֱȹٷ��Ļ�Ҫ��2~3������һ�鲢���ܽ�pivot�ŵ����ʵ�λ����
{
    int t=FindPivot(num,low,high);
    if(t==-1)return -1;
    int pivot=num[t];

    int l,r;
    l=low;
    r=high;
    while(l<=r)
    {
        swap(num[l],num[r]);
        while(num[l]<pivot)
            l++;
        while(num[r]>=pivot)
            r--;
    }
    return l; //����pivotpos+1(����������ʼ�±�)
}

void QuickSort(int num[],int low,int high)
{
    int pivotpos;
    if(low<high)
    {
        pivotpos=Partition(num,low,high);
        if(pivotpos==-1)return;
        QuickSort(num,low,pivotpos-1);
        QuickSort(num,pivotpos,high);
    }
}

int main()
{

    int n;
    DWORD take;
    scanf("%d",&n);
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;i++)
        num[i]=rand();

    take = GetTickCount();

    QuickSort(num,0,n-1);

    printf("\n%ld\n", GetTickCount() - take);

}


/***************PartII***********************/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <windows.h>

using namespace std;


void swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
int Partition(int numbers[],int left,int right) //���֡������Ļ��ַ�ʽ��һ�����ܽ�pivot�ŵ����ʵ�λ��
{
    int pivot;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left < right)
        {
            numbers[left++] = numbers[right];
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left < right)
        {
            numbers[right--] = numbers[left];
        }
    }
    numbers[left] = pivot;
    return left; //����pivotpos
}

void QuickSort(int elem[],int low,int high)
{
    int pivotpos;
    if(low<high)
    {
        pivotpos=Partition(elem,low,high);
        QuickSort(elem,low,pivotpos-1);
        QuickSort(elem,pivotpos+1,high);  //pivot���ҵ����Լ���λ�ã��Ժ�����򲻱��ٲμ�
    }
}
int elems[100000000];
int main()
{

    int n;
    DWORD take;
    scanf("%d",&n);
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;i++)
        elems[i]=rand();

    take = GetTickCount();

    QuickSort(elems,0,n-1);

    printf("\n%ld\n", GetTickCount() - take);

}
/*************ԭ�����㷨Ч��Ҫ���������ŵ�������*******************/
/**�������partition�����������Ч�ʲ���һ������**/
/****************�����ǹٷ��㷨********************

void quickSort(int numbers[], int array_size)
{
    q_sort(numbers, 0, array_size - 1);
}



void q_sort(int numbers[], int left, int right)
{
    int pivot, l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        q_sort(numbers, left, pivot-1);
    if (right > pivot)
        q_sort(numbers, pivot+1, right);
}
*/
