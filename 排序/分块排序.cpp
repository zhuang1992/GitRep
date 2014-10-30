#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

struct Index
{
    int key;
}index[100];
int DivideBlocks(int num[],int n,Index index[],int &blocksL) //划分成块
{
    int blocksnum=sqrt(n)+1;
    blocksL=n/blocksnum; //每一个blocks里面的元素个数，即块长
    int maxn=-1;
    int j=0;
    for(int i=0;i<n;i++)
    {
        maxn=max(maxn,num[i]);
        if(i%blocksL==blocksL-1)
        {
            index[j].key=maxn;
            j++;
            maxn=-1;
        }
    }
    if(n%blocksL!=0)index[j].key=maxn; //如果最后一个桶装不满，则for里面那个if进不去，在这里补上index[j].key
    return blocksnum;//返回分的块数
}
int Block_Search(int num[],int key,int n,Index index[],int blocksnum,int blocksL) //num为待查找数组,n为数组中元素个数，blocksnum是块数，blocksL是每一块的长度
{
    int i,j;
    i=0;
    while(key>index[i].key&&i<blocksnum)i++;
    if(i<blocksnum)
    {
        j=i*blocksL;
        while(key!=num[j]&&(j<(i+1)*blocksL)&&(j<n))j++;
        if(key==num[j])return j;    //如果找到，则返回该数在数组中的下标
    }
    return -1;
}
int main()
{
    int num[6]={12,21,97,89,99,98};
    int blocksL;
    int nblocks=DivideBlocks(num,6,index,blocksL);
    for(int i=0;i<nblocks;i++)
    {
        printf("%d\n",index[i].key);
    }
    printf("%d\n",Block_Search(num,97,6,index,nblocks,blocksL));
    return 0;
}
