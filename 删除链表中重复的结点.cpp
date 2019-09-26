/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
//你根本就不熟，链表的结构没有了然于胸
class Solution
{
  public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        ListNode *pre = new ListNode(-1);
        pre->next = pHead;
        ListNode *p = pre;
        ListNode *last = pre;

        while (p!=nullptr && p->next != nullptr)
        {
            if(p->val == p->next->val)
            {
                int val = p->val;
                while(p!=nullptr && p->val == val)
                {
                    p = p->next;
                }
                last->next = p;
            }
            else
            {
                last = p;
                p = p->next;
            }
            

        }
        return pre->next;

    }
};