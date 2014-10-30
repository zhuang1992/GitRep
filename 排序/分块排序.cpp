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
int DivideBlocks(int num[],int n,Index index[],int &blocksL) //���ֳɿ�
{
    int blocksnum=sqrt(n)+1;
    blocksL=n/blocksnum; //ÿһ��blocks�����Ԫ�ظ��������鳤
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
    if(n%blocksL!=0)index[j].key=maxn; //������һ��Ͱװ��������for�����Ǹ�if����ȥ�������ﲹ��index[j].key
    return blocksnum;//���طֵĿ���
}
int Block_Search(int num[],int key,int n,Index index[],int blocksnum,int blocksL) //numΪ����������,nΪ������Ԫ�ظ�����blocksnum�ǿ�����blocksL��ÿһ��ĳ���
{
    int i,j;
    i=0;
    while(key>index[i].key&&i<blocksnum)i++;
    if(i<blocksnum)
    {
        j=i*blocksL;
        while(key!=num[j]&&(j<(i+1)*blocksL)&&(j<n))j++;
        if(key==num[j])return j;    //����ҵ����򷵻ظ����������е��±�
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
