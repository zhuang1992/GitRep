#include <iostream>
#include <cstdio>
#include <cstring>
#define NUM_OF_PRIME 1000001
#define RANGE 10000001
using namespace std;

//筛法求素数

bool hash[RANGE];
int prime[NUM_OF_PRIME];
//long long num[1000001];
int cnt;
void PrimeByGriddling() {
    memset(hash,0,sizeof(hash));
    prime[0] = 2;
    cnt = 1;
    for(int i = 3 ; i < RANGE ; i+=2) {
        if(hash[i]) {
            continue;
        }
        prime[cnt++] = i;
        if(i<=10000) {         //这个if是有必要的。防止i*i超出int范围
            for(int j = i*i; j < RANGE; j+=i) {  //从i*i开始，i*(i-1)已经在之前处理过了
                hash[j] = 1;
            }
        }
    }
}
int main() {
    PrimeByGriddling();
    printf("%d\n",cnt);
    for(int i = 0; i < 50 ; ++i) {
        printf("%d ",prime[i]);
    }
    return 0;
}

