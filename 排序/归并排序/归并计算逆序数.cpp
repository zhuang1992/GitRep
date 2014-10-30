
#include <iostream>
#include <cstdio>
#define MAXN 100005
using namespace std;

int tmp[MAXN];
typedef long long LL;
LL res;
int num[MAXN];
void merge(int left, int middle, int right)
{
     int i, j, k;
     i = left, j= middle+1, k = 1;
     while(i<= middle && j <= right)
     {
               if(num[j] < num[i])
               {
                    tmp[k++] = num[j++];
                    res += middle - i + 1;//归并排序的特点使得可以方便的记录逆序数。
                    //每一个j序列里的元素入队，说明此时i序列里面还没有入队的元素，都是该j元素的
                    //逆序之数，即它们比该j元素大，且在j元素的前面。middle-i+1即该数字的逆序数
               }
               else
                    tmp[k++] = num[i++];
     }

     while(i <= middle)  tmp[k++] = num[i++];
     while(j <= right) tmp[k++] = num[j++];

     for(i = left, k = 1; i<= right; i++, k++)
            num[i] = tmp[k];
}
void merge_sort(int left, int right)
{
     if(left < right)
     {
             int middle = (left + right)/2;
             merge_sort(left, middle);
             merge_sort(middle+1, right);
             merge(left, middle, right);
     }
}
