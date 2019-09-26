/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
*/

#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root,int expect_number)
    {
        if(root) dfs_find(root, expect_number);
        return res;
    }


private: 
    vector<vector<int>> res;
    vector<int> t;
    void dfs_find(TreeNode* root, int expc)
    {
        t.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && root->val == expc) res.push_back(t);
        else
        {
            if(root->left) dfs_find(root->left, expc - root->val);
            if(root->right) dfs_find(root->right, expc - root->val);
        }
        t.pop_back();

    }
};