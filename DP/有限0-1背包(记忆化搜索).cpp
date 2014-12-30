//���仯����������˵ݹ�Ͷ�̬�滮�����ơ�
// ������Ϊë���Ǳ���ͨ��̬�滮Ҫ��������TLE�ˡ�
#include <iostream>
#include <cstring>
#define MAXN 1005
#define MAXP 105
#define MAXW 35
using namespace std;

struct Object{
    int weight;
    int val;
}objects[MAXN];
int persons;
int dp[MAXN][MAXW];

int Knapsack(int i,int w){
    if(dp[i][w] < 0){
        if(w >= objects[i].weight){
            return max(Knapsack(i-1,w),Knapsack(i-1,w-objects[i].weight)+objects[i].val);
        }else{
            return Knapsack(i-1,w);
        }
    }else{
        return dp[i][w];
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i <= MAXN; i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i <= MAXW; i++){
            dp[0][i] = 0;
        }
        int numPack;
        cin>>numPack;
        for(int i = 1;i <= numPack; i++){
            cin>>objects[i].val>>objects[i].weight;
        }
        int numPerson;
        cin>>numPerson;
        for(int p = 0;p < numPerson; p++){
            cin>>persons;
            ans += Knapsack(numPack,persons);
        }
        cout<<ans<<endl;
    }
    return 0;
}
