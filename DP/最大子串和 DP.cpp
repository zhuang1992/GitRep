/*����Ӵ���
Ҫץס�Ӵ������������ص㣡
ȥ����״̬ת�Ʒ���
��dp[i]��ʾ��A[i]��β������Ӵ��ͣ���
��dp[i]ֻ������dp[i-1]+A[i]��A[i]����ȡ����dp[i-1]�������Ǹ�
*/

//������ʹ���˹����洢��space complexity ΪO(1)
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
