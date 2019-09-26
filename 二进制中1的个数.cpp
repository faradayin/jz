/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int  NumberOf1(int n) {
    int cnt = 0;
    for(int i = 0; i< 8*sizeof(int); i++)
    {
        if(n&1) ++cnt;
        n = n>>1;
    }
    return cnt;
    }
};