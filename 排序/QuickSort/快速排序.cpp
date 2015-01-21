//快速排序。partI是按课本上的方法进行pivot的选取
//partII是比较常见的写法。
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <ctime>
using namespace std;

int num[100000000];
int FindPivot(int num[],int low,int high) //使用左边两个不同关键字的较大者的下标，作为主元。
{
    int t;
    t=num[low];
    for(int j=low+1;j<=high;j++)
    {
        if(num[j]>t)return j;
        else if(num[j]<t)return low;
    }
    return -1; //若数组中的元素大小都相同，则返回-1
}

int Partition(int num[],int low,int high) //划分。课本上这种划分比官方的还要快2~3倍。但一遍并不能将pivot放到合适的位置上
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
    return l; //返回pivotpos+1(右子序列起始下标)
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
int Partition(int numbers[],int left,int right) //划分。这样的划分方式，一遍总能将pivot放到合适的位置
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
    return left; //返回pivotpos
}

void QuickSort(int elem[],int low,int high)
{
    int pivotpos;
    if(low<high)
    {
        pivotpos=Partition(elem,low,high);
        QuickSort(elem,low,pivotpos-1);
        QuickSort(elem,pivotpos+1,high);  //pivot已找到了自己的位置，以后的排序不必再参加
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
/*************原来的算法效率要比正常快排低三倍多*******************/
/**问题出在partition函数那里。导致效率差了一个常数**/
/****************下面是官方算法********************

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
