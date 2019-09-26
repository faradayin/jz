// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
#include <iostream>
#include <vector>
using namespace std;
//冒泡排序
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    int N = input.size()-1;
    vector<int> res;
    if(k > input.size()) return res;
    int start = 0;
    while(start < k)
    {
        for(int i=N;i>start;i--)
        {
            if(input[i-1] > input[i])
            {
                int t = input[i-1];
                input[i-1] = input[i];
                input[i] = t;

            }

        }
        res.push_back(input[start++]);

        
    }
    return res;
    }
};
