/*
    Segment Tree. Scanning line.
    成段更新。Lazy标记。
    在线算法。支持实时插入实时计算。
    hw5-Pro 5
    没有排序，直接插入，保留最高高度即可。
    没做离散化。
	注意这里的x不是点，而是线段编号。见图。
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn=100010;
long long height[maxn<<2];
long long lazy[maxn<<2];

void PushUp(int rt){
    if(height[rt<<1] != height[rt<<1|1]){
        height[rt] = -1;
    }else{
        height[rt] = max(height[rt],height[rt<<1]);
    }
}

void PushDown(int rt,int m){
    if (lazy[rt]){
        lazy[rt<<1] = lazy[rt];
		lazy[rt<<1|1] = lazy[rt];
		height[rt<<1] = max(height[rt<<1],lazy[rt]);
		height[rt<<1|1] = max(height[rt<<1|1],lazy[rt]);
		lazy[rt] = 0;
    }
}

void build(int l,int r,int rt){
    lazy[rt]=0;
    if(l==r){
        //scanf("%lld",&sum[rt]);
        height[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);  //这个PushUp是在出递归的过程中被执行的。因此它是自叶子节点向根节点执行的。将叶子节点的信息向上更新到根节点。
}
void update(int L,int R,int c,int l,int r,int rt){
    if (height[rt] != -1 && L <= l && r <= R){
        if(l!=r)
            lazy[rt] = max(lazy[rt],(long long) c);
        else
            lazy[rt] = 0;
        height[rt] =max(height[rt],(long long) c);
        return ;                        //返回，子节点暂时不要更新
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (R > m) update(L , R , c , rson);
    PushUp(rt);
}

void query(int L,int R,int l,int r,int rt){
    if (height[rt]!=-1 && L <= l && r <= R){
        printf("X:[%d,%d],Height:%d\n",l,r,height[rt]);
        return;
    }
    PushDown(rt , r - l + 1);             //
    int m = (l + r) >> 1;
    query(L , R , lson);
    query(L , R , rson);
}

int main(){
    int n,q;
    while(scanf("%d %d",&n,&q)!=EOF){
        build(1,n,1);
        while(q--){
            int x1,x2,r;
            scanf("%d %d %d",&x1,&x2,&r);
            update(x1,x2,r,1,n,1);
        }
        query(1,n,1,n,1);
    }
    return 0;
}
/*
10 6
1 3 1
2 4 3
3 6 2
7 8 4
7 10 1
5 10 15
*/
