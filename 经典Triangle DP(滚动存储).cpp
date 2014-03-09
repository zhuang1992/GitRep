#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define MAXN 500
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int rows = triangle.size();
        int temp = 0;
        int temp2 = 0;
        int dp[MAXN];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < triangle.size(); i++) {
            for(int j = 0; j< triangle[i].size(); j++) {
                if(j == 0) {
                    temp = dp[j] + triangle[i][j];
                    if(j == triangle[i].size()-1) {
                        dp[j] = temp;
                    }
                } else if(j == triangle[i].size()-1) {
                    temp2 = dp[j-1] + triangle[i][j];
                    dp[j-1] = temp;
                    temp = temp2;
                    dp[j] = temp;
                } else {
                    temp2 = min(dp[j-1],dp[j])+triangle[i][j];
                    dp[j-1] = temp;
                    temp = temp2;
                }

            }
        }
        int ans = 0x7fffffff;
        for(int i = 0; i< triangle[rows-1].size(); i++) {
            ans = min(ans,dp[i]);
        }
        return ans;
    }
};

int main() {
    vector<vector<int> > triangle;

    int row[2][2] = {
        {-1},
        {-2,-3}
    };
    for(int i = 0; i < 2; i++) {
        vector<int> vrow(row[i],row[i]+i+1);
        triangle.push_back(vrow);
        cout<<triangle[i].size()<<endl;
    }

    Solution test;
    cout<<test.minimumTotal(triangle);
    return 0;
}
/*

其实这个状态转移方程找的不够好
下面这个思路可以大大提高效率

设状态为f(i; j)，表示从从位置(i; j) 出发，路径的最小和，则状态转移方程为
f(i; j) = min ff(i; j + 1); f(i + 1; j + 1)g + (i; j)

这是一个自底向上的思路

代码
// LeetCode, Triangle
// 时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
	int minimumTotal (vector<vector<int>>& triangle) {
		for (int i = triangle.size() - 2; i >= 0; --i)
			for (int j = 0; j < i + 1; ++j)
				triangle[i][j] += min(triangle[i + 1][j],triangle[i + 1][j + 1]);
		return triangle [0][0];
	}
};
*/