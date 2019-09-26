/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/
//f(n) = f(n-1) + f(n-2)   原来就是Fibonacci数列
//f(1) = 1; f(2) = 2;

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int fib[100] = {0};
    int jumpFloor(int n) {
    if(fib[n] != 0) return fib[n];
    if(n == 1)
    {
        fib[n] = 1;
        return fib[n];
    }
    if(n == 2)
    {
        fib[n]= 2;
        return fib[n];
    }
    fib[n] = jumpFloor(n-2) + jumpFloor(n-1);
    return fib[n];

    }
};