/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushv,vector<int> popv) {
    //maitain a stack!
    if(pushv.empty()) return true;
    stack<int> v;
    int N1 = pushv.size();
    int N2 = popv.size();
    
    int n1 = 0;
    int n2 = 0;
    v.push(pushv[n1++]);

    while(n2 < N2) //it2++
    {
        if(popv[n2] == v.top())
        {
            v.pop();
            ++n2;
            
        }
        else
        {
            while(popv[n2] != v.top())//continue pushing in stack
            {
                if(n1 < N1)
                {
                    v.push(pushv[n1]);
                    ++n1;
                }
                else 
                    return false;

            }
        }
    }
    //now n2 == N2
    return v.empty();
    }
};