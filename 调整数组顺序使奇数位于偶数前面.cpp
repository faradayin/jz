/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include <vector>
#include <string>
using namespace std;

public:
    void reOrderArray(vector<int> &A) {
    for(auto i=A.begin(); i<A.end(); i++)
    {
        if(*i%2 == 0)//偶数
        {
            auto j = i+1;
            while(*j%2 == 0 && j != A.end()) 
                j++;
            if(j == A.end())
                return;
            // now j points to an odd
            int v = *j;
            while(j!=i)
            {
                *j = *(j-1);
                --j;
            }
            *j = v;
        }

    }
    }
};