/*
Description

Farmer John has purchased a lush new rectangular pasture composed of M by N (1 ≤ M ≤ 12; 1 ≤ N ≤ 12) square parcels. He wants to grow some yummy corn for the cows on a number of squares. Regrettably, some of the squares are infertile and can't be planted. Canny FJ knows that the cows dislike eating close to each other, so when choosing which squares to plant, he avoids choosing squares that are adjacent; no two chosen squares share an edge. He has not yet made the final choice as to which squares to plant.

Being a very open-minded man, Farmer John wants to consider all possible options for how to choose the squares for planting. He is so open-minded that he considers choosing no squares as a valid option! Please help Farmer John determine the number of ways he can choose the squares to plant.

Input

Line 1: Two space-separated integers: M and N 
Lines 2..M+1: Line i+1 describes row i of the pasture with N space-separated integers indicating whether a square is fertile (1 for fertile, 0 for infertile)
Output

Line 1: One integer: the number of ways that FJ can choose the squares modulo 100,000,000.
Sample Input

2 3
1 1 1
0 1 0
Sample Output

9
Hint

Number the squares as follows:
1 2 3
  4  

There are four ways to plant only on one squares (1, 2, 3, or 4), three ways to plant on two squares (13, 14, or 34), 1 way to plant on three squares (134), and one way to plant on no squares. 4+3+1+1=9.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXM 15
#define MAXN 15
#define MAXS 600   //这里设得太小了。。。一定要好好估计啊
#define MOD 100000000
using namespace std;

int cur[MAXM];
int okState[MAXS];
int numS;
int dp[MAXN][MAXS];
bool ok(int x){
    if(x&(x<<1))return false;
    return true;
}
void initS(int n){
    numS = 0;
    for(int i = 0; i < 1<<n; i++){
        if(ok(i))
            okState[numS++] = i;
    }
}
bool fit(int x, int k){
    if(cur[k]&x)return false;
    return true;
}
int main(){
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF){
        if(m==0 && n==0)break;
        memset(cur,0,sizeof(cur));
        memset(okState,0,sizeof(okState));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int t;
                scanf("%d",&t);
                if(t==0)
                    cur[i] += 1<<(n-j);
            }
        }
        initS(n);
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < numS; i++){
            if(fit(okState[i],1))
                dp[1][i] = 1;
        }
        for(int i = 2; i <=m ;i++){
            for(int j = 0; j < numS; j++){
                if(!fit(okState[j],i))continue;
                for(int k = 0; k < numS; k++){
                    //if(!fit(okState[k],i-1))continue; 这句可不要
                    if(okState[j]&okState[k])continue;
                    dp[i][j] = (dp[i][j]+dp[i-1][k])%MOD;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < numS; i++){
            ans = (ans+dp[m][i])%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}
