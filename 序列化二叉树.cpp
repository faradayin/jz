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
        //活的现实一点
        //主动一点
        //深度思考。唯有深度思考创造价值。
/*
 1. 对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点
不为空时，在转化val所得的字符之后添加一个' ， '作为分割。对于空节点则以 '#' 代替。
 2. 对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树(特别注意：
在递归时，递归函数的参数一定要是char ** ，这样才能保证每次递归后指向字符串的指针会
随着递归的进行而移动！！！)
*/
class Solution {
public:
    char* Serialize(TreeNode *root) 
    {    
        //val → char 
        //to_string()
        if(!root)
            return nullptr;
        string str;
        Serialize(root, str);
        char *ret = new char[str.length()+1];
        //  
        int i;
        for(i=0; i<str.length(); i++)
        {
            ret[i] = str[i];

        }
        ret[i] = '\0';
        return ret;


    }
    void Serialize(TreeNode *root, string& str)
    {
        if(root == nullptr)
        {
            str +='#' ;
            return;
        }
        str += to_string(root->val);
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);

    }

    TreeNode* Deserialize(char *str)
    {
        if(str == nullptr)
            return nullptr;
        TreeNode* ret = Deserialize(&str);
        return ret;
    }
    TreeNode* Deserialize(char **str) 
    {
        //空节点
        if(**str == '#')
        {
            ++(*str);
            return nullptr;

        }
        //还原一个val节点
        int num = 0;
        while(**str != '\0' && **str != ',')
        {
            num = num*10 + ((**str)-'0');
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);

        //step to the next node
        if(**str == '\0')
            return root;
        else
            (*str)++;
        //pre-order
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};