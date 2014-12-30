/*最大子串和
要抓住子串必须连续的特点！
去构造状态转移方程
令dp[i]表示以A[i]结尾的最大子串和！！
则dp[i]只能来自dp[i-1]+A[i]或A[i]本身，取决于dp[i-1]是正还是负
*/

//另这里使用了滚动存储，space complexity 为O(1)
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define MAXN 500
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int dp = A[0];
        //memset(dp,0,sizeof(dp));
        int res = dp;
        for(int i = 1;i < n; i++){
            dp = max(dp,0) + A[i];
            res = max(dp,res);
        }
        return res;
    }
};

int main() {
    int A[10] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = 9;
    Solution test;
    cout<<test.maxSubArray(A,n);
    return 0;
}
