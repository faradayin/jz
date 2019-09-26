/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 
1  2  3  4
5  6  7  8 
9  10 11 12 
13 14 15 16 
则依次打印出数字
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10
*/
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<int> res;
        //if(column == 0 || row == 0) return res;
        int R = column-1,     //右界
            D = row - 1,    //下界
            L = 0, //左
            U = 0; //上

        

        while (L<=R && U<=D)
        {
            for (int j=L;j<=R;j++)
                res.push_back(matrix[U][j]);
            
            for (int i=U+1;i<=D;i++)
                res.push_back(matrix[i][R]);
            if (U != D)//防止回文
                for (int j = R - 1; j >= L; j--)
                    res.push_back(matrix[D][j]);
            if (L != R)//防止回文
                for (int i = D - 1; i > U; i--)
                    res.push_back(matrix[i][L]);

            L++;
            R--;
            U++;
            D--;

        }
        return res;

    }
};