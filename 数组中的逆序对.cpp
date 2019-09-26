/*
在数组中的两个数字，如果前面一个数字大于后面的数字，
则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007

*/
class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        if (data.size() <= 1)
            return 0;
        int *copy = new int[data.size()];
        for (unsigned int i = 0; i < data.size(); i++)
        {
            copy[i] = 0;
        }
        int count = InversePairCore(data, copy, 0, data.size() - 1);
        delete[] copy;
        return count;
    }
    int InversePairCore(vector<int> &data, int *&copy, int start, int end)
    {
        if (start == end)
        {
            copy[start] = data[start];
            return 0;
        }
        int length = (end - start) / 2;
        int left = InversePairCore(data, copy, start, start + length) % 1000000007;
        int right = InversePairCore(data, copy, start + length + 1, end) % 1000000007;
        int i = start + length;
        int j = end;
        int index = end;
        int count = 0;
        while (i >= start && j >= start+length+1)
        {
            if (data[i] > data[j])
            {
                copy[index--] = data[i--];
                count += j - start - length;
                if(count >= 1000000007) count = count % 1000000007;
            }
            else
                copy[index--] = data[j--];
            
        }
        for (; i >= start; --i)
            copy[index--] = data[i];
        for (; j > start + length + 1; --j)
            copy[index--] = data[j];
        for (int i = start; i <= end; i++)
            data[i] = copy[i];
        return (count + left + right) % 1000000007;
    }
};