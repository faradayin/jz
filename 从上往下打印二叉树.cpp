#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    queue<TreeNode*> look;
    look.push(root);

    while(!look.empty())
    {
        res.push_back(look.front()->val);
        
        if(look.front()->left != NULL) look.push(look.front()->left);
        if(look.front()->right != NULL) look.push(look.front()->right);
        look.pop();

    }
    return res;
    }
};