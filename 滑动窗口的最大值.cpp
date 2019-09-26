/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为
{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

*/
// 如果能从队列中找出它的最大数，这个问题也就解决了
// A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.
class Solution {
    typedef pair<int, int> Pair;
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        priority_queue<Pair> Q;
        if(num.size() < size || size < 1) return res;
        for(int i = 0; i < size-1; i++)
            Q.push(Pair(num[i], i));
        for(int i = size-1; i< num.size(); i++)
        {
            Q.push(Pair(num[i],i));
            Pair p = Q.top();
            while(p.second < i-(size-1))
            {
                Q.pop();
                p = Q.top();
            }
            res.push_back(p.first);
        }
        return res;
        
    }
};