/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
f(n)=f(n-1)+f(n-2)+f(n-3)+... +f(1)+f(0);
f(n)= 2f(n-1);
f(0) = 1;
f(1) = 1;
f(2) = 2;
f(3) = 4;
f(4) = 8;


*/


#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int f[100] = {0};
    int jumpFloorII(int n) {
    if(f[n] != 0) return f[n];
    if(n == 1)
    {
        f[n] = 1;
        return f[n];
    }
    f[n] = 2*jumpFloorII(n-1);
    return f[n];


    }
};