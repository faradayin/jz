// 统计一个数字在排序数组中出现的次数。


class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
    return get_upper(data, k)-get_lower(data, k)+1;
    }

    int get_lower(vector<int> data, int k)
    {
        int start = 0, end = data.size()-1;
        int mid = (start+end)/2;
        while(start <= end)
        {
            if(data[mid] < k)
                start = mid + 1;
            else
                end = mid - 1;
            mid = (start + end)/2;

        }
        return start;
    }
    int get_upper(vector<int> data, int k)
    {
        int start = 0, end = data.size()-1;
        int mid = (start + end)/2;
        while(start <= end)
        {
            if(data[mid] <= k)
                start = mid+1;
            else
                end = end-1;
            mid = (start+end)/2;

        }
        return end;
    }
};