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
    vector<vector<int> > Print(TreeNode* proot) 
    {
        //vector<int> tem;
        vector<vector<int>> res;

        vector<TreeNode*> hang;
        //vector<TreeNode*> n_hang;
        if(proot == nullptr) return res;
        hang.push_back(proot);
        
        do
        {      
            res.push_back(print_hang(hang));//save this hang data
            hang = next_hang(hang);//save the next hang index
        } while (!hang.empty());
        return res;
    }
        
        
        
    
private:
    vector<int> print_hang(vector<TreeNode*> hang)
    {
        vector<int> r;
        for(auto p:hang)
        {
            r.push_back(p->val);
        }
        return r;
    }
    vector<TreeNode*> next_hang(vector<TreeNode*> hang)
    {
        vector<TreeNode*> nh;
        for(auto p:hang)
        {
            if(p->left)
                nh.push_back(p->left);
            if(p->right)
                nh.push_back(p->right);

        }
        return nh;
    }

        
        
    
    
};