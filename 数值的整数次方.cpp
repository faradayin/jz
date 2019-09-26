/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    double Power(double bs, int ex)
    {
        if (ex >= 0)
        {
            if (ex == 0)
                return 1;
            else
                return bs * Power(bs, ex - 1);
        }
        else
        {
            return 1/Power(bs, -ex);
        }
        
    }
};
