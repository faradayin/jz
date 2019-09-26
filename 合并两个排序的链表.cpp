/*
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。

*/
#include <vector>
#include <string>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* p1, ListNode* p2)//两个单调递增的链表
    {
        if(p1 == NULL && p2 == NULL) return NULL;
        ListNode* h = NULL;
        ListNode** c = &h;//c指向链表尾指针
        MyMerge(c, p1, p2);
        return h;
        
    }
    void MyMerge(ListNode** c, ListNode* p1, ListNode* p2)
    {
        if(p1 == NULL)
        {
            MergeP(c, p2);
            return;
        }
        if(p2 == NULL)
        {
            MergeP(c, p1);
            return;
        }
        if(p1->val <= p2->val)
        {
            *c = new ListNode(p1->val);
            c = &(*c)->next;
            MyMerge(c, p1->next, p2);

        }
        else
        {
            *c = new ListNode(p2->val);
            c = &(*c)->next;
            MyMerge(c, p1, p2->next);
        }
        
    }
    void MergeP(ListNode** c, ListNode* p)
    {
        if(p == NULL)
            return;
        *c = new ListNode(p->val);  

        MergeP(&(*c)->next, p->next);

    }
};