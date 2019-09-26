/*
*************
本题难点在，如果pNode节点没有右子节点，而且pNode是其parent的右子节点，
 ———— 这种情况下，需要向上遍历【相当于扩大子树的规模】，直到所在子树是某一个节点的左子树，注意，是左子树！此时返回该parent节点即可
 ************
*/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution
{
  public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        TreeLinkNode *pnext = nullptr;
        if(pNode == nullptr)
            return pnext;
        
        //has right child
        if (pNode->right != nullptr)
        {
            pnext = pNode->right;
            while (pnext->left != nullptr)
            {
                pnext = pnext->left;
            } //find left child of its right sub-tree
        }
        else // has no right child
        
        {
            while(pNode->next != nullptr)
            {
                TreeLinkNode *proot  = pNode->next;
                if(proot->left == pNode)
                    return proot;
                else
                    pNode = pNode->next;// traverse upwards
                
                
            }

        }
        return pnext;

    }
};