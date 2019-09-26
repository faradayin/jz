/*
输入一个链表，输出该链表中倒数第k个结点。
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
//双指针，前面一个领先k步
    ListNode* FindKthToTail(ListNode* h, unsigned int k) {
    if(h == NULL || k <= 0) return NULL;//考虑输入负的k，返回NULL

    ListNode* j = h;
    ListNode* i = h;

    while(k != 0)
    {
        if(j->next == NULL && k != 1) return NULL;//链表不够长，返回NULL
        j = j->next;
        --k;
    }
    while(j != NULL)
    {
        j = j->next;
        i = i->next;
    }
    return i;
    }
};