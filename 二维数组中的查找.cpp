#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int t, vector<vector<int>> a)
    {
        int n = a.size();
        int m = a[0].size();
        int i, j;
        for(i = n-1, j = 0; i >= 0 && j < m;)
        {
            if(t == a[i][j]) return true;
            if(t < a[i][j]) 
            {
                i--;
                continue;
            }
            if(t > a[i][j])
            {
                j++;
                continue;
            }

        }
        return false;

    }
};