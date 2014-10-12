#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 100
using namespace std;

int maxSubarray(int sum[], int n, int a, int b,int& mMax, int &mMin){
    if(a==b){
        mMax = sum[a];
        mMin = sum[a];
        return sum[a];
    }
    int m = (a+b)/2;
    int lMax,lMin,rMax,rMin;
    int lAns = maxSubarray(sum, n, a, m, lMax, lMin);
    int rAns = maxSubarray(sum, n, m+1, b, rMax, rMin);
    mMax = max(lMax, rMax);
    mMin = min(lMin, rMin);
    return max(max(max(rMax - lMin, lAns),rAns),0);
}
int main(){
    int num[] = {-10,-20,2,4,-5,7};
    int n = sizeof(num)/sizeof(int);
    int sum[n];
    sum[0] = num[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1]+num[i];
    }
    int a,b;
    printf("%d\n", maxSubarray(sum, n, 0, n-1, a, b));
    return 0;
}
