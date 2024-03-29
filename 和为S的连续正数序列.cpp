/*
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,
他马上就写出了正确答案是100。
但是他并不满足于此,
他在想究竟有多少种连续的正数序列的和为100
(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? 
Good Luck!

*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int>> res;
    vector<int> seq;
    if(sum < 3) return res;
    int begin = 1, end = 2, mid = (sum + 1)/2;
    int s = begin + end;
    while(begin < mid && end < sum)
    {
        if(s == sum) 
        {
            seq.clear();
            for(int i = begin; i<= end; i++)    seq.push_back(i);
            res.push_back(seq);
            ++end;
            s += end;
        }
        
        else if(s > sum)
        {
            s -= begin;
            ++begin;

        }
        else if(s < sum)
        {
            ++end;
            s += end;
        }

    }
    return res;
    }
    
};