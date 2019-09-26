/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
    unordered_map<char, int> ch_cnt;
    for(auto ch:str)
    {
        ch_cnt[ch] += 1;//若map中没有该元素，会自动创建{ch, 0}

    }
    for(int i=0; i< str.size(); ++i)
    {
        if(ch_cnt[str[i]] == 1)
            return i;
        
    }
    return -1;
    }
};