/*HW6 P1 Gas Station DP*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int gas_station(int n, int c[], int x[]){
    int dp[101][101];
    memset(dp,0x7f7f7f7f,sizeof(dp));
    for(int j = 0;j <= 100; j++){
        dp[1][j]=0;
    }
    for(int i = 2; i <= n; i++){
        if(x[i]-x[i-1]>100)
            return -1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= 100; j++){
            if(j >= x[i+1]-x[i]){
                dp[i+1][j-x[i+1]+x[i]] = min(dp[i+1][j-x[i+1]+x[i]],dp[i][j]);
            }
            dp[i+1][100-x[i+1]+x[i]] = min(dp[i+1][100-x[i+1]+x[i]],dp[i][j]+c[i]);
        }
    }
    int res = 10000000;
    for(int j = 0 ; j <= 100; j++){
        res = min(res, dp[n][j]);
    }
    return res;
}
int main(){
    int c[] = {-1,2,3,4,5,6,7,8};
    int x[] = {-1,0,60,150,200,220,260,360};
    int n = 5;
    printf("%d\n",gas_station(n,c,x));
    return 0;
}
