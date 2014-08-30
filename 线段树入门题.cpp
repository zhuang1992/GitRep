//HDOJ1754
/*
本题目包含多组测试，请处理到文件结束。
在每个测试的第一行，有两个正整数 N 和 M ( 0<N<=200000,0<M<5000 )，分别代表学生的数目和操作的数目。
学生ID编号分别从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩。
接下来有M行。每一行有一个字符 C (只取'Q'或'U') ，和两个正整数A，B。
当C为'Q'的时候，表示这是一条询问操作，它询问ID从A到B(包括A,B)的学生当中，成绩最高的是多少。
当C为'U'的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。
 

Output
对于每一次询问操作，在一行里面输出最高成绩。
 

Sample Input
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5
*/

//树是用数组存储的。rt表示当前结点（在数组中下标）。
#include <cstdio>
#include <algorithm>
using namespace std;
 
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 222222;
int MAX[maxn<<2];
void PushUP(int rt) {
    MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
}
void build(int l,int r,int rt) {
    if (l == r) {
        scanf("%d",&MAX[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}
void update(int p,int sc,int l,int r,int rt) {
    if (l == r) {
        MAX[rt] = sc;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p , sc , lson);
    else update(p , sc , rson);
    PushUP(rt);
}
int query(int L,int R,int l,int r,int rt) {
    if (L <= l && r <= R) {
        return MAX[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = max(ret , query(L , R , lson));
    if (R > m) ret = max(ret , query(L , R , rson));
    return ret;
}
int main() {
    int n , m;
    while (~scanf("%d%d",&n,&m)) {
        build(1 , n , 1);
        while (m --) {
            char op[2];
            int a , b;
            scanf("%s%d%d",op,&a,&b);
            if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));
            else update(a , b , 1 , n , 1);
        }
    }
    return 0;
}