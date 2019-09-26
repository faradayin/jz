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
    int count = 0;
    TreeNode* KthNode(TreeNode* root, int k)
    {
        if(root != nullptr)
        {
            //中序遍历，搜索第 k结点
            TreeNode* node = KthNode(root->left, k);
            if(node != nullptr)
                return node;
            count++;
            if(count == k)
                return root;
            node = KthNode(root->right, k);
            if(node != nullptr)
                return node;

        }
        return nullptr;
    }

    
};