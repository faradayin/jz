// 输入一棵二叉树，求该树的深度。
// 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
    int TreeDepth(TreeNode* proot)
    {
        //迭代
        if(proot == NULL) return 0;
        queue<TreeNode*> q;
        q.push(proot);
        int shendu = 0;
        while(!q.empty())
        {//广度优先
            shendu++;
            int the_level = q.size();
            for(int i=0; i<the_level; i++)//遍历一层
            {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }

        }
        return shendu;
    
    }
    int TreeDepth(TreeNode* proot)
    {
        //递归
        if(proot == NULL) return 0;
        return max(TreeDepth(proot->left), TreeDepth(proot->right))+1;
    }
};
