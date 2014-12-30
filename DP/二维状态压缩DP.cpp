/*
Description

司令部的将军们打算在N*M的网格地图上部署他们的炮兵部队。一个N*M的地图由N行M列组成，地图的每一格可能是山地（用"H" 表示），也可能是平原（用"P"表示），如下图。在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示： 


如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。图上其它白色网格均攻击不到。从图上可见炮兵的攻击范围不受地形的影响。 
现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。 
Input

第一行包含两个由空格分割开的正整数，分别表示N和M； 
接下来的N行，每一行含有连续的M个字符('P'或者'H')，中间没有空格。按顺序表示地图中每一行的数据。N <= 100；M <= 10。
Output

仅一行，包含一个整数K，表示最多能摆放的炮兵部队的数量。
Sample Input

5 4
PHPP
PPHH
PPPP
PHPP
PHHP
Sample Output

6
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXM 21
#define MAXN 201
#define MAXS 100
using namespace std;
int okState[MAXS]; //用数组存可能的二进制状态，比直接从0遍历到1<<M快多了。但是要估计好可能的状态数。
int num[MAXS]; // 每种状态放置的大炮数。提前算出来存在这。
int okNum;
int cur[MAXN];//用二进制储存了地图中P,H的分布。H为1，P为0
bool ok(int x){ //只考虑一行，且不考虑地型，状态x是否合法
    if(x&(x<<1))return false;
    if(x&(x<<2))return false;
    return true;
}
//找到同一行中所有可能的合法状态
void initS(int M){
    okNum = 0;
    for(int i = 0; i < 1<<M; i++){
        if(ok(i))
            okState[okNum++] = i;
    }
}
//判断状态x是否与第k行匹配(即看是否有炮放在了山上)
bool fit(int x, int k){
    if(cur[k]&x)return false;
    return true;
}
//数一个整型数x的二进制中1的个数(用于初始化),用来数可以放的大炮的个数。
int jcount(int x){
   int cnt=0;
   while(x){
       cnt++;
       x &= (x-1);
   }
   return cnt;
}
int dp[MAXN][MAXS][MAXS]; //dp[i][j][k] 表示第i行状态为k，第i-1状态为j时的最大炮兵个数。注意i-2行的状态不需要存，枚举即可。
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n == 0 && m == 0)break;
        getchar();
        memset(okState,0,sizeof(okState));
        memset(num,0,sizeof(num));
        memset(cur,0,sizeof(cur));
        initS(m);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char t;
                scanf("%c",&t);
                if(t=='H') cur[i] += (1<<(j-1));
            }
            getchar();
        }
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < okNum; i++){
            num[i] = jcount(okState[i]);
            if(fit(okState[i],1)){
                dp[1][0][i] = num[i]; //注意这里的初始化，1,0,i。第二维用0，是因为边界外可以认为什么都不放，而okState[0]正代表什么都不放。
            }
        }
        for(int i = 2; i <= n; i++){
            for(int k = 0; k < okNum; k++){ //枚举第i行的状态
                if(!fit(okState[k],i))continue;
                for(int k2 = 0; k2 < okNum; k2++){ //枚举i-2行的状态
                    if(okState[k]&okState[k2])continue; // 相隔一行的两行，不允许在同一位置放置炮
                    for(int k3 = 0; k3 < okNum; k3++){ //枚举i-1行的状态
                        if(okState[k]&okState[k3])continue; // 相邻两行在同一位置放置炮，也是不允许的。
                        if(dp[i-1][k2][k3]==-1)continue; // 即使i-2行与i行无冲突，i-1行与i行也无冲突，但i-1行可能与i-2行存在冲突。如果这个dp为-1，说明这个状态是不能达到的，即i-1与i-2行存在冲突。
                        dp[i][k3][k] = max(dp[i][k3][k],dp[i-1][k2][k3]+num[k]);//a=max(a,b)这是在所有可能的转移情况中求最大值，存在dp中。
                    }
                }
            }
        }
        int ans = 0; //下面就要遍历dp矩阵，找最大值。i只需看等于n的时候就行，因为肯定i越大能放的炮越多。
       // for(int i = 1; i <= n; i++){
            for(int j = 0; j < okNum; j++){
                for(int k = 0; k < okNum; k++){
                    ans = max(ans, dp[n][j][k]);
                }
            }
        //}
        printf("%d\n",ans);
    }
    return 0;
}
