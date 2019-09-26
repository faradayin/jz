/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* proot)
    {
        if(proot == nullptr)
            return true;
        return lr_sym(proot->left, proot->right);
    
    }
private:

    bool lr_sym(TreeNode* l, TreeNode* r)
    {
        if(l==nullptr && r==nullptr)
            return true;
        if(l == nullptr || r == nullptr)
            return false;
        if(l->val != r->val)
            return false;
        //如果左右子树节点值相同，则 递归 左左-右右 && 左右-右左
        return lr_sym(l->left,r->right) && lr_sym(l->right, r->left);

    }

};