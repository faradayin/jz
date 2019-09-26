/**
 * 
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * 
 */
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) 
    {
        if(pre.size() == 0)
            return nullptr;

        int val = pre[0];//root node 
        TreeNode* node = new TreeNode(val);
        auto it = in.begin();
        while(*it != val)
        {
            ++it;
        }
        vector<int> left_in(in.begin(), it);
        vector<int> right_in(++it, in.end());
        vector<int> left_pre(pre.begin()+1, pre.begin()+1+left_in.size() );
        vector<int> right_pre(pre.end()-right_in.size(), pre.end());
        
        node->left = reConstructBinaryTree(left_pre, left_in);
        node->right = reConstructBinaryTree(right_pre, right_in);
        return node;   


    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        //递归让问题简单
        if(pre.size() == 0) return nullptr;
        TreeNode* node = new TreeNode(pre[0]);
        auto it = in.begin();
        while(*it != pre[0]) ++it;
        vector<int> left_in(in.begin(), it);
        vector<int> right_in(it+1, in.end());
        vector<int> left_pre(pre.begin()+1, pre.begin()+1+left_in.size());
        vector<int> right_pre(pre.end()-right_in.size(), pre.end());
        node->left = reConstructBinaryTree(left_pre, left_in);
        node->right = reConstructBinaryTree(right_pre, right_in);
        return node;
    }
     
};