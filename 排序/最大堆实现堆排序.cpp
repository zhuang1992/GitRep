//最大堆。实现堆排序。
//包括MaxHeapify,BuildHeap,HeapSort函数
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <ctime>
#define MAXNODE 500

using namespace std;
typedef struct
{
    int key;
    //  char info;
} Node;
typedef struct heap
{
    int cnt;
    Node nodes[MAXNODE];
    heap()
    {
        memset(nodes,0,sizeof(nodes));
        cnt=0;
    }
} Heap;
bool HeapFull(Heap &h)
{
    return (h.cnt==MAXNODE-1);
}
bool HeapEmpty(Heap &h)
{
    return (h.cnt==0);
}
void swapNode(Node &a,Node &b)
{
    Node t;
    t=a;
    a=b;
    b=t;
}
void MaxHeapify(Heap &h,int i)
{
    int l=i<<1;
    int r=i<<1|1;
    int larger;
    if(l>h.cnt)larger=i;
    else if(h.nodes[l].key>h.nodes[i].key)
    {
        larger=l;
    }
    else larger=i;
    if(r<=h.cnt&&h.nodes[r].key>h.nodes[larger].key)
    {
        larger=r;
    }
    if(larger!=i)
    {
        swapNode(h.nodes[larger],h.nodes[i]);
        MaxHeapify(h,larger);
    } //以larger为根的子树又可能违反性质，因此递归调用MaxHeapify
}
void BuildMaxHeap(Heap &h)//原地进行建堆
{
    for(int i=(h.cnt/2)+1; i>=1; i--)
    {
        MaxHeapify(h,i); //对每一个非叶子节点都进行一次Heapify(注意是从下往上的顺序)。复杂度n/2*logn
    }
}
void HeapSort(Heap &h)
{
    BuildMaxHeap(h);
    for(int i=h.cnt;i>=2;i--)
    {
        swapNode(h.nodes[1],h.nodes[i]);
        h.cnt--;
        MaxHeapify(h,1);
    }
}
int main()
{
    Heap h;
    srand((unsigned)time(NULL));
    for(int i=1; i<=100; i++)
    {
        h.nodes[i].key=rand()%100;
        h.cnt++;
    }
    HeapSort(h);
    for(int i=1; i<=100; i++)
        printf("%d ",h.nodes[i].key);

    return 0;
}
