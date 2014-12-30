#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 300
#define INF 0x7fffffff
using namespace std;
int dp[MAXN][MAXN];
int main()
{
    int n;
    int frequence[MAXN];
    int sum[MAXN];
    while(scanf("%d",&n)!=EOF){
        memset(sum,0,sizeof(sum));
        for(int i = 0;i < n; i++){
            scanf("%d",&frequence[i]);
            sum[i] = sum[max(0,i-1)] + frequence[i];
        }
        memset(dp,0,sizeof(dp));

        for(int i = 1;i < n ; i++){
            for(int j = 0; j + i < n; j++){
                int freqSum = 0;
                int l = j;
                int r = j + i;
                dp[l][r]=INF;
                for(int k = l; k <= r; k++){
                    dp[l][r] = min(dp[l][max(0,k-1)]+dp[k+1][r]-frequence[k] + sum[r]-(l-1<0?0:sum[l-1]),dp[l][r]);

                    /*if(minPrice > dp[j][max(0,k-1)]+dp[k+1][j+i] - frequence[k]){
                        minPrice = dp[j][max(0,k-1)]+dp[k+1][j+i] - frequence[k];
                        minKId = k;
                    }
                    freqSum += frequence[k];*/
                }
                //dp[j][j+i] = minPrice + freqSum;
            }
        }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
//dp(i,j) = min(dp[i][k-1]+dp[k+1][j] - freq[k])+ sum of all freq ; for all k between i and j
//注意填表的方向。此题是从对角线向一侧填
