/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) 
    {
        //先反转链表
        ListNode* nh = reverse_this_linkedlist(head);
        vector<int> res;
        while(nh)
        {
            res.push_back(nh->val);
            nh = nh->next;
        }
        return res;
        
    }

    ListNode* reverse_this_linkedlist(ListNode* h)
    {
        if(h == nullptr || h->next == nullptr) return h;
        ListNode* end = h->next;
        ListNode* nh = reverse_this_linkedlist(h->next);
        end->next = h;
        h->next = nullptr;
        return nh;
    }
    
    vector<int> res;
    vector<int> printListFromTailToHead_recursive(ListNode* head)
    {
        //递归，最简单的方法
        if(head != nullptr)
        {
            if(head->next != nullptr) printListFromTailToHead_recursive(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};