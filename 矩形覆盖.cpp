/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/
//还是斐波那契数列

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int fib[100] = {0,1,2};
    
    int rectCover(int n) {
    if(fib[n] != 0) return fib[n];
    if(n <= 2)
        return fib[n];
    fib[n] = rectCover(n-2) + rectCover(n-1);
    return fib[n];

    }
};
};