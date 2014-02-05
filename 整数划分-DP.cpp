/*Input
ÿ����������������n��k��(1 <= n <= 50, 1 <= k <= n)
Output
����ÿ�����룬��������С�
��һ�У� ��n���ֳ�����������֮�͵Ļ�������
�ڶ��У� ��n���ֳ�k��������֮�͵Ļ�������
�����У� ��n���ֳ������������k�Ļ�������
�����У� ��n���ֳ�������������֮�͵Ļ�������
�����У� ��n���ֳ����ɲ�ͬ����֮�͵Ļ�������
�����У� ��ӡһ�����С�*/

//�������� DP
#include <iostream>
#include <cstring>
#define MAXN 100
using namespace std;
int dp[MAXN][MAXN];

int func1(int n) {
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }//ע��߽������ĳ�ʼ��dp(0,0)ӦΪ1
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i < j){
                dp[i][j] = dp[i][j-1];
            }else{
                dp[i][j] = dp[i-j][j] + dp[i][j-1];
            }
        }
    }
    return dp[n][n];
}

int func2(int n,int k){
    memset(dp,0,sizeof(dp));
    //dp[][]�Ķ�ά�����巢���˱仯
    for(int i = 0; i <= n; i++){
        dp[i][i] = 1;
        dp[i][1] = 1;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            if(i < j){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-j][j] + dp[i-1][j-1];
            }

        }
    }
    return dp[n][k];
}
int func3(int n,int k){
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }//ע��߽������ĳ�ʼ��dp(0,0)ӦΪ1
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i < j){
                dp[i][j] = dp[i][j-1];
            }else{
                dp[i][j] = dp[i-j][j] + dp[i][j-1];
            }
        }
    }
    return dp[n][k];
}

int func4(int n){    //��ʱû����
    int f[MAXN][MAXN];
    int g[MAXN][MAXN];
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    f[0][0] = 1, g[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j <= i; j++) {
            g[i][j] = f[i - j][j];
            f[i][j] = f[i - 1][j - 1] + g[i - j][j];
        }
    }
    int res3 = 0;
    for (int i = 0; i <= n; i++) {
        res3 += f[n][i];
    }
    return res3;
}
/*
int func4(int n,int max)            //��n���ֳ�������������֮�͵Ļ��������ݹ顣
{
    int counter=0;
    int i;

    if(max<=1)
    {
        return 1;
    }
    else
    {
        for(i=1;2*i<=max+1;i++)
        {
            counter+=func4(n-2*i+1,(i<n-2*i+1)?i:(n-2*i+1));
        }
        return counter;
    }
}*/
int func5(int n){
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i < j){
                dp[i][j] = dp[i][j-1];
            }else{
                dp[i][j] = dp[i-j][j-1] + dp[i][j-1];
            }
        }
    }
    return dp[n][n];
}
int main() {
    int n,k;
    while(cin>>n>>k) {
        cout<<func1(n)<<endl;
        cout<<func2(n,k)<<endl;
        cout<<func3(n,k)<<endl;
        cout<<func4(n)<<endl;
        cout<<func5(n)<<endl;
        cout<<endl;
    }

    return 0;
}
