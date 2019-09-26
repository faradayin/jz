/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
/*
1 用一快一慢两个指针在环中相遇
2 用一个指针遍历环，得到环长度计数
3 用两个指针，其距离为环的长度，以同样的速度向前走，直到相遇，此时相遇点即为入口

*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {   

        //get the number of nodes in loop
        int lop = lenloop(pHead);
        if(lop == 0)
            return nullptr;
        //get to the entry
        ListNode* sw = pHead;
        ListNode* fs = pHead;
        for(int i=0;i<lop;i++)
        {
            fs = fs->next;

        }
        //now i == lop
        while(fs != sw)
        {
            fs = fs->next;
            sw = sw->next;
        }
        //meet at the entry
        return sw;
    }

    int lenloop(ListNode* pHead)
    {
        ListNode* sw = pHead;
        if(sw == nullptr)
            return 0;
        ListNode* fs = pHead->next;
        if(fs == nullptr)
            return 0;
        ListNode* meet = nullptr;
        while(sw && fs)
        {
            if(sw == fs)
                //meet
            {
                meet = sw;
                break;
            }

            fs = fs->next;
            if(fs)
            fs = fs->next;//2 steps of fs
            sw = sw->next;//1 step of sw
        }
        //no loop,no meet
        
        //count
        if(!meet)
            return 0;
        sw = meet;
        fs = meet->next;
        int count = 1;
        while(fs != sw)
        {
            fs = fs->next;
            ++count;
        }
        return count;
        
    }
};