/*
大家都知道斐波那契数列，现在要求输入一个整数n，
请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int Fib[40] = {0};//局部自动变量，只要初始化列表存在，即使没有在列表中的部分也会被初始化填充0
    

    int Fibonacci(int n) {
    if(Fib[n] != 0) return Fib[n];
    if(n == 0) 
    {
        Fib[n] = 0;
        return Fib[n];
    }
    if(n == 1)
    {
        Fib[n] = 1;
        return Fib[n];
    }


    Fib[n] = Fibonacci(n-1)+Fibonacci(n-2);
    return Fib[n];




    }
};
