/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //dp缓存
    int dp[1000];

    int FindGreatestSumOfSubArray(vector<int> array) {
    if(array.size() == 0) return 0;
    int temp, start, end;
    int max_sum = INT_MIN;
    dp[0] = array[0];
    for(unsigned int i=1; i<array.size(); i++)
    {
        if(dp[i-1] <= 0)
        {
            dp[i] = array[i];
            temp = i;
        }
        else
        {
            dp[i] = array[i]+dp[i-1];
        }
        if(dp[i] > max_sum)
        {
            max_sum = dp[i];
            start = temp;
            end = i;
        }

    }
    return max_sum;
    
    }
};
// #include <iostream>
// #include <vector>
// #include <iterator>

// #include <climits>

// using namespace std;


// #define __tmain main

// #ifdef __tmain

// #define debug cout

// #else

// #define debug 0 && cout

// #endif // __tmain


// class Solution
// {
//     int dp[1000];
// public:
//     int FindGreatestSumOfSubArray(vector<int> array)
//     {
//         if(array.size( ) == 0)
//         {
//             return 0;
//         }

// #ifdef __tmain
//         debug <<"vector : ";
//         copy(array.begin( ), array.end( ), ostream_iterator<int>(cout, " "));
//         debug <<endl;
//         int start, end;
// #endif  // __tmain

//         int maxSum = INT_MIN;
//         dp[0] = array[0];
// #ifdef  __tmain
//         start = 0;
//         //debug <<"start = " <<0 <<endl;
// #endif  // __tmain

//         for(int i = 1; i < array.size( ); i++)
//         {
//             debug <<"dp[" <<i - 1 <<"] = " <<dp[i - 1] <<endl;
//             if(dp[i - 1] <= 0)
//             {
//                 dp[i] = array[i];
// #ifdef __tmain
//                 //debug <<"start = " <<i <<endl;
//                 start = i;
// #endif  // __tmain
//             }
//             else        // 否则累加 > 0, 继续与下一个数累加
//             {
//                 dp[i] = array[i] + dp[i - 1];
//             }

//             //  判断当前最大值
//             if(dp[i] > maxSum)
//             {
//                 maxSum = dp[i];
// #ifdef __tmain
//                 end = i;
//                 //debug <<"end = " <<i <<endl;
//                 debug <<"[" <<start <<", " <<end <<"] = " <<maxSum <<endl;
// #endif  // __tmain
//             }
//         }

//         return maxSum;
//     }
// };

// int __tmain( )
// {


//     Solution solu;

//     int arr1[] = { 6, -3, -2, 7, -15, 1, 2, 2};
//     vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
//     cout <<"maxSum = " <<solu.FindGreatestSumOfSubArray(vec1) <<endl;

//     int arr2[] = { -2, -8, -1, -5, -9 };
//     vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
//     cout <<"maxSum = " <<solu.FindGreatestSumOfSubArray(vec2) <<endl;

//     return 0;
// }