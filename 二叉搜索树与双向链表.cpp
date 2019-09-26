/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
public:
    TreeNode *Convert(TreeNode *root)
    {
        if (root == NULL)
            return root;
        root = Convert_sub(root);
        while (root->left) //find the min
        {
            root = root->left;
        }
        return root;
    }


private:
    TreeNode *Convert_sub(TreeNode *root)
    {
        //递归
        //递归就死自上而下的调用，递归的终点是叶子结点
        if (root == NULL)
            return root;
        
        //依次处理左右子结点
        if (root->left)
        {
            TreeNode* l_st = Convert_sub(root->left);
            while (l_st->right) l_st = l_st->right;

            //连接
            l_st->right = root;
            root->left = l_st;
        }
        if (root->right)
        {
            TreeNode* r_st = Convert_sub(root->right);
            while (r_st->left) r_st = r_st->left;

            r_st->left = root;
            root->right = r_st;
        }
        return root;
    }

};
//重写
class Solution {
public:
    TreeNode *Convert(TreeNode *root)
    {
        if(root == nullptr) return root;
        convert_at(root);
        while(root->left) root = root->left;
        return root;
    }
        
private:
    TreeNode* convert_at(TreeNode* root)
    {
        //不亲手做，永远不要以为自己会了
        if(root == nullptr) return root;
        if(root->left)
        {
            TreeNode* ls = convert_at(root->left);
            while(ls->right) ls = ls->right;
            ls->right = root;
            root->left = ls;
        }
        if(root->right)
        {
            TreeNode* rs = convert_at(root->right);
            while(rs->left) rs = rs->left;
            rs->left = root;
            root->right = rs;
            
        }
        return root;          
    }
};
