/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
//后续遍历序列，队尾ass是根结点
    bool VerifySquenceOfBST(vector<int> s)
    {
        if (s.size() == 0)
            return false; //OJ要求这里若序列为空时，返回false，因此下面要根据序列是否为空来递归@1
        if (s.size() <= 2)
            return true;
        //at least 3 elements
        int ass = s[s.size() - 1];
        auto it = s.begin();
        while (*it < ass && it != s.end() - 1)
            it++;
        vector<int> sl(s.begin(), it);
        vector<int> sr(it, s.end() - 1);
        for (auto i : sr)
        {
            if (i < ass)
                return false;
        }
        if (!sl.empty() && !sr.empty())
            return VerifySquenceOfBST(sl) && VerifySquenceOfBST(sr); //@1
        if (sr.empty())
            return VerifySquenceOfBST(sl);
        if (sl.empty())
            return VerifySquenceOfBST(sr);
        return true;
    }
};
