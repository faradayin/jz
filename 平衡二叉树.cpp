// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
#include <iostream>
#include <vector>
#include <string>
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
//////this solution travese the tree twice!

    // bool IsBalanced_Solution(TreeNode* proot) {
    // if(h_t(proot) == 0) return true;
    // int h_left = h_t(proot->left);
    // int h_right = h_t(proot->right);
    // if(fabs(h_left-h_right) <= 1)
    //     return IsBalanced_Solution(proot->left) && IsBalanced_Solution(proot->right);
    // else
    //     return false;
    // }

    bool IsBalanced_Solution(TreeNode* proot)
    {
        int depth;
        return is_balanced(proot, &depth);
    }



private:
    bool is_balanced(TreeNode* root, int* depth)//deliever the pointer
    {   
        if(root == NULL)
        {
            *depth = 0;
            return true;
        }
        int depth_l, depth_r;
        bool isb_l = is_balanced(root->left, &depth_l);
        bool isb_r = is_balanced(root->right, &depth_r);
        if(isb_l && isb_r)//left & right sub-tree both balanced
        {
            if(fabs(depth_l - depth_r) <= 1)
            {
                *depth = max(depth_l, depth_r)+1;
                return true;
            }
        }
        return false;

    }

    int h_t(TreeNode* root)
    {
        if(root == NULL) return 0;
        return max(h_t(root->left),h_t(root->right))+1;

    }
    
};
