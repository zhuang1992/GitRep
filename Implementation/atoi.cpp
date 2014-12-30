/*
atoi()
看看自己的代码有多蠢*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        int ans = 0;
        bool valid = 1;
        int outOfRange = -1;
        int negative = 0;
        int hasSymbol = 0;
        int begin;
        for(begin = 0; begin < strlen(str); begin++) {
            if(str[begin] != ' ')break;
        }
        if(begin == strlen(str))return 0;
        if(str[begin] == '-') {
            negative = 1;
            hasSymbol = 1;
        } else if(str[begin] == '+') {
            hasSymbol = 1;
        }

        for(int i =begin + hasSymbol; i < strlen(str); i++) {
            if(str[i] < '0' || str[i] > '9' || (!valid))break;
            if(ans > 0x7fffffff / 10) {
                ans *= 10;
                if(!negative) {
                    valid = 0;
                    outOfRange = 1;
                    continue;
                } else {
                    if(ans != 0x80000000) {
                        valid = 0;
                    }
                    outOfRange = 0;
                    if(!valid)continue;
                }
            } else {
                ans *= 10;
                valid = 1;
            }
            if(ans > 0x7fffffff - str[i] + '0') {
                ans += str[i] - '0';
                if(!negative) {
                    valid = 0;
                    outOfRange = 1;
                    continue;
                } else {
                    if(ans != 0x80000000) {
                        valid = 0;
                    }
                    outOfRange = 0;
                    if(!valid)continue;
                }
            } else {
                ans += str[i] - '0';
                valid = 1;
            }
        }


        if(negative) {
            ans *= -1;
        }

        if(!valid && outOfRange == -1) {
            return 0;
        }
        if(!valid && outOfRange == 0) {
            return 0x80000000;
        } else if(!valid && outOfRange == 1) {
            return 0x7fffffff;
        } else if(valid && outOfRange == 1) {
            return 0x80000000;
        }
        return ans;
    }
};




class Solution {
public:
    int atoi(const char *str) {
        int num = 0;
        int sign = 1;
        const int n = strlen(str);
        int i = 0;
        while (str[i] == ' ' && i < n) i++;
        if (str[i] == '+') i++;
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        for (; i < n; i++) {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (num > INT_MAX / 10 ||
                    (num == INT_MAX / 10 &&
                     (str[i] - '0') > INT_MAX % 10)) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + str[i] - '0';
        }
        return num * sign;
    }
};