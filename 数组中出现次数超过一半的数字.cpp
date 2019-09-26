/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    unordered_map<int, int> cnt;
    
    for(auto &n:numbers)
    {
        cnt[n] += 1;
    }
    for(auto &it:cnt)
        if(it.second > numbers.size()/2) return it.first;
    return 0;
    }
};