class Solution
{
public:
    vector< vector<int> > ans;

    void LevelOrder(TreeNode *pRoot,int p )
    {
        if(pRoot == NULL)
        {
            return;

        }
        if(ans.size( ) == p)
        {
            ans.push_back(vector<int>( ));
        }

        ans[p].push_back(pRoot->val);

        LevelOrder(pRoot->left, p + 1);
        LevelOrder(pRoot->right, p + 1);

    }

    vector< vector<int> > Print(TreeNode* pRoot)
    {
        LevelOrder(pRoot,0);

        for(int i = 0; i <ans.size( ); i++)
        {
            if(i & 1)
            {
                reverse(ans[i].begin( ), ans[i].end( ));
            }
        }
        return ans;
    }

};
