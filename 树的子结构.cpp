/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

*/
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
    bool HasSubtree(TreeNode* pa, TreeNode* pb)
    {
        if(pb == nullptr) return false;//我们约定空树不是任意一个树的子结构
        if(pa == nullptr) return false;
        bool res = false;
        if(pa->val == pb->val) res = sametree(pa, pb);
        if(res == false)
        {
            return HasSubtree(pa->left, pb) || HasSubtree(pa->right, pb);

        }
        else return res;
     
    }
    bool sametree(TreeNode* pa, TreeNode* pb)
    {
        if(pb == nullptr) return true;
        else if(pa == nullptr) return false;
        if(pa->val != pb->val) return false;
        else return sametree(pa->left, pb->left) && sametree(pa->right, pb->right);

    }
};