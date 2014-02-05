#include <iostream>
#include <cstring>
#define MAXN 1005
#define MAXP 105
#define MAXW 31
using namespace std;

struct Object{
    int weight;
    int val;
}objects[MAXN];
int persons[MAXP];
int dp[MAXN][MAXW];

int main()
{
    int t;
    cin>>t;
    while(t--){
        int ans = 0;
        memset(dp,0,sizeof(dp));
        int numPack;
        cin>>numPack;
        for(int i = 1;i <= numPack; i++){
            cin>>objects[i].val>>objects[i].weight;
        }
        int numPerson;
        cin>>numPerson;
        for(int p = 0;p < numPerson; p++){
            cin>>persons[p];
            for(int i = 1;i <= numPack; i++){
                for(int j = 1;j <= persons[p]; j++){
                    if(j >= objects[i].weight){
                        dp[i][j] = max(dp[i-1][j],dp[i-1][j-objects[i].weight]+objects[i].val);
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            ans += dp[numPack][persons[p]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
